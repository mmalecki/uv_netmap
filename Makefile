OBJS += src/uv_netmap.o

EXAMPLES += examples/simple

CFLAGS += -g -Wall -Ideps/libuv/include -Ideps/netmap/sys -Iinclude

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
	$(CC) $(CFLAGS) -o $@ $< -L. -luv_netmap -Ldeps/libuv/.libs -luv

.PHONY: all clean cleanall
