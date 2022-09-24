*
 * HW-1 - bbcp.c - bare-bones copy a file
 * Author: Pratish Bhansali
 * Email: pbhansal@stevens.edu
*/

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/*Buffer size for copying the file*/
#define BUF_SIZE 131072

/*Limit set for file*/
#define FILE_LIM 200

int main(int argc, char* argv[]){
    FILE *fp1, *fp2;
    char ch;
    int pos;
    char buf[BUF_SIZE];
    size_t len;

/*check if user supplies source file and destination file/directory*/
    if(!fp1 || !fp2 || argc!==3){
        printf("error: %s\n", strerror(2));
	exit(1);
    }

    if (strcmp(argv[1], argv[2]) == 0){
	printf("Error: %s\n", strerror(errno));
	exit(1);
    }
	    
/*opens source file in read-only*/
    fp1 = fopen(argv[1],"r");
    if(fp1==-1){
        exit(1);
    }

/*check if source file is accessible*/
    if (access(argv[1], R_OK) != 0) {
	printf("error: %s\n", strerror(2));
    }

/*opens destination file in write-only*/   
    fp2 = fopen(argv[2], "w"); 
    if(fp2 == -1){
        printf("error: %s\n", strerror(errno));
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

    if(close(fp1) == -1){
            exit(1);   
        }

    if(close(fp2) == -1){
            exit(1);
        }

        exit(0);   
}


