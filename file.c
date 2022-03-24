#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *fileName = "asda";
    int bufferSize = 8;

    FILE *filePtr = fopen(".gitignore", "r");
    if (filePtr == NULL)
    {
        printf("open file fial");
        exit(0);
    }

    char *fileContent = (char *)malloc(bufferSize);

    int readLength = 0;
    while (!feof(filePtr))
    {
        int readCount = fread((char *)(fileContent + readLength), bufferSize, 1, filePtr);
        printf("filrPtr:%p, buffer size:%d, read count:%d, content:%s\n", filePtr, bufferSize, readCount, fileContent);

        readLength = strlen(fileContent);
        if (!feof(filePtr))
        {
            fileContent = realloc(fileContent, readLength + bufferSize);
        }
    }

    printf("file length: %d\n", readLength);
    printf("file data:\n%s\n", fileContent);

    free(filePtr);

    return 0;
}