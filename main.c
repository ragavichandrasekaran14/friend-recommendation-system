#include <stdio.h>
#include "graph.h"
#include "recommendation.h"
#include "user.h"

int main() {
    SocialGraph g;
    initGraph(&g);

    // sample users
    char interests1[][MAX_NAME_LEN] = {"coding", "music", "books"};
    User u1 = createUser("1", "Alice", interests1, 3);
    addUser(&g, u1);

    char interests2[][MAX_NAME_LEN] = {"gaming", "music", "movies"};
    User u2 = createUser("2", "Bob", interests2, 3);
    addUser(&g, u2);

    char interests3[][MAX_NAME_LEN] = {"sports", "music", "cooking"};
    User u3 = createUser("3", "Charlie", interests3, 3);
    addUser(&g, u3);

    char interests4[][MAX_NAME_LEN] = {"books", "cooking", "art"};
    User u4 = createUser("4", "Diana", interests4, 3);
    addUser(&g, u4);

    // friendships
    addFriendship(&g, "1", "2");
    addFriendship(&g, "1", "3");
    addFriendship(&g, "2", "3");
    addFriendship(&g, "1", "4");

    // get recommendations for user 2
    Recommendation recs[10];
    int n = getRecommendations(&g, "2", recs, 5);

    printf("Friend Recommendations for Bob:\n");
    for (int i = 0; i < n; i++) {
        printf("- %s (Score: %.2f, Mutual: %d, Interests: ",
               recs[i].name, recs[i].score, recs[i].mutual_friends);
        for (int j = 0; j < recs[i].common_interest_count; j++) {
            printf("%s ", recs[i].common_interests[j]);
        }
        printf(")\n");
    }

    return 0;
}
