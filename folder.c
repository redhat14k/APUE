/*
 * C Program to Copy a File into Another File
 */
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
int main(int argc,char **argv)
{
    FILE *fp1, *fp2;
    char ch;
    int pos;
    fp1 = fopen(argv[1],"r"
    fp2 = fopen(argv[2], "w");  
    if (!fp1 || !fp2 || !argc == 3){
        printf("error: %s\n",strerror(2))
    }
    fseek(fp1, 0L, SEEK_END); // file pointer at end of file
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET); // file pointer set at start
    while (pos--)
    {
        ch = fgetc(fp1);  // copying file character by character
        fputc(ch, fp2);
    }    
    fclose(fp1);
    fclose(fp2);
}
