#ifndef UV_NETMAP_H
#define UV_NETMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <uv.h>

typedef void (*uv_netmap_open_cb)(struct netmap_ring, int status);

/*
 * Opens /dev/netmap and does proper `ioctl` on it.
 */
int uv_netmap_open(uv_loop_t* loop, uv_netmap_open_cb cb);

#ifdef __cplusplus
}
#endif

#endif
