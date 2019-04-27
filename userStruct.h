#ifndef USERSTRUCT_H_INCLUDED
#define USERSTRUCT_H_INCLUDED
#define M sizeof(struct USER)
struct USER
{
    char name[10];//The user's name
    char ID[20];//The user's student ID
    int book;//The number of books this user has borrowed
    struct USER *next;
};
typedef struct USER User;
typedef User *user;

#endif // USERSTRUCT_H_INCLUDED
