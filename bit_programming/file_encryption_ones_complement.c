#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fa,*fb;
    char ch;
    fa=fopen("file1.txt","r");
    //file1.txt contains secret message that is about to be encrypted
    fb=fopen("file2.txt","w");
    //file2.txt holds the encrypted file transfered from the file1
    if(fa==NULL ||fb==NULL){
        printf("\n Error in file opening");
        exit(1);
    }
    while(ch=getc(fa)!=EOF){
        //ch is character that takes the character from fa file type pointer that points to file1 and EOF(end of line)
        putc(~ch,fb);
       // (~ch) i.e one's compelement and encrypts the file and makes it hard to read for the unauthorized user

    }
    fclose(fa);
    fclose(fb);
    return 0 ;
}