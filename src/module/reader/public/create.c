#include <module/reader/_private/_reader.h>

napc__Reader napc_Reader_create(const void *data, libnapc_size data_size) {
	napc__Reader reader;

	napc_Reader_init(&reader, data, data_size);

	return reader;
}
