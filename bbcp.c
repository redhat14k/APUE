/*
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
    int fin,fout;
    char buf[BUF_SIZE];
    size_t len;

/*check if user supplies source file and destination file/directory*/
    if(argc!=3){
        printf("error: %s\n", strerror(errno));
    }

    if (strcmp(argv[1], argv[2]) == 0){
	printf("Error: %s\n", strerror(errno));
		exit(1);
/*opens source file in read-only*/
    fin=open(argv[1], O_RDONLY);
    if(fin==-1){
        exit(1);
    }

/*check if source file is accessible*/
    if (access(argv[1], R_OK) != 0) {
	printf("error: %s\n", strerror(errno));
    }

/*opens destination file in write-only*/   
    fout=open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | S_IWUSR | S_IRUSR);
    if(fout == -1){
        printf("error: %s\n", strerror(errno));
    }

    while((len = read(fin,buf,BUF_SIZE)) > 0){
        if(write(fout,buf,len)!=len){
            exit(1);
        }
        close(fin);
        close(fout);

        if(close(fin) == -1){
            exit(1);   
        }

        if(close(fout) == -1){
            exit(1);
        }

        exit(0);   
    }
}



