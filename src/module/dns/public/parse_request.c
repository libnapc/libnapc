#include <module/dns/_private/_dns.h>

bool napc_DNS_parseRequest(
	napc__DNSRequest *out,
	const void *buffer, libnapc_size buffer_size
) {
	napc__DNSHeader header;

	if (!napc_DNS_parseHeader(&header, buffer, buffer_size)) {
		return false;
	}

	napc__Reader reader;
	napc_Reader_init(&reader, buffer, buffer_size);

	// skip DNS header we just read
	if (!napc_Reader_readU8Array(&reader, 12, NULL)) return false;

	if (header.question_count != 1) {
		PV_NAPC_DNS_WARNING(
			"Request contains other than 1 question (%d questions).", header.question_count
		);

		return false;
	}

	// question count capped at max 1
	napc__DNSQuery *q = out ? &out->query : NULL;

	if (!PV_napc_DNS_parseQuerySection(q, &reader)) {
		return false;
	}

	if (out) {
		memcpy(&out->header, &header, sizeof(header));
	}

	return true;
}
