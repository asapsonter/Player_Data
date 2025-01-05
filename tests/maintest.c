#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// max length for string fields
#define MAX_NAME_LENGTH 70
#define MAX_POSITION_LENGTH 25
#define MAX_NATIONALITY_LENGTH 35

// define player info in struct
struct Player_Info {
    char Player_Name[MAX_NAME_LENGTH];
    char Player_Position[MAX_POSITION_LENGTH];
    char Player_Nationality[MAX_NATIONALITY_LENGTH];
    int Player_Age;
    double Player_Rating;
};

// print function
void print_player_data(struct Player_Info player) {
    printf("Player name: %s\n", player.Player_Name);
    printf("Player position: %s\n", player.Player_Position);
    printf("Player nationality: %s\n", player.Player_Nationality);
    printf("Player age: %d\n", player.Player_Age);
    printf("Player rating: %.2f\n", player.Player_Rating);
}

// test function to validate player initialization
void test_player_initialization() {
    struct Player_Info player;

    // Initialize player information
    strncpy(player.Player_Name, "Sam Sonter", MAX_NAME_LENGTH);
    strncpy(player.Player_Position, "Cutter", MAX_POSITION_LENGTH);
    strncpy(player.Player_Nationality, "Nigeria", MAX_NATIONALITY_LENGTH);
    player.Player_Age = 27;
    player.Player_Rating = 9.2;

    // Assertions to check if the values are initialized correctly
    assert(strcmp(player.Player_Name, "Sam Sonter") == 0);
    assert(strcmp(player.Player_Position, "Cutter") == 0);
    assert(strcmp(player.Player_Nationality, "Nigeria") == 0);
    assert(player.Player_Age == 27);
    assert(player.Player_Rating == 9.2);

    // Print player data to validate the print function
    print_player_data(player);
}

int main(void) {
    printf("Running tests...\n");

    // Run the test
    test_player_initialization();

    printf("All tests passed!\n");

    return 0;
}
