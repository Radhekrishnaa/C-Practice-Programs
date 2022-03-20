#include<stdio.h>
struct student{
    char name[30];
    int roll_no;
    int marks;
};
int main(){
    struct student s;
    FILE *fp;
    char ch;
    fp=fopen("student1.txt","r");
    if(fp==NULL){
        printf("This file can't be opened\n");
    }
    while(1){
        fscanf(fp,"%s %d %d",&s.name,&s.roll_no,&s.marks);
        printf("%s %d %d\n",s.name,s.roll_no,s.marks);
        if(fscanf(fp,"%s %d %d",&s.name,&s.roll_no,&s.marks)==EOF)
        break;
    }
    fclose(fp);
    return 0 ;
}