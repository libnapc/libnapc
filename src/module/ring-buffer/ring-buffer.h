/*!
 * @name RingBuffer:intro
 * @brief Circular byte buffer
 */
#if !defined(NAPC_MODULE_RINGBUFFER_h)
	#define NAPC_MODULE_RINGBUFFER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>
	#include <napc-core/napc-core.h> // napc__AccessFailureMode

	/*!
	 * @name napc__RingBuffer
	 * @module RingBuffer
	 * @brief Representation of a RingBuffer.
	 * @version 2.0.0
	 * @opaque
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	typedef struct napc__RingBuffer {
		NAPC_MAGIC_MEMBER;

		napc__AccessFailureMode _fail_mode;

		void *buffer;
		napc_size buffer_size;

		napc_size read_position;
		napc_size write_position;

		bool buffer_full;
	} napc__RingBuffer;
#endif
