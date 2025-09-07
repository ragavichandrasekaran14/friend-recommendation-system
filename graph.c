#include "graph.h"
#include <string.h>

void initGraph(SocialGraph *g) {
    g->user_count = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addUser(SocialGraph *g, User user) {
    if (g->user_count < MAX_USERS) {
        g->users[g->user_count++] = user;
    }
}

int findUserIndex(SocialGraph *g, const char *id) {
    for (int i = 0; i < g->user_count; i++) {
        if (strcmp(g->users[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void addFriendship(SocialGraph *g, const char *id1, const char *id2) {
    int i = findUserIndex(g, id1);
    int j = findUserIndex(g, id2);
    if (i != -1 && j != -1) {
        g->adj[i][j] = g->adj[j][i] = 1;
    }
}
