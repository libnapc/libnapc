#include <napc-rand-source/_private/_napc-rand-source.h>

static napc_u8 _random_byte = 0; // @static
static int _random_byte_pos = 0; // @static

bool napc_getRandomByte(napc_u8 *out) {
	// iterate through the various random bit sources
	const int *random_bit_sources = napc_getRandomBitSources();
	napc_size i = 0;

	while (true) {
		int random_bit_source = random_bit_sources[i];

		// reached end of array (of sources)
		if (random_bit_source == -1) break;

		// check if we need to get another bit
		if (_random_byte_pos == 8) break;

		// try to get a random bit
		bool random_bit;

		if (napc_getRandomBit(&random_bit, random_bit_source)) {
			// save random_bit in the byte
			_random_byte |= (random_bit << _random_byte_pos);

			++_random_byte_pos;
		}

		++i;
	}

	// did we collect an entire byte?
	if (_random_byte_pos == 8) {
		*out = _random_byte;

		_random_byte = 0;
		_random_byte_pos = 0;

		return true;
	}

	return false;
}
