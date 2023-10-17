/*
File Copy Program

WTD: Write a program that copies one file to another using low-level file operations. Use open(), read(), and write() system calls to perform the file copy.

(e.g.: I/P: Source and destination file paths; O/P: Copy status)

author : yosaak
*/

#include <stdlib.h>
#include <stdio.h>

#define BLOCK_LEN 1

void main(int argc, char** argv)
{
    char block;
    int readReturn = 0; 
    int writeReturn = 0;
    FILE *input;
    FILE *output;

    if(argc == 1)
    {
        printf("Error:No input and output file\n");
        return;
    }
    if(argc == 2)
    {
        printf("Error:No output file\n");
        return;
    }
    if(argc > 3)
    {
        printf("Error: More input arguments passed.\nConsidering only %s %s\n", argv[1],argv[2]);
    }

    input = fopen(argv[1], "r");
    if(NULL == input)
    {
        printf("Error:Input file not found\n");
        return;
    }

    output = fopen(argv[2], "w");
    if(NULL == output)
    {
        printf("Error:Output file cannot be created or not found\n");
        return;
    }

    do
    {
        readReturn = fread(&block, sizeof(block), BLOCK_LEN, input);
        if(readReturn > 0)
        {
            writeReturn = fwrite(&block, sizeof(block), BLOCK_LEN, output);
            if(BLOCK_LEN != writeReturn)
            {
                printf("Error: File write failure\n");
                return;
            }
        }
    }while(BLOCK_LEN == readReturn);
    printf("File copied successfully\n");
    fclose(input);
    fclose(output);
}
