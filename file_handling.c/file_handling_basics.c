#include<stdio.h>

int main(){
    FILE *fp;
    char ch;
    fp=fopen("student.dat","w");
    printf("Enter Character Until you want and If you want to Quit press q ");
    while(1){
        scanf("%c",&ch);
        fputc(ch,fp);
        if(ch=='q')
        break;
    }
    fclose(fp);
    return 0 ;
}

   