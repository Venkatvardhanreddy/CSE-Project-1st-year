#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playTicTacToe() {
    printf("Tic Tac Toe Game\n");
	char board[3][3]; // 3x3 Tic Tac Toe board

    // Function to initialize the board
    void initialize_board() {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Function to draw the board
    void draw_board() {
        int i, j;
        printf("  0 1 2\n");
        for (i = 0; i < 3; i++) {
            printf("%d ", i);
            for (j = 0; j < 3; j++) {
                printf("%c", board[i][j]);
                if (j < 2) {
                    printf("|");
                }
            }
            printf("\n");
            if (i < 2) {
                printf("  -----\n");
            }
        }
        printf("\n");
    }

    // Function to check if a player has won
    int check_winner(char mark) {
        int i;
        // Check rows and columns for a win
        for (i = 0; i < 3; i++) {
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
                (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                return 1; // Win
            }
        }
        // Check diagonals for a win
        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            return 1; // Win
        }
        return 0; // No win
    }

    // Function to make a move
    int make_move(int row, int col, char mark) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return 0; // Invalid move
        }
        board[row][col] = mark;
        return 1; // Valid move
    }

    // Initialize the board
    initialize_board();

    int row, col, currentPlayer = 1;
    char playerMark = 'X';

    while (1) {
        draw_board();
        printf("Player %d, enter row (0-2) and column (0-2) to place your mark: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (make_move(row, col, playerMark)) {
            if (check_winner(playerMark)) {
                draw_board();
                printf("Player %d (%c) wins!\n", currentPlayer, playerMark);
                break;
            } else if (playerMark == 'X') {
                playerMark = 'O';
            } else {
                playerMark = 'X';
            }
            currentPlayer = (currentPlayer % 2) + 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

}

void playRockPaperScissors() {
    int player_choice, computer_choice;
    srand(time(NULL));

    printf("Rock-Paper-Scissors Game\n");
    printf("Choose your move:\n");
    printf("0 - Rock\n");
    printf("1 - Paper\n");
    printf("2 - Scissors\n");
    printf("Enter your choice (0-2): ");
    scanf("%d", &player_choice);

    if (player_choice < 0 || player_choice > 2) {
        printf("Invalid choice. Please enter a number between 0 and 2.\n");
        return;
    }

    computer_choice = rand() % 3;

    printf("You chose: ");
    switch (player_choice) {
        case 0:
            printf("Rock\n");
            break;
        case 1:
            printf("Paper\n");
            break;
        case 2:
            printf("Scissors\n");
            break;
    }

    printf("Computer chose: ");
    switch (computer_choice) {
        case 0:
            printf("Rock\n");
            break;
        case 1:
            printf("Paper\n");
            break;
        case 2:
            printf("Scissors\n");
            break;
    }

    if (player_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if ((player_choice == 0 && computer_choice == 2) ||
               (player_choice == 1 && computer_choice == 0) ||
               (player_choice == 2 && computer_choice == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Game Center!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Play Tic Tac Toe\n");
        printf("2. Play Rock-Paper-Scissors\n");
        printf("3. Quit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playTicTacToe();
                break;
            case 2:
                playRockPaperScissors();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);

    return 0;
}

