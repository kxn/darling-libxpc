#ifndef XPC_PRIVATE_SERVICE_H
#define XPC_PRIVATE_SERVICE_H
#include <xpc/xpc.h>
#include <dispatch/dispatch.h>
#include <stdint.h>

__BEGIN_DECLS
#define XPC_SERVICE_SUBSYSTEM 2
#define XPC_SERVICE_KICKSTART 702
#define XPC_SERVICE_ATTACH 703
#define XPC_SERVICE_REGISTER_HANDLER 704
#define XPC_SERVICE_CANCEL 706

XPC_EXPORT int _xpc_service_routine(int routine, xpc_object_t request, xpc_object_t* reply);
XPC_EXPORT xpc_object_t xpc_service_create(int kind, const char* name, uint64_t handle, dispatch_queue_t queue);
XPC_EXPORT xpc_object_t xpc_service_create_from_specifier(const char* specifier, dispatch_queue_t queue);
XPC_EXPORT const char* xpc_service_get_rendezvous_token(xpc_object_t service);
XPC_EXPORT int xpc_service_kickstart(xpc_object_t service, bool suspended, bool kill);
XPC_EXPORT int xpc_service_kickstart_with_flags(xpc_object_t service, uint64_t flags);
__END_DECLS
#endif
