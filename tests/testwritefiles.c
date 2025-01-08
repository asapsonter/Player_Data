/*#include <stdio.h> 

int main(void){
    FILE *fp;
    int x = 32;

    fp = fopen("test.txt", "a");
    fputc('B', fp);
    fputc('\n', fp);//new line
    fprintf(fp, "x=%d \n", x); 
    fputs("this puts line \n", fp);

    fclose(fp);




    // char name[1024];
    // float length;
    // int mass;

    // fp = fopen("test.txt", "r"); //read file

    // while ( fscanf(fp, "%s %f %d", name, &length, &mass) != EOF) // while memory is not wrong
    //     printf("%s whale, %d tonnes, %.1f metters \n", name, mass, length);
    //     fclose(fp);
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // For bool type

// max length for string fields
#define MAX_NAME_LENGTH 70
#define MAX_POSITION_LENGTH 25
#define MAX_NATIONALITY_LENGTH 35
#define MAX_PLAYERS 100 // Maximum number of players

// define player info in struct
struct Player_Info {
    char Player_Name[MAX_NAME_LENGTH];
    char Player_Position[MAX_POSITION_LENGTH];
    char Player_Nationality[MAX_NATIONALITY_LENGTH];
    int Player_Age;
    double Player_Rating;
};

// Function to write player data to file with index and metadata
bool write_player_to_file(const struct Player_Info *player, int index) {
    FILE *fp = fopen("player_data.txt", "a"); // Append mode
    if (fp == NULL) {
        perror("Error opening file for writing");
        return false;
    }

    // Metadata format: Index|Name Length|Position Length|Nationality Length|Age|Rating
    fprintf(fp, "%d|%zu|%zu|%zu|%d|%lf\n", index, strlen(player->Player_Name),
            strlen(player->Player_Position), strlen(player->Player_Nationality),
            player->Player_Age, player->Player_Rating);
    //Data format: Name|Position|Nationality
    fprintf(fp,"%s|%s|%s\n",player->Player_Name,player->Player_Position,player->Player_Nationality);

    fclose(fp);
    return true;
}

// Function to delete player info at a specific index and re-index
bool delete_player_at_index(int index) {
    FILE *fp = fopen("player_data.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return false;
    }

    FILE *temp_fp = fopen("temp.txt", "w");
    if (temp_fp == NULL) {
        perror("Error opening temporary file");
        fclose(fp);
        return false;
    }

    int current_index = 0;
    char line[256]; // Adjust buffer size as needed
    char data_line[256];
    while (fgets(line, sizeof(line), fp) != NULL && fgets(data_line, sizeof(data_line), fp) != NULL) {
        if (current_index != index) {
            fprintf(temp_fp, "%s", line);
            fprintf(temp_fp, "%s", data_line);
        }
        current_index++;
    }

    fclose(fp);
    fclose(temp_fp);

    if (remove("player_data.txt") != 0) {
        perror("Error deleting original file");
        return false;
    }

    if (rename("temp.txt", "player_data.txt") != 0) {
        perror("Error renaming temporary file");
        return false;
    }

    return true;
}

// ... (rest of the code: print_player_data, input validation functions)

int main(void) {
    struct Player_Info player;
    int player_count = 0; // Initialize player count

    while (player_count < MAX_PLAYERS) {
        get_valid_string("Enter player name (or press Enter to finish): ", player.Player_Name, MAX_NAME_LENGTH);
        if (player.Player_Name[0] == '\0') { // Check for empty input
            break; // Exit input loop
        }
        get_valid_string("Enter player position: ", player.Player_Position, MAX_POSITION_LENGTH);
        get_valid_string("Enter player nationality: ", player.Player_Nationality, MAX_NATIONALITY_LENGTH);
        player.Player_Age = get_valid_int("Enter player age: ");
        player.Player_Rating = get_valid_double("Enter player rating: ");

        print_player_data(player);

        if (write_player_to_file(&player, player_count)) {
            printf("Player data saved successfully.\n");
            player_count++;
        } else {
            printf("Failed to save player data.\n");
        }
    }

    int delete_index;
    printf("Enter index of player to delete (or -1 to skip deletion): ");
    scanf("%d", &delete_index);

    if (delete_index >= 0 && delete_index < player_count) {
        if (delete_player_at_index(delete_index)) {
            printf("Player at index %d deleted successfully.\n", delete_index);
            player_count--;
        } else {
            printf("Failed to delete player.\n");
        }
    } else if (delete_index != -1) {
        printf("Invalid index.\n");
    }

    printf("testing dir\n");
    return 0;
}

    return 0;
}*/
