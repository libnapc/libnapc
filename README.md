![logo of libnapc](https://static.nap-software.com/github/libnapc/logo.png?)

[![Build and Test](https://github.com/libnapc/libnapc/actions/workflows/main.yaml/badge.svg)](https://github.com/libnapc/libnapc/actions/workflows/main.yaml)

# libnapc

Thank you very much for checking out the documentation of [libnapc](https://libnapc.nap-software.com/)! 🎉

This library came into existence to support any projects written in C by nap.software.

Its split up into three parts:

- Core library (basic functionality, basic HAL)
- Hardware independent modules:
  - DNS
  - Cryptographic functions (SHA256-HMAC and AES-256)
  - Buffer management (Writer, Reader)
  - Random byte generation
  - String parsing
- Hardware dependent modules:
  - Networking (UDP)
  - FileSystem

It provides HAL (Hardware Abstraction Layer) so that applications written in it can be run both on Arduino and Linux.

> ⚠️ This library is developed on a per-need basis. It is not a complete library (yet?).

Every napc application using libnapc defines at least these two functions:

`napc_app_setup()`
`napc_app_loop()`

## Purpose of napc_app_setup
Inspired by Arduino's `setup()` function libnapc uses the same methodology.

You can use `napc_app_setup()` to perform initialisation that only needs to be done once in the program's lifecycle.

`napc_app_setup()` also provides the current platform as a string:

`"arduino"` for Arduino.
`"linux"` for Linux.

## The napc_app_loop function
The `napc_app_loop` function gets called indefinitely until it returns false indicating the program should exit.

## The most basic program possible

```c
#include <napc.h>

void napc_app_setup(const char *platform) {
	// do one time initialization here
	// like setting network adapter settings (napc_eth_)
}

bool napc_app_loop(napc_time uptime) {
	/* program logic */

	return true;
}
```
