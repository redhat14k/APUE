#include<stdio.h>
#include<conio.h>

int main(int argc, char* argv[])
{
FILE *fp1,*fp2;
char ch;
clrscr();
fp1=fopen(argv[1], “r”);
fp2=fopen(argv[2], “w”);
while(1)
{
ch=fgetc(fp1);
if(ch=EOF){
break;
}
else
putc(ch,fp2);
}
printf(“\nFile copied successfully!”);
fclose(fp1);
fclose(fp2);
getch();
}
