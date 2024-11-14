#include <stdio.h>
#include <string.h>

struct Player
{
    int num;
    int win;
    int losses;
    int rank;
};
struct Game
{
    char type[10];  // type ranked or casual
    int winner_num; // winner's player ID
    int loser_num;  // loser's player ID
};
void addGame(struct Game games[], int *gameCount, struct Player players[], int winner_num, int loser_num, char type);
void player_rank(struct Player players[]);                       // print player ranks
void player_stat(struct Player players[], int playernum);        // print player stats
void print_games(struct Game games[], int gameCount, char type); // print games based on type

int main()
{
    struct Player players[5];
    struct Game games[20];
    int gameCount = 0;
    char command; // input by the user
    for (int i = 0; i < 5; i++)
    {
        players[i].num = i + 1;
        players[i].win = 0;
        players[i].losses = 0;
        players[i].rank = 100;
    }
    while (1)
    {
        printf("\nEnter n, r, p, g or x: ");
        scanf(" %c", &command);
        if (command == 'n')
        {
            char type;
            int winner_num, loser_num;
            printf("\nEnter game type (c,r): ");
            scanf(" %c", &type);
            printf("\nEnter winner ID (1-5): ");
            scanf("%d", &winner_num);
            printf("\nEnter loser ID (1-5): ");
            scanf("%d", &loser_num);
            if (winner_num == loser_num)
            {
                printf("\nWinner and loser identical!");
            }
            else
            {
                addGame(games, &gameCount, players, winner_num, loser_num, type);
            }
        }
        else if (command == 'r')
        {
            player_rank(players);
        }
        else if (command == 'p')
        {
            int playernum;
            printf("\nSelect player (1-5): ");
            scanf("%d", &playernum);
            player_stat(players, playernum);
        }
        else if (command == 'g')
        {
            char type;
            printf("\nRanked or casual? (r,c): ");
            scanf(" %c", &type);
            print_games(games, gameCount, type);
        }
        else if (command == 'x')
        {
            break;
        }
    }
    return 0;
}
void addGame(struct Game games[], int *gameCount, struct Player players[], int winner_num, int loser_num, char type)
{
    struct Game newGame;
    if (type == 'r')
    {
        strcpy(newGame.type, "ranked");
    }
    else
    {
        strcpy(newGame.type, "casual");
    }
    newGame.winner_num = winner_num;
    newGame.loser_num = loser_num;
    games[*gameCount] = newGame; // add the new game to the array
    (*gameCount)++;
    players[winner_num - 1].win++;   // update player statistics
    players[loser_num - 1].losses++; // update player statistics

    if (type == 'r')
    {
        players[winner_num - 1].rank += 50; // increase winner's rank
        players[loser_num - 1].rank -= 50;  // decrease loser's rank
        // rank>= 0
        if (players[loser_num - 1].rank < 0)
        {
            players[loser_num - 1].rank = 0;
        }
    }
    printf("\nNew game added");
}

// print player ranks
void player_rank(struct Player players[])
{
    printf("\nPlayer ranks");
    int maxRank = 0;
    for (int i = 0; i < 5; i++)
    { // find the highest rank
        if (players[i].rank > maxRank)
        {
            maxRank = players[i].rank;
        }
    }
    for (int i = 0; i < 5; i++)
    { // Print the rank of each player
        printf("\nPlayer %d - Rank %d", players[i].num, players[i].rank);
        if (players[i].rank == maxRank)
        {
            printf(" - TOP");
        }
    }
}

// print player statistics
void player_stat(struct Player players[], int playernum)
{
    struct Player player = players[playernum - 1];
    printf("\nPlayer %d - Rank %d", player.num, player.rank);
    int totalGames = player.win + player.losses;
    double winRate;
    if (totalGames > 0)
    {
        winRate = (double)player.win / totalGames * 100;
    }
    else
    {
        winRate = 0.0;
    }
    printf("\nWins/Losses/Winrate: %d/%d/%.2f %%", player.win, player.losses, winRate);
}

// print games of a specified type
void print_games(struct Game games[], int gameCount, char type)
{
    int found = 0;

    // print games that match the specified type
    for (int i = 0; i < gameCount; i++)
    {
        if ((type == 'r' && strcmp(games[i].type, "ranked") == 0) ||
            (type == 'c' && strcmp(games[i].type, "casual") == 0))
        {
            printf("\nWinner: %d - Loser: %d", games[i].winner_num, games[i].loser_num);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nThere are no games yet.");
    }
}