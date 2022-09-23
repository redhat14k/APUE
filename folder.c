* program to copy data from one file to another file*/

#include<studio.h>

#include<conio.h>

void main()

{

FILE *fp1,*fp2;

char ch;

clrscr();

fp1=fopen(“mslifelineway.c”, “r”);

fp2=fopen(“bakait.c”, “w”);

while(1)

{

ch=fgetc(fp1);

if(ch=EOF)

break;

else

putc(ch,fp2);

}

printf(“\nFile copied successfully!”);

fclose(fp1);

fclose(fp2);

getch();

}
