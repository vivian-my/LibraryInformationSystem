#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "bookChange.h"
#include "bookStruct.h"
#include "bookfile.h"
#include "menu.h"
void input_book()   //Input the new book's information to the system
{
    do
    {
    int r;
    char i,c,t;
    book p,p1;
    p=(book)malloc(N);
    p1=read();
    char num[10];
    printf("Please enter the book's landing number\n");
    scanf("%s",num);getchar();
    int flag=0;
    while(p1!=NULL)
    {
        if(strcmp(p1->number,num)==0)
        {
            printf("The landing number has already existed. Please enter again:\n");
            printf("Please enter the book's landing number\n");
            scanf("%s",p->number);getchar();
            flag=1;
            break;
        }
        p1=p1->next;
    }
    if(flag==0)
        strcpy(p->number,num);//p->number,num;
    printf("Please enter the book's title\n");
    gets(p->title);
    printf("Please enter the book's author\n");
    gets(p->author);
    printf("Please enter the book's type\n");
    gets(p->type);
    printf("Please enter the book's publish\n");
    gets(p->publish);
    printf("Please enter the book's price\n");
    scanf("%f",&p->price);getchar();
    printf("Please enter the book's amount\n");
    scanf("%d",&p->num);getchar();
    save_book(p);
    printf("Save book successfully!\n");
    printf("Do you want to continue?\n");
    printf("1.YES        2. NO\n");
    scanf("%d",&r);
    if(r==2)
    {
        Menu();
        break;
    }
    }while(1);

}
void del_book()
{
 do
{
    FILE *fp;
    book head,p,pre = NULL;
    char num[10];
    char t, ch, c;
    int x;
    int j=0;
    head=read();
    printf("Enter the landing number of the book that you want to delete:\n");
    scanf("%s",num);getchar();
    p=head;
    while(p!=NULL)
    {
        p->x=0;
        p=p->next;
    }
    p=head;
    printf("***************************************The book information****************************************\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("  Landing number     Title        Author          Type         Publish        Price       Amount\n");
    while(p!=NULL)
    {
        if(p!=NULL&&strcmp(p->number,num)==0)
        {
            j++;
            printf("%d: %s%19s%14s %14s%16s%13.2f%10d\n",j,p->number,p->title,p->author,p->type,p->publish,p->price,p->num);
            p->x=j;

        }
       p=p->next;
    }
    if(j==0)
    {
        printf("No related book.(input 0 to return, input 1 to search again)\n");

        while(1)
        {
            ch=getch();
            if(ch=='0')
            {
                Menu();
                break;
            }
            else if(ch=='1')
            {
                continue;

            }

        }
        if(ch=='1')
            continue;

    }
    while(1)
    {
        printf("Please enter the book's serial number\n");
        scanf("%d",&x);getchar();
        if(x>j||x==0)
        {
            printf("Error, please input again\n");
        }
        else
            break;
    }
    printf("-------------------------------------------------\n");
    printf("|                                               |\n");
    printf("              Do you want to delete?\n");
    printf("|             1. yes        2. no\n");
    printf("|                                               |\n");
    printf("-------------------------------------------------\n");
    while(1)
    {
        t=getch();
        if(t=='1')
        {
            break;
        }
        else if(t=='2')
        {
            Menu();
        }
    }
    p=head;
    while(p!=NULL&&p->x!=x)
    {
        pre=p;
        p=p->next;
    }
    if(p!=NULL)
    {
        if(pre==NULL)
        {
            head=head->next;
        }
        else
        {
           pre->next=p->next;
        }

    }
    free(p);
    fp=fopen("library","wb");
    if(fp==NULL)
    {
        printf("Cannot open the file\n");
    }
    if(fwrite(head,N,1,fp)!=1)
    {
        printf("write error!\n");
    }
    fclose(fp);
    if(head!=NULL)
    {
        p=head->next;
        fp=fopen("library","ab");
        if(fp==NULL)
        {
            printf("Cannot open the file!\n");
        }
        while(p!=NULL)
        {
            if(fwrite(p,N,1,fp)!=1)
            {
                printf("Write error.");
            }
            p=p->next;
        }
        fclose(fp);

    }
    printf("|Delete successfully! Would you want to continue?|\n");
    printf("|       1.yes                         2.no       |\n");
    while(1)
    {
        c=getch();
        if(c=='1')
        {
            break;
        }
        else if(c=='2')
        {
            Menu();
        }
    }

  }while(1);
}

