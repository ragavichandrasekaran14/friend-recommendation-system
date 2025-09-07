#include "user.h"
#include <string.h>

// Simple function to create a user
User createUser(const char *id, const char *name, char interests[][MAX_NAME_LEN], int interest_count) {
    User u;
    strncpy(u.id, id, MAX_NAME_LEN);
    strncpy(u.name, name, MAX_NAME_LEN);
    u.interest_count = interest_count;
    u.friend_count = 0;
    for (int i = 0; i < interest_count; i++) {
        strncpy(u.interests[i], interests[i], MAX_NAME_LEN);
    }
    return u;
}
