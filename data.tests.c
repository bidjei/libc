#include "data/dyn_memory.spec.c"
#include <string.h>
#include <stdio.h>

void test_data()
{
	test_dyn_memory();
}

int main(int argc, char *argv[argc]) {
	switch (argc) {
		case 1:
			test_data();
			printf("[PASSED] all from data (spec)\n");
			break;
		case 2:
			if (!strcmp(argv[1], "dyn_memory")) { test_dyn_memory(); }
			else if (!strcmp(argv[1], "all"))   { test_data(); }
			else {
				fprintf(stderr, "Unknown spec '%s', pick from: dyn_memory, all.\n", argv[1]);
				return -1;
			}

			printf("[PASSED]: %s from data (spec)\n", argv[1]);
			break;
		default:
			fprintf(stderr, "Usage: test-data [dyn_memory|all]\n");
			return -1;
	}

	return 0;
}