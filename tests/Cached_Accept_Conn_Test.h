// $Id$
//
// Contains classes for Cached_Accept_Conn_Test which are used in automatic
// template instantiation - IBM C++ requires these to be in their own header.

#ifndef __CACHED_ACCEPT_CONN_TEST_H
#define __CACHED_ACCEPT_CONN_TEST_H

#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"
#include "ace/Synch.h"

class Client_Svc_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
public:

  Client_Svc_Handler (ACE_Thread_Manager *t = 0);
  int open (void *v = 0);
  int close (u_long flags = 0);
};


class Server_Svc_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
public:

  Server_Svc_Handler (ACE_Thread_Manager *t = 0);
  int open (void *v = 0);
};

#endif /* __CACHED_ACCEPT_CONN_TEST_H */
