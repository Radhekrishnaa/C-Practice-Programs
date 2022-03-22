#include<stdio.h>
struct student{
    char name[30];
    int roll_no;
    int marks;
};
int main(){
    struct student s;
    char ch;
    FILE *fp;
    fp=fopen("student1.txt","w");
    while(1){
        printf("Enter your name ,roll_no and marks :\n");
        scanf("%s%d%d",&s.name,&s.roll_no,&s.marks);
        fprintf(fp,"%s %d %d\n",s.name,s.roll_no,s.marks);
       printf("Do you want to write more enter Y or N \n");
       fflush(stdin);

       scanf("%c",&ch);
       if(ch=='n'){
           break;
       }
    }

    fclose(fp);
    return 0 ;
}