![logo of libnapc](https://static.nap-software.com/github/libnapc/logo.png?)

[![Build and Test](https://github.com/libnapc/libnapc/actions/workflows/main.yaml/badge.svg)](https://github.com/libnapc/libnapc/actions/workflows/main.yaml)

# libnapc

Thank you very much for checking out the documentation of [libnapc](https://libnapc.nap-software.com/)! 🎉

This library came into existence to support any projects written in C by nap.software.

At the moment, the following functions are provided:

- Core library (basic functionality, basic HAL)
- DNS
- Cryptographic functions (SHA256-HMAC and AES-256)
- Buffer management (Writer, Reader)
- String parsing

> **Warning**
> This library is developed on a per-need basis. It is not a complete library (yet?).

To start using libnapc, call `libnapc_init()` before using any of the library functions:

```c
#include <libnapc.h>

int main(void) {
	libnapc_init();

	libnapc_printf("Hello, World!\n");

	return 0;
}
```

Or on Arduino:

```c
#include <libnapc.h>

void setup() {
	libnapc_init();

	libnapc_printf("Hello, World!\n");
}

void loop() {

}
```
