#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *args[]){
    if (argc != 2){
        fprintf(stderr, "usage: cpu <string>\n");
	exit(1);
    }

    char *str = args[1];
    while(1){
        printf("%s\n", str);
        Spin(1);
    }
    return 0;
}
