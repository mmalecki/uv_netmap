#include <uv.h>
#include <net/netmap_user.h>

#include "uv_netmap.h"

void uv__netmap_after_open(uv_work_t* req, int status) {
}

void uv__netmap_open(uv_work_t* req) {

}

int uv_netmap_open(uv_loop_t* loop, uv_netmap_open_cb cb) {
  uv_work_t work_req;

  work_req.data = (void*) cb;
  uv_queue_work(loop, &work_req, uv__netmap_open, uv__netmap_after_open);
  return 0;
}
