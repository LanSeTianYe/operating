#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[]){

    if (argc != 2){
        fprintf(stderr,"usage: mem <value>\n");
	exit(1);
    }

    int *intP;
    intP = malloc(sizeof(int));
    assert(intP != NULL);

    printf("(%d) memory address of p: %p\n", getpid(), intP);
    printf("(%d) memory address of &p:%p\n", getpid(), &intP);

    *intP = atoi(argv[1]);
    while(1){
        Spin(1);
	*intP = *intP + 1;
	printf("(%d) p:%d\n", getpid(), *intP);
    }

    return 0;
}
