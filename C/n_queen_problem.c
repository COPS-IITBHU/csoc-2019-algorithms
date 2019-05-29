/*The N Queens Problem is one of the most common examples of backtracking. 
The problem is to arrange N queens on an NxN chessboard such that no queen can strike down any other queen. 
A queen can attack horizontally, vertically, or diagonally.

Author: Gaurav Burjwal ( https://github.com/gauravburjwal )
*/

#include<stdio.h>

// number of queens
int n;

// chessboard
int board[50][50];

// function checking if the cell is attacked or not
int attacked(int a, int b)
{
    int c, d;
    // to check if there is queen in row or column
    for(c = 0; c < n; c++)
    {
        if((board[a][c] == 1) || (board[c][b] == 1))
            return 1;
    }

    // to check in diagnols
    for(c = 0; c < n; c++)
    {
        for(d = 0; d < n; d++)
        {
            if(((c + d) == (a + b)) || ((c - d) == (a - b)))
            {
                if(board[c][d] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int n_queen(int x)
{
    int a, b;
    if(x == 0)
        return 1;
    for(a = 0; a < n; a++)
    {
        for(b = 0; b < n; b++)
        {
            // to check if the place is attacked or occupied 
            if((!attacked(a, b)) && (board[a][b] != 1))
            {
                board[a][b] = 1;
                if(n_queen(x-1) == 1)
                {
                    return 1;
                }
                board[a][b] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    // taking dimension of chessboard
    printf("Enter the value of n for square chessboard: ");
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    // calling the function
    n_queen(n);

    // printing the result
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d\t", board[i][j]);
        printf("\n");
    }
    return 0;
}