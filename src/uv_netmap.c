#include <stdio.h>
#include <uv.h>
#include <net/netmap_user.h>

#include "uv_netmap.h"

void uv__netmap_after_open(uv_work_t* req, int status) {
  printf("uv__netmap_after_open\n");
}

void uv__netmap_open(uv_work_t* req) {
  printf("uv__netmap_open\n");
}

int uv_netmap_open(uv_loop_t* loop, uv_netmap_open_cb cb) {
  printf("uv_netmap_open\n");
  uv_work_t work_req;

  uv_queue_work(loop, &work_req, uv__netmap_open, uv__netmap_after_open);
  return 0;
}
