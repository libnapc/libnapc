#include <module/dns/_private/_dns.h>

bool libnapc_DNS_parseRequest(
	libnapc__DNSRequest *out,
	const void *buffer, libnapc_size buffer_size
) {
	libnapc__DNSHeader header;

	if (!libnapc_DNS_parseHeader(&header, buffer, buffer_size)) {
		return false;
	}

	libnapc__Reader reader;
	libnapc_Reader_init(&reader, buffer, buffer_size);

	// skip DNS header we just read
	if (!libnapc_Reader_readU8Array(&reader, 12, NULL)) return false;

	if (header.question_count != 1) {
		PV_NAPC_DNS_WARNING(
			"Request contains other than 1 question (%d questions).", header.question_count
		);

		return false;
	}

	// question count capped at max 1
	libnapc__DNSQuery *q = out ? &out->query : NULL;

	if (!PV_libnapc_DNS_parseQuerySection(q, &reader)) {
		return false;
	}

	if (out) {
		memcpy(&out->header, &header, sizeof(header));
	}

	return true;
}
