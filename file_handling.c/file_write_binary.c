#include<stdio.h>
struct student{
    char name[30];
    int roll_no;
    int marks;
}s1;
int main(){
    FILE *fp;
    char ch;
    fp=fopen("binary.txt","w+");
    while(1){
        printf("Enter your name,roll_no,and marks :\n");
        scanf("%s%d%d",&s1.name,&s1.roll_no,&s1.marks);
        fwrite(&s1,sizeof(s1),1,fp);
        printf("Do you want to write more if yes press y or n\n");
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='n'){
            break;
        }
    }
    fclose(fp);
    return 0 ;
}