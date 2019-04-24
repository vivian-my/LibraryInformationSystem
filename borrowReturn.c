#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "borrowReturn.h"
#include"bookStruct.h"
#include"bookfile.h"
#include"userStruct.h"
#include"userFile.h"
/*This function is going to help a student to borrow a book
    and it updates the amount of book in the "library file" and the number of
    books that the student has borrowed.
*/
void  borrow_book()
{
    do
    {
       int result;
       int j=0;
       int x,q;
       int flag=0;
       book head,p;
       user head1,p1;
       char ch,t;
       FILE *fp,*fp1;
       char _title[30];
       char _ID[20];
       int num;
       head=read();      //return to the head of book file
       head1=read2();    //return to the head of user file
       p=head;
       p1=head1;
       printf("Please enter the book you want to borrow.\n");
       getchar();
       gets(_title);
       while(p!=NULL)
       {
           p->x=0;
           p=p->next;
       }
       p=head;
       printf("***************************************The book overview****************************************\n");
       printf("-------------------------------------------------------------------------------------------------\n");
       printf("  Landing number     Title        Author          Type         Publish        Price       Amount\n");
       while(p!=NULL)//search and print the book
       {
           if(p!=NULL&&strcmp(p->title,_title)==0)
           {
                j++;
                printf("%d: %s  %18s%13s %12s%15s%16.2f%10d\n",j,p->number,p->title,p->author,p->type,p->publish,p->price,p->num);
                p->x=j;
           }
           p=p->next;
       }
       if(j==0)
       {
           printf("The library does not have this book.(0:return 1:search again)\n");
           while(1)
           {
                scanf("%d",&q);
                if(q==0)
                {
                    Menu();
                    break;
                }
                else if(q==1)
                {
                    break;
                }
           }
           if(q==1)
           {
               continue;
           }

       }

       while(1)
       {
           printf("Enter the serial number of the book you want to borrow.\n");
           scanf("%d",&x);getchar();
           if(x>j||x==0)
           {
               printf("Error,please enter again.\n");
           }
           else
            break;

       }
       p=head;
       while(p!=NULL&&p->x!=x)
       {
           p=p->next;
       }

        if(p)
       {
           if(p->num>0) //To ensure the library currently has this book
           {
           printf("Please enter your ID:\n"); //To ensure only registered students can borrow
           gets(_ID);

           while(p1!=NULL)
           {
                if(p1!=NULL&&strcmp(p1->ID,_ID)==0)
                {
                    p1->book++;
                    flag=1;
                    break;
                }
                p1=p1->next;
           }
           if(flag==0)
           {
               printf("You have not registed.\n");
               Menu();
               break;
           }
           num=p->num;
           num--;
           p->num=num;  //To decrease the amount of books in the library
           }
           else
           {
               printf("The book is not available.\n");
               printf("Enter any key to return the menu.\n");
               getchar();
               Menu();
               break;
           }
       }
       fp1 = fopen("user","wb");
       if(fp1==NULL)
       {
           printf("Cannot open the file\n");
       }
       if(fwrite(head1,M,1,fp1)!=1)
       {
           printf("Write error!\n");
       }
       fclose(fp1);
       if(head1!=NULL)
       {
           p1=head1->next;
           fp1=fopen("user","ab");
           if(fp1==NULL)
           {
               printf("Cannot open the file\n");
           }
           while(p1!=NULL)
           {
               if(fwrite(p1,N,1,fp1)!=1)
                printf("Write error\n");
               p1=p1->next;
           }
           fclose(fp1);
        }

       fp=fopen("library","wb");
       if(fp==NULL)
       {
           printf("Cannot open the file\n");
       }
       if(fwrite(head,N,1,fp)!=1)
       {
           printf("Write error\n");

       }
       fclose(fp);
       if(head!=NULL)
       {
           p=head->next;
           fp=fopen("library","ab");
           if(fp==NULL)
           {
               printf("Cannot open the file\n");
           }
           while(p!=NULL)
           {
               if(fwrite(p,N,1,fp)!=1)
                printf("Write error\n");
               p=p->next;
           }
           fclose(fp);
        }
        printf("Borrow successfully!\n");
        printf("Do you want to continue?\n");
        printf("1.Yes          2. NO\n");
        scanf("%d",&result);getchar();
        if(result==1)
            continue;
        else if(result==2)
        {
            Menu();
            break;
        }

   }while(1);

}
/*This function helps the user to return a book
this increases the amount of books and decreases the number of books that
student borrow.
*/
void return_book()
{
    do
    {
        int result;
        int flag=0;
        FILE *fp;
        FILE *fp1;
        char _ID[20];
        char _number[10];
        int num;
        book p,head;
        user head1,p1;
        head1=read2();
        p1=head1;
        head=read();
        p=head;
        printf("Please enter you student ID:\n");
        getchar();
        gets(_ID);
        while(p1!=NULL)
        {
             if(p1!=NULL&&strcmp(p1->ID,_ID)==0)
                {
                    p1->book--;
                    flag=1;
                    break;
                }
                p1=p1->next;
        }
        if(flag==0)
           {
               printf("You have not registed.\n");
               Menu();
               break;
           }

        printf("Please enter the landing number of the book you want to return.\n");
        scanf("%s",_number);getchar();
        while(p!=NULL)
        {
            if(p!=NULL&&strcmp(p->number,_number)==0)
                break;
            p=p->next;
        }

        if(p)
        {
            num=p->num;
            num++;          //To increase the number of books
            p->num=num;
        }
        else
        {
            printf("Error: Cannot find the book.Please enter again!\n");
            continue;
        }


       fp=fopen("library","wb");
       if(fp==NULL)
       {
           printf("Cannot open the file\n");
       }
       if(fwrite(head,N,1,fp)!=1)
       {
           printf("Write error\n");

       }
       fclose(fp);
       if(head!=NULL)
       {
           p=head->next;
           fp=fopen("library","ab");
           if(fp==NULL)
           {
               printf("Cannot open the file\n");
           }
           while(p!=NULL)
           {
               if(fwrite(p,N,1,fp)!=1)
                printf("Write error\n");
               p=p->next;
           }
           fclose(fp);
        }
        printf("Return successfully!\n");

       fp1 = fopen("user","wb");
       if(fp1==NULL)
       {
           printf("Cannot open the file\n");
       }
       if(fwrite(head1,M,1,fp1)!=1)
       {
           printf("Write error!\n");
       }
       fclose(fp1);
       if(head1!=NULL)
       {
           p1=head1->next;
           fp1=fopen("user","ab");
           if(fp1==NULL)
           {
               printf("Cannot open the file\n");
           }
           while(p1!=NULL)
           {
               if(fwrite(p1,N,1,fp1)!=1)
                printf("Write error\n");
               p1=p1->next;
           }
           fclose(fp1);
        }

        printf("Do you want to continue?\n");
        printf("1.Yes          2. NO\n");
        scanf("%d",&result);getchar();
        if(result==1)
            continue;
        else if(result==2)
        {
            Menu();
            break;
        }
    }while(1);
}
