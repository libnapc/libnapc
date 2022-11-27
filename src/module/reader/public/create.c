#include <module/reader/_private/_reader.h>

napc__Reader libnapc_Reader_create(const void *data, libnapc_size data_size) {
	napc__Reader reader;

	libnapc_Reader_init(&reader, data, data_size);

	return reader;
}
