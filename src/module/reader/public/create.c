#include <module/reader/_private/_reader.h>

libnapc__Reader libnapc_Reader_create(const void *data, libnapc_size data_size) {
	libnapc__Reader reader;

	libnapc_Reader_init(&reader, data, data_size);

	return reader;
}
