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

    char *fileContent = (char *)malloc(bufferSize + 1);

    while (!feof(filePtr))
    {
        int readLength = fread((char *)(fileContent + (strlen(fileContent))), bufferSize, 1, filePtr);
        printf("buffer size:%d, read length:%d, content:%s\n", bufferSize, readLength, fileContent);
        char *temp = fileContent;
        if (feof(filePtr))
        {
            break;
        }

        fileContent = (char *)malloc(strlen(temp) + bufferSize + 1);
        strcpy(fileContent, temp);
    }

    printf("file data:\n%s\n", fileContent);
    return 0;
}