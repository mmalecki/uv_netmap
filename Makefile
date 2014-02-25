OBJS += src/uv_netmap.o

EXAMPLES += examples/simple

CFLAGS += -g -Wall -Ideps/libuv/include -Ideps/netmap/sys -Iinclude

uname_S=$(shell uname -s)

ifeq (Darwin, $(uname_S))
  LDFLAGS += -framework CoreServices
endif

ifeq (Linux, $(uname_S))
  LDFLAGS += -lc -lrt -ldl -lm -lpthread
endif

ifeq (SunOS, $(uname_S))
  LDFLAGS += -lsendfile -lsocket -lkstat -lnsl -lm
endif

all: libuv_netmap.a

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

libuv_netmap.a: $(OBJS)
	ar rcs $@ $^

libuv:
	$(MAKE) -C deps/libuv/

clean:
	rm -f libuv_netmap.a $(OBJS) $(EXAMPLES)

examples: libuv $(EXAMPLES)

examples/%: examples/%.c libuv_netmap.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< ./libuv_netmap.a deps/libuv/.libs/libuv.a

.PHONY: all clean cleanall
