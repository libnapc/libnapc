#if !defined(LIBNAPC_MAGIC_h)
	#define LIBNAPC_MAGIC_h

	#include <libnapc-internal.h>

	#include <napc-panic/napc-panic.h>

	typedef uint32_t napc_init_magic;

	#define NAPC_MAGIC_MEMBER napc_init_magic _init_magic

	#define NAPC_MAGIC_DESTROYED LIBNAPC_U32_LITERAL(0xFFFFFFFF)

	#define NAPC_MAGIC_INIT(type, obj) (obj)->_init_magic = (NAPC_MAGIC_ ## type)
	#define NAPC_MAGIC_DESTROY(obj) (obj)->_init_magic = NAPC_MAGIC_DESTROYED

	// Used to silence -Waddress warnings
	#define PV_NAPC_MAGIC_GET_VALUE(obj) \
		((void *)(obj) != NULL ? (obj)->_init_magic : 0)

	#define NAPC_MAGIC_ASSERT(type, obj)                                      \
		do {                                                                  \
			const napc_init_magic actual   = PV_NAPC_MAGIC_GET_VALUE(obj);    \
			const napc_init_magic expected = (NAPC_MAGIC_ ## type);           \
			if (actual == NAPC_MAGIC_DESTROYED) {                             \
				LIBNAPC_PANIC("Attempt to use destroyed " # type);            \
			} else if (actual != expected) {                                  \
				LIBNAPC_PANIC("Detected uninitialized " # type);              \
			}                                                                 \
		} while (false)

	/*
	 * Is used for structs that are allocated on the stack and have an
	 * _init() function.
	 */
	#define NAPC_MAGIC_napc__HRTimer                      LIBNAPC_U32_LITERAL(0x56d3a4f1)
	#define NAPC_MAGIC_napc__Timer                        LIBNAPC_U32_LITERAL(0x2f1fa628)
	#define NAPC_MAGIC_napc__Pool                         LIBNAPC_U32_LITERAL(0xd3d0df2a)

	#define NAPC_MAGIC_napc__Buffer                       LIBNAPC_U32_LITERAL(0x7beccbe2)
	#define NAPC_MAGIC_napc__Reader                       LIBNAPC_U32_LITERAL(0xf0de7965)

	#define NAPC_MAGIC_napc__Writer                       LIBNAPC_U32_LITERAL(0x1b81b5d1)

	#define NAPC_MAGIC_napc__IPv4Participant              LIBNAPC_U32_LITERAL(0x97d59a3d)

	#define NAPC_MAGIC_napc__RingBuffer                   LIBNAPC_U32_LITERAL(0x67fa9d2d)
#endif
