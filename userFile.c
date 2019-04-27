#include<stdio.h>
#include<stdlib.h>
#include"userStruct.h"
#include"userFile.h"
/*This function helps to store the user's information to
the file*/
void save_user(user n)
{
    FILE *fp;
    fp=fopen("user","ab");
    if(fp==NULL)
    {

        printf("Cannot open the file\n");
    }
    if(fwrite(n,M,1,fp)!=1)
    {
        printf("Error\n");
    }
    fclose(fp);
}
//This function returns to the head of user file
user read2()
{
    FILE *fp;
    int s=0;
    user a =NULL;
    user b1,b2,b3=NULL;
    fp=fopen("user","ab+");
    if(fp==NULL)
    {
        printf("Cannot open the file\n");
    }
    while(!feof(fp))
    {
        s++;
        b1=(user)malloc(M);
        fread(b1,M,1,fp);
        if(s==1)
        {
            a=b1;
            b2=b1;
        }
        else
        {
            b3=b2;
            b2->next=b1;
            b2=b1;
        }
    }
    if(b3!=NULL)
    {
        b3->next=NULL;
    }
    else
        a=NULL;
    fclose(fp);

    return a;

}



