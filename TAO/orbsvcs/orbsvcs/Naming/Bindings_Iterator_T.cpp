// $Id$

#ifndef TAO_BINDINGS_ITERATOR_T_CPP
#define TAO_BINDINGS_ITERATOR_T_CPP

#include "Bindings_Iterator_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

template <class ITERATOR, class TABLE_ENTRY>
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::TAO_Bindings_Iterator (ITERATOR *hash_iter,
                                                                     PortableServer::POA_ptr poa,
                                                                     ACE_SYNCH_RECURSIVE_MUTEX &lock)
  : destroyed_ (0),
    hash_iter_ (hash_iter),
    lock_ (lock),
    poa_ (PortableServer::POA::_duplicate (poa))

{
}

template <class ITERATOR, class TABLE_ENTRY>
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::~TAO_Bindings_Iterator (void)
{
  delete hash_iter_;
}

// Return the Default POA of this Servant
template <class ITERATOR, class TABLE_ENTRY> PortableServer::POA_ptr
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::_default_POA (CORBA::Environment &/*env*/)
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}

template <class ITERATOR, class TABLE_ENTRY> CORBA::Boolean
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::next_one (CosNaming::Binding_out b,
                                                        CORBA::Environment &ACE_TRY_ENV)
{
  CosNaming::Binding *binding;

  // Allocate a binding to be returned (even if there no more
  // bindings, we need to allocate an out parameter.)
  ACE_NEW_THROW_EX (binding,
                    CosNaming::Binding,
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  // Check to make sure this object didn't have <destroy> method
  // invoked on it.
  if (this->destroyed_)
    ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (), 0);

  b = binding;

  ACE_GUARD_THROW_EX (ACE_SYNCH_RECURSIVE_MUTEX,
                      ace_mon,
                      this->lock_,
                      CORBA::INTERNAL ());
  ACE_CHECK_RETURN (0);
  // If there are no more bindings.
  if (hash_iter_->done ())
    return 0;
  else
    {
      TABLE_ENTRY *hash_entry;
      hash_iter_->next (hash_entry);

      if (populate_binding (hash_entry, *binding) == 0)
        ACE_THROW_RETURN (CORBA::NO_MEMORY (), 0);

      hash_iter_->advance ();
      return 1;
    }
}

template <class ITERATOR, class TABLE_ENTRY> CORBA::Boolean
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::next_n (CORBA::ULong how_many,
                                                      CosNaming::BindingList_out bl,
                                                      CORBA::Environment &ACE_TRY_ENV)
{
  // We perform an allocation before obtaining the lock so that an out
  // parameter is allocated in case we fail to obtain the lock.
  ACE_NEW_THROW_EX (bl,
                    CosNaming::BindingList (0),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);
  // Obtain a lock.
  ACE_GUARD_THROW_EX (ACE_SYNCH_RECURSIVE_MUTEX,
                      ace_mon,
                      this->lock_,
                      CORBA::INTERNAL ());
  ACE_CHECK_RETURN (0);

  // Check to make sure this object didn't have <destroy> method
  // invoked on it.
  if (this->destroyed_)
    ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (), 0);

  // If there are no more bindings...
  if (hash_iter_->done ())
      return 0;
  else
    {
      // Initially assume that iterator has the requested number of
      // bindings.
      bl->length (how_many);

      TABLE_ENTRY *hash_entry;

      // Iterate and populate the BindingList.

      for (CORBA::ULong i = 0; i < how_many; i++)
        {
          hash_iter_->next (hash_entry);

          if (populate_binding (hash_entry, bl[i]) == 0)
            ACE_THROW_RETURN (CORBA::NO_MEMORY (), 0);

          if (hash_iter_->advance () == 0)
            {
              // If no more bindings left, reset length to the actual
              // number of bindings populated and get out of the loop.
              bl->length (i + 1);
              break;
            }
        }
      return 1;
    }
}

template <class ITERATOR, class TABLE_ENTRY> void
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::destroy (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_THROW_EX (ACE_SYNCH_RECURSIVE_MUTEX,
                      ace_mon,
                      this->lock_,
                      CORBA::INTERNAL ());
  ACE_CHECK;

  // Check to make sure this object didn't have <destroy> method
  // invoked on it.
  if (this->destroyed_)
    ACE_THROW (CORBA::OBJECT_NOT_EXIST ());

  PortableServer::POA_var poa =
    this->_default_POA (ACE_TRY_ENV);
  ACE_CHECK;

  PortableServer::ObjectId_var id =
    poa->servant_to_id (this,
                        ACE_TRY_ENV);
  ACE_CHECK;

  poa->deactivate_object (id.in (),
                          ACE_TRY_ENV);
  ACE_CHECK;
}

template <class ITERATOR, class TABLE_ENTRY> int
TAO_Bindings_Iterator<ITERATOR, TABLE_ENTRY>::populate_binding (TABLE_ENTRY *hash_entry,
                                                                CosNaming::Binding &b)
{
  b.binding_type = hash_entry->int_id_.type_;
  b.binding_name.length (1);

  // Here we perform a check before assignment to make sure
  // CORBA::string_dup is not called on 0 pointer, since the spec does
  // not say what should happen in that case.
  if (hash_entry->ext_id_.id () != 0)
    {
      b.binding_name[0].id =
        hash_entry->ext_id_.id ();
      if (b.binding_name[0].id.in () == 0)
        return 0;
    }
  if (hash_entry->ext_id_.kind () != 0)
    {
      b.binding_name[0].kind =
        hash_entry->ext_id_.kind ();
      if (b.binding_name[0].kind.in () == 0)
        return 0;
    }
  return 1;
}

#endif /* TAO_BINDINGS_ITERATOR_T_CPP */
