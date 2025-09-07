#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INTERESTS 10
#define MAX_NAME_LEN 50
#define MAX_USERS 100
#define MAX_RECOMMENDATIONS 10

// --------- Struct Definitions ---------
typedef struct {
    char name[MAX_NAME_LEN];
    char interests[MAX_INTERESTS][MAX_NAME_LEN];
    int interest_count;
} User;

typedef struct {
    int user_id;
    double score;
    int mutual_friends_count;
    char mutual_friends_names[MAX_USERS][MAX_NAME_LEN];
    char common_interests[MAX_INTERESTS][MAX_NAME_LEN];
    int common_interest_count;
} Recommendation;

// --------- Function Prototypes ---------
int get_common_interests(User u1, User u2, char common[][MAX_NAME_LEN]);
void get_recommendations(User users[], int user_count, int user_id, Recommendation recs[], int *rec_count, int limit);

// --------- Implementation ---------
int get_common_interests(User u1, User u2, char common[][MAX_NAME_LEN]) {
    int count = 0;
    for (int i = 0; i < u1.interest_count; i++) {
        for (int j = 0; j < u2.interest_count; j++) {
            if (strcmp(u1.interests[i], u2.interests[j]) == 0) {
                strcpy(common[count], u1.interests[i]);
                count++;
            }
        }
    }
    return count;
}

void get_recommendations(User users[], int user_count, int user_id, Recommendation recs[], int *rec_count, int limit) {
    *rec_count = 0;
    User current = users[user_id];

    for (int i = 0; i < user_count && *rec_count < limit; i++) {
        if (i == user_id) continue; // Skip self

        Recommendation r;
        r.user_id = i;
        strcpy(r.mutual_friends_names[0], "DummyFriend"); // placeholder
        r.mutual_friends_count = 1; // placeholder
        r.score = (double)(rand() % 100) / 100.0; // random score for demo

        // Common interests
        r.common_interest_count = get_common_interests(current, users[i], r.common_interests);

        recs[*rec_count] = r;
        (*rec_count)++;
    }
}

// --------- Example Usage ---------
int main() {
    User users[3];

    // User 0
    strcpy(users[0].name, "Alice");
    users[0].interest_count = 2;
    strcpy(users[0].interests[0], "Music");
    strcpy(users[0].interests[1], "Reading");

    // User 1
    strcpy(users[1].name, "Bob");
    users[1].interest_count = 2;
    strcpy(users[1].interests[0], "Music");
    strcpy(users[1].interests[1], "Sports");

    // User 2
    strcpy(users[2].name, "Charlie");
    users[2].interest_count = 1;
    strcpy(users[2].interests[0], "Reading");

    Recommendation recs[MAX_RECOMMENDATIONS];
    int rec_count = 0;

    get_recommendations(users, 3, 0, recs, &rec_count, 2);

    printf("Recommendations for %s:\n", users[0].name);
    for (int i = 0; i < rec_count; i++) {
        printf("User: %s, Score: %.2f, Common Interests: ", users[recs[i].user_id].name, recs[i].score * 100);
        for (int j = 0; j < recs[i].common_interest_count; j++) {
            printf("%s ", recs[i].common_interests[j]);
        }
        printf("\n");
    }

    return 0;
}
