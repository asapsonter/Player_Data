#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// max length for string fields
#define MAX_NAME_LENGTH 70
#define MAX_POSITION_LENGTH 25
#define MAX_NATIONALITY_LENGTH 35

// define player info in struct
struct Player_Info
{
    char Player_Name[MAX_NAME_LENGTH];
    char Player_Position[MAX_POSITION_LENGTH];
    char Player_Nationality[MAX_NATIONALITY_LENGTH];
    int Player_Age;
    double Player_Rating;
};

// print function

void print_player_data(struct Player_Info player)
{
    printf("\n Player name: %s \n", player.Player_Name);
    printf("\n Player postion: %s \n", player.Player_Position);
    printf("\n Player nationality: %s \n", player.Player_Nationality);
    printf("\n Player age: %d \n", player.Player_Age);
    printf("\n Player nationality: %f \n", player.Player_Rating);
}

// function to validate integer input
/**int get_valid_int(const char *prompt)
{
    int value;
    char input[20];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            if (sscanf(input, "%d", &value) == 1)
            {
                return value;
            }
        }
        printf("Invalid input. Please enter an integer.\n");
    }
} **/
int get_valid_int(const char *prompt)
{
    int value;
    char input[20];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            if (feof(stdin)){
                printf("end of input \n");
            } else{
                perror("error reading input");
            }
            exit(EXIT_FAILURE);

        }
        if (sscanf(input, "%d", &value) == 1)
            {
                return value;
            }
        printf("Invalid input. Please enter an integer.\n");
    }
}

// function to validate double input
double get_valid_double(const char *prompt)
{
    double value;
    char input[20];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            if (sscanf(input, "%lf", &value) == 1)
            {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}
// function to get valid string input
/*void get_valid_string(const char *prompt, char *str, int max_length)
{
    printf("%s", prompt);
    if (fgets(str, max_length, stdin) != NULL)
    {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }   
    }
}*/
void get_valid_string(const char *prompt, char *str, int max_length)
{
    printf("%s", prompt);
    if (fgets(str, max_length, stdin) != NULL)
    {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        } else {
            //input too long. clear input buffer

            int c;
            while( (c = getchar()) != '\n' && c != EOF);
            printf(" input too long. Please enter a string up tp %d characters. \n", max_length - 1);
            // You might want to re-prompt here or handle the error differently
            str[0] = '\0'; // Set to empty string to avoid further issues

            return;
        }  

    }
}
int main(void)
{
    struct Player_Info player;

    // strncpy(player.Player_Name, "Sam Sonter", MAX_NAME_LENGTH);
    // strncpy(player.Player_Position, "Cutter", MAX_POSITION_LENGTH);
    // strncpy(player.Player_Nationality, "Nigeria", MAX_NATIONALITY_LENGTH);
    // player.Player_Age = 27;
    // player.Player_Rating = 9.2;
    get_valid_string("Enter player name: ", player.Player_Name, MAX_NAME_LENGTH);
    get_valid_string("Enter player position: ", player.Player_Position, MAX_POSITION_LENGTH);
    get_valid_string("Enter player nationality: ", player.Player_Nationality, MAX_NATIONALITY_LENGTH);
    player.Player_Age = get_valid_int("Enter player age: ");
    player.Player_Rating = get_valid_double("Enter player rating: ");

    print_player_data(player);

    printf("\ntesting dir");
    return 0;
}
