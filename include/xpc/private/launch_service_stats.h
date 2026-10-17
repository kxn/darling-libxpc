#ifndef XPC_PRIVATE_LAUNCH_SERVICE_STATS_H
#define XPC_PRIVATE_LAUNCH_SERVICE_STATS_H

#include <xpc/xpc.h>
#include <stdint.h>

__BEGIN_DECLS

#define XPC_LAUNCH_STATS_SUBSYSTEM 8
#define XPC_LAUNCH_STATS_COPY 0x386
#define XPC_LAUNCH_STATS_QUERY 0x387
#define XPC_LAUNCH_STATS_ENABLE 0x389
#define XPC_LAUNCH_STATS_DISABLE 0x38a

// Packed native wire layout. Later ABI versions extend the 37-byte prefix;
// unknown extension fields are not synthesized by the Darling collector.
struct __attribute__((packed)) launch_service_stats_record {
	uint32_t label_index;
	uint64_t start_time;
	uint64_t unique_id;
	int32_t pid;
	uint32_t wait_status;
	uint8_t reason_namespace;
	uint64_t reason_code;
	uint8_t extension[22];
};

struct launch_service_stats {
	xpc_object_t labels;
	void* records;
	uint32_t count;
	uint32_t dropped_count;
};

XPC_EXPORT int _xpc_control_routine(int routine, xpc_object_t request, xpc_object_t* reply);
XPC_EXPORT int launch_service_stats_enable(const char* monitor_id, uint32_t capacity);
XPC_EXPORT int launch_service_stats_disable(const char* monitor_id);
XPC_EXPORT bool launch_service_stats_is_enabled(const char* monitor_id);
XPC_EXPORT int _launch_service_stats_copy_impl(const char* monitor_id, uint32_t capacity,
	struct launch_service_stats* result, uint32_t version);

__END_DECLS
#endif
