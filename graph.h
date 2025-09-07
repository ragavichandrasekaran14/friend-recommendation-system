#ifndef GRAPH_H
#define GRAPH_H

#include "user.h"

typedef struct {
    User users[MAX_USERS];
    int user_count;
    int adj[MAX_USERS][MAX_USERS];  // adjacency matrix for friendships
} SocialGraph;

void initGraph(SocialGraph *g);
void addUser(SocialGraph *g, User user);
void addFriendship(SocialGraph *g, const char *id1, const char *id2);
int findUserIndex(SocialGraph *g, const char *id);

#endif
