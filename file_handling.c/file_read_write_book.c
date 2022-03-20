#include<stdio.h>
struct book{
    char book_name[50];
    int pages;
    char author[30];
}s;
int main(){
    FILE *fp;
    char ch;
    fp=fopen("book.txt","w");
    while(1){
        printf("Enter the book name,pages in it, the name of author :\n");
        scanf("%s %d %s",&s.book_name,&s.pages,&s.author);
        fprintf(fp,"%s %d %s\n ",s.book_name,s.pages,s.author);
        printf("Do you want to write again press Y or N\n");
        fflush(stdin);
        scanf("%c",&ch);

        if(ch=='n'){
            break;
        }
    }
      fclose(fp);
      fp=fopen("book.txt","r");
    while(1){
        fscanf(fp,"%s %d %s",&s.book_name,&s.pages,&s.author);
        printf("%s %d %s\n",s.book_name,s.pages,s.author);
        if(fscanf(fp,"%s %d %s",&s.book_name,&s.pages,&s.author)==EOF)
        break;
    }
    fclose(fp);
    return 0 ;
}