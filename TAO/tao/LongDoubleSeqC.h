// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_LONGDOUBLESEQC_H_
#define _TAO_IDL_ORIG_LONGDOUBLESEQC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_LONGDOUBLESEQ_CH_)
#define _CORBA_LONGDOUBLESEQ_CH_
  
  class LongDoubleSeq;
  
  typedef
    TAO_FixedSeq_Var_T<
        LongDoubleSeq,
        CORBA::LongDouble
      >
    LongDoubleSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        LongDoubleSeq,
        LongDoubleSeq_var,
        CORBA::LongDouble
      >
    LongDoubleSeq_out;
  
  class TAO_Export LongDoubleSeq
    : public
        TAO_Unbounded_Sequence<
            CORBA::LongDouble
          >
  {
  public:
    LongDoubleSeq (void);
    LongDoubleSeq (CORBA::ULong max);
    LongDoubleSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::LongDouble* buffer, 
        CORBA::Boolean release = 0
      );
    LongDoubleSeq (const LongDoubleSeq &);
    ~LongDoubleSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef LongDoubleSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_LongDoubleSeq;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::LongDoubleSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::LongDoubleSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::LongDoubleSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::LongDoubleSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_LongDoubleSeq_H_
#define _TAO_CDR_OP_CORBA_LongDoubleSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::LongDoubleSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::LongDoubleSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_LongDoubleSeq_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:947

#if defined (__ACE_INLINE__)
#include "LongDoubleSeqC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


