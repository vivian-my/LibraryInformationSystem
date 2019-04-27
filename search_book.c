#include<stdio.h>
#include<string.h>
#include"search_book.h"
#include"bookStruct.h"
/*This function helps the user to search a book
by title,author or landing number
*/
void search_book()
{
    do
    {
        int t;
        printf("********Book Search********\n");
        printf("       1. Title search    \n");
        printf("       2. Author search   \n");
        printf("       3. Landing number search\n");
        printf("       4. Return to the menu\n");
        scanf("%d",&t);
        switch(t)
        {
            case 1:title_search();
            break;
            case 2:author_search();
            break;
            case 3:number_search();
            break;
            case 4:Menu();
            break;
            default:break;
        }
    }while(1);

}


void author_search()
{
    book head,p;
    head=read();
    char author[30];
    printf("Input the author you want to search:\n");
    scanf("%s",author);getchar();
    p=head;
    printf("***************************************The book information****************************************\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Landing number     Title        Author          Type         Publish        Price       Amount\n");
    while(p!=NULL)
    {
        if(p!=NULL&&strcmp(p->author,author)==0)
        {
           printf("%s%19s%14s %14s%16s%13.2f%10d\n",p->number,p->title,p->author,p->type,p->publish,p->price,p->num);

        }
    p=p->next;

    }
    printf("Return by any key.");
    getch();
    search_book();
}
void title_search()
{
    book head,p;
    head=read();
    char title[30];
    printf("Input the title you want to search:\n");
    scanf("%s",title);getchar();
    p=head;
    printf("***************************************The book information****************************************\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Landing number     Title        Author          Type         Publish        Price       Amount\n");
    while(p!=NULL)
    {
        if(p!=NULL&&strcmp(p->title,title)==0)
        {
           printf("%s%19s%14s %14s%16s%13.2f%10d\n",p->number,p->title,p->author,p->type,p->publish,p->price,p->num);

        }
    p=p->next;

    }
    printf("Return by any key.\n");
    getch();
    search_book();
}

void number_search()
{
    book head,p;
    head=read();
    char number[10];
    printf("Input the landing number you want to search:\n");
    scanf("%s",number);getchar();
    p=head;
    printf("***************************************The book information****************************************\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Landing number     Title        Author          Type         Publish        Price       Amount\n");
    while(p!=NULL)
    {
        if(p!=NULL&&strcmp(p->number,number)==0)
        {
           printf(" %s%19s%14s %14s%16s%13.2f%10d\n",p->number,p->title,p->author,p->type,p->publish,p->price,p->num);

        }
    p=p->next;

    }
    printf("Return by any key.\n");
    getch();
    search_book();
}











