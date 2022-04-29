#include <napc.h>
#include <napc-testing.h>

TEST_CASE("should calculate broadcast address correctly") {
	char broadcast_addr[32];

	TEST_ASSERT(
		napc_eth_calculateBroadcastAddress(
			"10.1.2.5",
			"255.255.255.0",
			broadcast_addr, sizeof(broadcast_addr)
		)
	);

	TEST_ASSERT(
		napc_streqli(broadcast_addr,"10.1.2.255")
	);
}
