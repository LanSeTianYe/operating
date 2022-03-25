#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void readFile(char *fileName, int bufferSize, int *fileLength, char **fileContentPtr)
{

    FILE *filePtr = fopen(fileName, "r");
    if (filePtr == NULL)
    {
        printf("open file fial");
        return;
    }

    char * fileContent;

    int readLength = 0;
    while (!feof(filePtr))
    {
        fileContent = realloc(fileContent, readLength + bufferSize + 1);
        int readCount = fread((char *)fileContent + readLength, bufferSize, 1, filePtr);
        readLength = strlen(fileContent);
        printf("filrPtr:%p, buffer size:%d, read count:%d, read length:%d, content:%s\n", filePtr, bufferSize, readCount, readLength, fileContent);
    }
    *fileLength = readLength;

    if (fileContent != NULL)
    {
        char *fileEndAddress = (char *)(fileContent + readLength);
        *fileEndAddress = '\0';
    }
    *fileContentPtr = fileContent;

    free(filePtr);

    return;
}

int main(int argc, char *argv[])
{
    char *fileName = ".gitignore";
    int bufferSize = 8;
    int *fileLength = (int *)malloc(sizeof(int));
    char *fileContent = (char *)malloc(sizeof(char));
    char **fileContentPtr= &fileContent; 
    readFile(fileName, bufferSize, fileLength, fileContentPtr);

    printf("file length: %d\n", *fileLength);
    printf("file content  -------------------------\n%s\nfile content  -------------------------\n", *fileContentPtr);
}