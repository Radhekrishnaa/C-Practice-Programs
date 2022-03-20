#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[30];
    int roll_no;
    int marks;
};
int main(){
    struct student s;
    FILE *fp;
    char ch;
    fp=fopen("binary.txt","r+");
     if(fp==NULL){
            printf("YOU can't access the file \n");
            exit(1);
        }
    while(1){
       ch=fread(&s,sizeof(s),1,fp);
       /*fread returns o if he can not return any thing from a file*/
        if(ch==0){
           break;
       }
       printf("%s %d %d \n",s.name,s.roll_no,s.marks);
         
    }
    fclose(fp);
    return 0 ;
}