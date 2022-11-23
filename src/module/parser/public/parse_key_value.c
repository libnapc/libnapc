#include <module/parser/_private/_parser.h>

bool napc_parser_parseKeyValue(
	const char *string,
	char *key, napc_size key_len,
	char *value, napc_size value_len
) {
	napc_size length = libnapc_strlen(string);

	if (!length) return false;

	// Flag (whether we are reading the key string or value string)
	bool readingKey = true;
	// Write position for key,value
	napc_size pos = 0;

	// Initialie key/value with zeros (safety precaution)
	if (key) napc_mzero(key, key_len);
	if (value) napc_mzero(value, value_len);

	for (napc_size i = 0; i < length; ++i) {
		char ch = string[i];

		// Check position index
		bool shouldWrite = false;

		// Position check for key
		if (readingKey) {
			shouldWrite = (key && key_len > pos);
		}
		// Position check for value
		else {
			shouldWrite = (value && value_len > pos);
		}

		// Reading key first
		if (readingKey) {
			// End of key
			if (ch == ',') {
				// Terminate key
				if (shouldWrite) key[pos] = 0;
				readingKey = false;
				// reset pos for value
				pos = 0;
			} else {
				// Only write to key if it is in the bounds
				if (shouldWrite) key[pos] = ch;
				++pos;
			}
		} else {
			// Only write to value if it is in the bounds
			if (shouldWrite) value[pos] = ch;
			++pos;
		}
	}

	// Handle strings without comma-separator
	// After the loop we shouldn't be in the reading key phase anymore
	if (readingKey) return false;

	// Make sure key and value are *always* terminated
	if (key) key[key_len - 1] = 0;
	if (value) value[value_len - 1] = 0;

	return true;
}
