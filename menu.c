#include<stdio.h>
#include "menu.h"
#include "bookChange.h"
#include "bookfile.h"
#include "List.h"
#include "borrowReturn.h"
//The menu to call different functions
void Menu()
{
    int b = mainMenu();
    do
    {
        if(b==1)
        {
            int a = staffMenu();
            if(a==1)
            {
                input_book();
                break;
            }

            if(a==2)
            {
                del_book();
                break;
            }

            if(a==3)
            {
                list_book();
                break;
            }

            if(a==4)
            {
                 list_user();
                 break;
            }

            if(a==5)
            {
                Menu();
                break;
            }

        }
    else if(b==2)
    {
        int b = studentMenu();
        if(b==1)
        {
            borrow_book();
            break;
        }

        if(b==2)
        {
            return_book();
            break;
        }

        if(b==3)
        {
             list_book();
             break;
        }

        if(b==4)
        {
            registration();
            break;
        }

        if(b==5)
        {
             search_book();
             break;
        }

        if(b==6)
        {
             Menu();
             break;
        }

    }
    else
    {
        printf("Wrong input! Please enter again.");
        break;
    }
   }while(1);

}
//Menu for the staff
int staffMenu()
{
    int func1;
    printf("               The library information system       \n");
    printf("        |          1. Add books                    |\n");
    printf("        |          2. Remove books                 |\n");
    printf("        |          3. List all books               |\n");
    printf("        |          4. List all registered users    |\n");
    printf("        |          5. Quit                         |\n");
    printf("        Input the number to choose the function.\n");
    scanf("%d",&func1);
    return func1;

}
//Menu for the student
int studentMenu()
{
    int func2;
    printf("               The library information system       \n");
    printf("        |          1. Borrow books                 |\n");
    printf("        |          2. Return books                 |\n");
    printf("        |          3. List all books               |\n");
    printf("        |          4. Registration                 |\n");
    printf("        |          5. Search for books             |\n");
    printf("        |          6. Quit                         |\n");
    printf("        Input the number to choose the function.\n");
    scanf("%d",&func2);
    return func2;
}
//The first menu for choosing the identity
int mainMenu()
{
    int choice;
    printf("*****Welcome to the library information system!*****\n\n");
    printf("     Please choose your identity.\n\n");
    printf("     1.Librarian          2.Student\n\n");
    printf("Input the number to choose your identity: ");
    scanf("%d",&choice);
    return choice;
}
