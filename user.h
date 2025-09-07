#ifndef USER_H
#define USER_H

#define MAX_INTERESTS 10
#define MAX_NAME_LEN 50
#define MAX_USERS 100

typedef struct {
    char id[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    char interests[MAX_INTERESTS][MAX_NAME_LEN];
    int interest_count;
    int friends[MAX_USERS];  // store indices of friends
    int friend_count;
} User;

#endif
