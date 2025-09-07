#include "recommendation.h"
#include <string.h>

// helper function: intersection of interests
int findCommonInterests(User *a, User *b, char common[][MAX_NAME_LEN]) {
    int count = 0;
    for (int i = 0; i < a->interest_count; i++) {
        for (int j = 0; j < b->interest_count; j++) {
            if (strcmp(a->interests[i], b->interests[j]) == 0) {
                strncpy(common[count++], a->interests[i], MAX_NAME_LEN);
            }
        }
    }
    return count;
}

int getRecommendations(SocialGraph *g, const char *user_id, Recommendation recs[], int limit) {
    int u_idx = findUserIndex(g, user_id);
    if (u_idx == -1) return 0;

    int rec_count = 0;
    User *u = &g->users[u_idx];

    for (int i = 0; i < g->user_count; i++) {
        if (i == u_idx || g->adj[u_idx][i]) continue; // skip self & existing friends

        User *cand = &g->users[i];

        // mutual friends count
        int mutual = 0;
        for (int f = 0; f < g->user_count; f++) {
            if (g->adj[u_idx][f] && g->adj[i][f]) mutual++;
        }

        // common interests
        char common[MAX_INTERESTS][MAX_NAME_LEN];
        int common_count = findCommonInterests(u, cand, common);

        // simple score
        double score = mutual * 0.6 + common_count * 0.4;

        Recommendation r;
        strncpy(r.user_id, cand->id, MAX_NAME_LEN);
        strncpy(r.name, cand->name, MAX_NAME_LEN);
        r.score = score;
        r.mutual_friends = mutual;
        r.common_interest_count = common_count;
        for (int c = 0; c < common_count; c++) {
            strncpy(r.common_interests[c], common[c], MAX_NAME_LEN);
        }

        if (rec_count < limit) {
            recs[rec_count++] = r;
        }
    }
    return rec_count;
}

