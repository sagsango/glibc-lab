// main.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

char * elf;
char * sym;

static int do_test(void) {
    void *handle;
    int (*test) (int);
    int res;

    handle = dlopen(elf, RTLD_LAZY);
    if (handle == NULL) {
        printf("%s\n", dlerror());
        exit(1);
    }

    test = dlsym(handle, sym);
    if (test == NULL) {
        printf("%s\n", dlerror());
        exit(1);
    }

    res = test(2);
    if (res != 4) {
        printf("Got %i, expected 4\n", res);
        exit(1);
    }

    dlclose(handle);
    return 0;
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
	printf ("%s <elf-name> <symbol-name>\n", argv[1]);
	return 0;
    }
    elf = argv[1];
    sym = argv[2];
    
    return do_test();
}

