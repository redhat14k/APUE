/*
 * HW-1 - bbcp.c - bare-bones copy a file
 * Author: Pratish Bhansali
 * Email: pbhansal@stevens.edu
*/

#include<errno.h>
#include<fcntl.h>
#include<libgen.h>
#include<stdio.h>
#include<string.sh>
#include<sys/stat.h>
#include <unistd.h>

/*Buffer size for copying the file*/
#define BUF_SIZE 131072

/*Limit set for file*/
#define FILE_LIM 200

int main{int argc, char* argv[]}
{
    FILE *f1,*f2;
    char buf[BUF_SIZE];
    size_t len;

/*check if user supplies source file and destination file/directory*/
    if(argc!=3){
        fprintf(stderr,"error")
        exit(1);
    }

/*opens source file in read-only*/
    f1=open(argv[1], O_RDONLY);
    if(f1==-1){
        exit(1);
    }

/*check if source file is accessible*/
    if (access(argv[1], R_OK) != 0) {
		fprintf(stderr, "error");
        exit(1);
    }

/*opens destination file in write-only*/   
    f2=open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | S_IWUSR | S_IRUSR);
    if(f2 == -1){
        fprintf(sterrr, "error");
        exit(1);
    }


    while((len = read(f1,buf,BUF_SIZE)) > 0){
        if(write(f2,buf,len)!=len){
            exit(1);
        }
        close(f1);
        close(f2);

        if(close(f1)) == -1){
            exit(1);   
        }

        if(close(f2)) == -1){
            exit(1);
        }

        exit(0)    
    }
}

