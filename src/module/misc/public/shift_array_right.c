#include <module/misc/_private/_misc.h>

void libnapc_misc_shiftArrayRight(void *array, libnapc_size n_elements, libnapc_size element_size) {
	// TODO: check usage of libnapc_ssize here.
	for (libnapc_ssize i = n_elements - 1; i >= 0 ; --i) {
		// cannot move last element, it gets discarded
		if ((libnapc_size)i == (n_elements - 1)) continue;

		// get pointer to the current element (i)
		unsigned char *current_element = ((unsigned char *)array) + (element_size * i);
		// get pointer to the next element
		unsigned char *next_element = ((unsigned char *)array) + (element_size * (i + 1));

		memcpy(next_element, current_element, element_size);
	}
}
