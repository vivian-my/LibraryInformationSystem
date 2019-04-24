#include<stdio.h>
#include<stdlib.h>
#include"bookStruct.h"
#include"bookfile.h"
#include"userStruct.h"
//This function is to print all the books information to the interface
void list_book()
{
    book head,p;
    head=read();
    printf("***************************************The book overview****************************************\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Landing number     Title        Author         Type       Publish           Price      Amount\n");
    if(head==NULL)
    {
        printf("There is no book in the library.\n");
    }

    p=head;

    while(p!=NULL)
    {
        printf("%s  %18s%13s %12s%15s%16.2f%10d\n",p->number,p->title,p->author,p->type,p->publish,p->price,p->num);
        p=p->next;
    }
    printf("Input any key to return.\n");
    getch();
    Menu();
}
//This function is going to list all the users' information
void list_user()
{
    user a,b;
    a=read2();
    printf("*************Registered user information**************\n");
    printf("------------------------------------------------------\n");
    printf("Name             ID         The number of books borrowed   \n");
    if(a==NULL)
        printf("There is no registered user.\n");
    b=a;
    while(b!=NULL)
    {
        printf("%-6s %18s%10d\n",b->name,b->ID,b->book);
        b=b->next;
    }
    printf("Input any key to return.\n");
    getch();
    Menu();
}
