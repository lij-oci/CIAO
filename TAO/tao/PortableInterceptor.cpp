// $Id$:

#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1

#if !defined (__ACE_INLINE__)
#include "tao/PortableInterceptor.i"
#endif /* defined INLINE */

TAO_ClientRequestInterceptor_Adapter::
~TAO_ClientRequestInterceptor_Adapter (void)
{
}

// -------------------------------------------------------------------

TAO_ServerRequestInterceptor_Adapter::
~TAO_ServerRequestInterceptor_Adapter (void)
{
}

#endif /* TAO_HAS_INTERCEPTORS == 1 */
