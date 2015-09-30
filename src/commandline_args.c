#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{

    if (argc != 2) {
        fprintf(stderr, "usage: %s arg\n", argv[0]);
        exit(1);
    }
    printf("%s\n", argv[1]);
}
