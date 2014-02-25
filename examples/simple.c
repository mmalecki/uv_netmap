#include <stdio.h>

#include <net/netmap_user.h>
#include <uv.h>
#include <uv_netmap.h>

void on_netmap_open(struct netmap_ring ring, int status) {
  printf("got netmap ring, status: %d\n", status);
}

int main(int argc, char** argv) {
  uv_loop_t* loop = uv_default_loop();

  int r = uv_netmap_open(loop, on_netmap_open);
  printf("getting netmap ring, status: %d\n", r);

  return uv_run(loop, UV_RUN_DEFAULT);
}
