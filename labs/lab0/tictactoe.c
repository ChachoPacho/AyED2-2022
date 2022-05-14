#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 3
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t .................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t .................................................\n");
    }
}

//  FUNCIONA TAMBIEN EN TATETIES DE DIMENSIONES MAYORES
char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    unsigned int matchesRow = 0;
    unsigned int matchesCol = 0;
    unsigned int matchesCross = 0;
    unsigned int matchesReversedCross = 0;

    unsigned int aux = 0;

    // IMPLEMENTAR
    for (unsigned int i = 0; i < BOARD_SIZE; i++) {
        //  Iteramos columnas y filas
        for (unsigned int j = 0; j < BOARD_SIZE - 1; j++) {
            if (board[i][j] == board[i][j + 1]) matchesRow++;

            if (board[j][i] == board[j + 1][i]) matchesCol++;
        }

        //  Vemos si alguna tiene tateti
        if (matchesRow == BOARD_SIZE - 1 || 
            matchesCol == BOARD_SIZE - 1) return board[i][i];

        //  Condicional para evitar salir del rango
        if (i != BOARD_SIZE - 1) {
            aux = BOARD_SIZE - 1 - i;
            if (board[i][i] == board[i + 1][i + 1]) matchesCross++;

            if (board[i][aux] == board[i + 1][aux - 1]) matchesReversedCross++;
        } else if (matchesCross == BOARD_SIZE - 1 || 
            matchesReversedCross == BOARD_SIZE - 1) {
            aux = (BOARD_SIZE - (BOARD_SIZE % 2)) / 2;
            return board[aux][aux];
        };

        //  Reinicio
        matchesRow = 0;
        matchesCol = 0;
    }

    return '-';
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    // IMPLEMENTAR
    for (unsigned int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') return true;
        }
    }

    return false;
}

int main(void)
{
    printf("TicTacToe\n");

    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al 8): ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
