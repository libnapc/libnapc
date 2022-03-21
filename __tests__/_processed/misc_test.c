#include <napc.h>
#include <napc.h>
#include <napc-testing.h>

static struct {
	unsigned char *data;
	napc_size size;
	void *context;
} _calls[10];

static char _dummy_data[64] = "abcdef123456789abcdef123456789abcdef123456789abcdef1234567891234";
static int _dummy_data_index = 0;

static int _calls_index = 0;

static napc_ssize _readFunction(const void *data, napc_size data_size, void *context) {
	TEST_ASSERT(10 > _calls_index);

	_calls[_calls_index].data = (void *)data;
	_calls[_calls_index].size = data_size;
	_calls[_calls_index].context = context;

	for (napc_size i = 0; i < data_size; ++i) {
		TEST_ASSERT(64 > _dummy_data_index);
		unsigned char *ptr = (void *)data;

		ptr[i] = _dummy_data[_dummy_data_index];
		++_dummy_data_index;
	}

	++_calls_index;

	return data_size;
}

void PV_napc_misc__testCase12(void) {
    napc_unmute();
    napc_puts("[misc/test.c] should work properly ... ");
    napc_mute();
	char tmp;
	void *fn_context = &tmp;
	napc_u8 data[63];

	TEST_ASSERT(
		napc_misc_chunkedOperation(
			data, sizeof(data), 32, _readFunction, fn_context
		)
	);

	// size: 63
	//	chunk size: 32 -> 31 left
	//	chunk size: 16 -> 15 left
	//	chunk size: 8  -> 7 left
	//	chunk size: 4  -> 3 left
	//	chunk size: 2  -> 1 left
	//	chunk size: 1  -> 0 left
	TEST_ASSERT(_calls_index == 6);
	TEST_ASSERT(_calls[0].size == 32);
	TEST_ASSERT(_calls[0].data == (data + 0));
	TEST_ASSERT(_calls[0].context == fn_context);

	TEST_ASSERT(_calls[1].size == 16);
	TEST_ASSERT(_calls[1].data == (data + 32));
	TEST_ASSERT(_calls[1].context == fn_context);

	TEST_ASSERT(_calls[2].size == 8);
	TEST_ASSERT(_calls[2].data == (data + 48));
	TEST_ASSERT(_calls[2].context == fn_context);

	TEST_ASSERT(_calls[3].size == 4);
	TEST_ASSERT(_calls[3].data == (data + 56));
	TEST_ASSERT(_calls[3].context == fn_context);

	TEST_ASSERT(_calls[4].size == 2);
	TEST_ASSERT(_calls[4].data == (data + 60));
	TEST_ASSERT(_calls[4].context == fn_context);

	TEST_ASSERT(_calls[5].size == 1);
	TEST_ASSERT(_calls[5].data == (data + 62));
	TEST_ASSERT(_calls[5].context == fn_context);

	TEST_ASSERT(
		memcmp(data, _dummy_data, 63) == 0
	);
}
