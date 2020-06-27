#include <stdio.h>

int check_win(char* board);
int check_draw(char* board);
int play_game(char* board, int* player);
int three_are_equal(char x, char y, char z);
void print_win(char piece);
void draw_board (char* board);

int main (void) {
    char board[] = {'1','2','3','4','5','6','7','8','9'};
    int player = 1;
    while (play_game(board, &player));
    return 0;
}

int check_win(char* board) {
    for (int i = 0; i < 3; i++) {

        // horizontal
        if (three_are_equal(
                    board[0 + 3 * i],
                    board[1 + 3 * i],
                    board[2 + 3 * i])) {
            draw_board(board);
            print_win(board[0 + 3 * i]);
            return 1;
        }

        //vertical
        if (three_are_equal(
                    board[0 + i],
                    board[3 + i],
                    board[6 + i])) {
            draw_board(board);
            print_win(board[0 + i]);
            return 1;
        }
    }

    // diagonal top left to bottom right
    if (three_are_equal(board[0], board[4], board[8])) {
        draw_board(board);
        print_win(board[0]);
        return 1;
    }

    // diagonal top right to bottom left
    if (three_are_equal(board[2], board[4], board[6])) {
        draw_board(board);
        print_win(board[2]);
        return 1;
    }

    if (check_draw(board)) {
        draw_board(board);
        printf("DRAW\n");
        return 1;
    }

    // game's not over
    return 0;
}

int check_draw(char* board) {
    for(int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') {
            printf("%d\n", i);
            return 0;
        }
    }
    return 1;
}

// probably not necessary, but it looked gross in-lined
void print_win (char piece) {
    printf("Player %d wins!\n", piece == 'X' ? 1 : 2);
}

// probably not necessary, but it looked gross in-lined
int three_are_equal(char x, char y, char z) {
    return x == y && y == z;
}

int play_game(char* board, int* player) {
    if (check_win(board)) return 0;

    int move = 0;
    draw_board(board);
    printf("Player %d move: ", *player);
    scanf("%d", &move);

    while (board[move - 1] == 'X' || board[move - 1] == 'O') {
        // keep redrawing until they put in something valid
        draw_board(board);
        printf("Invalid move\n");
        printf("Player %d move: ", *player);
        scanf("%d", &move);
    }

    char piece = *player == 1 ? 'X' : 'O';
    board[move - 1] = piece;
    *player = *player == 1 ? 2 : 1;
    return 1;
}

void draw_board(char* board) {
    // clears screen (unix based systems only)
    printf("\033c");
    printf("Tic Tac Toe\n");
    printf("=============\n");

    for (int i = 0; i < 3; ++i) {
        printf("| %c | %c | %c |\n",
                board[0 + 3 * i],
                board[1 + 3 * i],
                board[2 + 3 * i]);
    }

    printf("=============\n");
}
