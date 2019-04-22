#include<stdio.h>
#include<stdlib.h>
#include"bookfile.h"
#include"bookStruct.h"
void save_book(book p)
{
   FILE *fp;
   fp=fopen("library","ab");
   if(fp==NULL)
   {
       printf("Cannot open the file.");
   }
   if(fwrite(p,N,1,fp)!=1)
   {
       printf("File error.");
   }
   fclose(fp);
}
book read()
{
    FILE *fp;
    int n=0;
    book head = NULL;
    book p1,p2,p3 = NULL;
    fp=fopen("library","ab+");
    if(fp==NULL)
    {
       printf("cannot open the file\n");
    }
    while(!feof(fp))
    {
        n++;
        p1=(book)malloc(N);
        fread(p1,N,1,fp);
        if(n==1)
        {
            head=p1;
            p2=p1;
        }
        else
        {
            p3=p2;
            p2->next=p1;
            p2=p1;
        }
    }
    if(p3!=NULL)
    {
        p3->next=NULL;
    }
    else
        head=NULL;
    fclose(fp);

    return head;

}
