#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "registration.h"
#include "userStruct.h"
#include "userFile.h"
/*
This function helps a student to do registration and
this will help to record the student's name, ID into the file.
*/
void registration()
{
    do
    {
    int d;
    user k;
    k=(user)malloc(M);
    printf("*************Registration**************\n");
    printf("Please enter your name:\n");
    scanf("%s",k->name);getchar();
    printf("Please enter you student ID:\n");
    scanf("%s",k->ID);getchar();
    k->book = 0;            //Initialize the number of book student borrow to 0
    save_user(k);
    printf("Successfully registration!\n");
    printf("Input 1 to return.\n");
    scanf("%d",&d);
    if(d==1)
    {
        Menu();
        break;
    }
    else
        break;

    }while(1);
}
