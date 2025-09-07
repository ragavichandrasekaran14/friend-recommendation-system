#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include "graph.h"

typedef struct {
    char user_id[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    double score;
    int mutual_friends;
    char common_interests[MAX_INTERESTS][MAX_NAME_LEN];
    int common_interest_count;
} Recommendation;

int getRecommendations(SocialGraph *g, const char *user_id, Recommendation recs[], int limit);

#endif
