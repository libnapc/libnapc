#include <napc.h>
#include <napc-testing.h>

struct napc_pool_test_struct {
	char a;
	short b;
	int c;
};

struct napc_pool_test_struct my_array[5];

static unsigned char *addr_element0 = (unsigned char *)(&my_array[0]);
static unsigned char *addr_element1 = (unsigned char *)(&my_array[1]);
static unsigned char *addr_element2 = (unsigned char *)(&my_array[2]);
static unsigned char *addr_element3 = (unsigned char *)(&my_array[3]);
static unsigned char *addr_element4 = (unsigned char *)(&my_array[4]);

TEST_CASE("should work correctly") {
	napc__Pool pool;

	napc_Pool_init(&pool, NULL, my_array, 5, sizeof(struct napc_pool_test_struct));

	NAPC_ASSERT(napc_Pool_claimElement(&pool) == 0);
	NAPC_ASSERT(napc_Pool_claimElement(&pool) == 1);
	NAPC_ASSERT(napc_Pool_claimElement(&pool) == 2);
	NAPC_ASSERT(napc_Pool_claimElement(&pool) == 3);
	NAPC_ASSERT(napc_Pool_claimElement(&pool) == 4);

	NAPC_ASSERT(napc_Pool_getAddress(&pool, 0) == addr_element0);
	NAPC_ASSERT(napc_Pool_getAddress(&pool, 1) == addr_element1);
	NAPC_ASSERT(napc_Pool_getAddress(&pool, 2) == addr_element2);
	NAPC_ASSERT(napc_Pool_getAddress(&pool, 3) == addr_element3);
	NAPC_ASSERT(napc_Pool_getAddress(&pool, 4) == addr_element4);

	// element 3 should be available after this call
	napc_Pool_releaseElement(&pool, 3);

	NAPC_ASSERT(napc_Pool_claimElement(&pool) == 3);

	unsigned char *tmp = napc_Pool_getAddress(&pool, 3);

	NAPC_ASSERT(tmp == addr_element3);
}
