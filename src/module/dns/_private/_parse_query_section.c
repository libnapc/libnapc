#include <module/dns/_private/_dns.h>

bool PV_napc_DNS_parseQuerySection(
	napc__DNSQuery *out,
	napc__Reader *reader
) {
	NAPC_MAGIC_ASSERT(napc__Reader, reader);

	// Read question name (QNAME)
	int name_length = PV_napc_DNS_dn_expand(
		// start of buffer
		reader->data,
		// end of buffer
		napc_Reader_getEndAddress(reader),
		// pointer to ''compressed'' domain name
		napc_Reader_getCurrentAddress(reader),
		PV_napc_DNS_tmp_name,
		sizeof(PV_napc_DNS_tmp_name)
	);

	if (0 >= name_length) {
		PV_NAPC_DNS_ERROR("Invalid name_length %d.", name_length);

		return false;
	}

	// Advance reader by name_length bytes
	if (!napc_Reader_readU8Array(reader, name_length, NULL)) {
		return false;
	}

	napc_u16 qtype = 0;
	napc_u16 qclass = 0;

	// Read QType
	if (!napc_Reader_readU16BE(reader, &qtype)) {
		return false;
	}
	// Read QClass
	if (!napc_Reader_readU16BE(reader, &qclass)) {
		return false;
	}

	if (qclass != 1) {
		PV_NAPC_DNS_WARNING("Invalid QClass %d. (expected 1)", qclass);

		return false;
	}

	if (out) {
		out->qtype = qtype;
		napc_strncpy(out->name, PV_napc_DNS_tmp_name, sizeof(out->name));
	}

	return true;
}
