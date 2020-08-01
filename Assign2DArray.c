/*
 * =====================================================================================
 *
 *       Filename:  Assign2DArray.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/22/20 22:37:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

const int ROW = 3;
const int COL = 4;

// row 0 - > 1 1 1
// row 1 - > 2 2 2
// row 3 - > 3 3 3

// Row and column are allocated in contigious memory
int **assign2DArrayMethod2(int row, int col)
{
    int **arr2D = (int **)malloc(sizeof(int*)*row + (row *col));

    for(int i = 0; i < row; ++i)
    {
        arr2D[i] = (int *)((int*)arr2D + ((sizeof(int*)*row) + (i * col)));
    }

    return arr2D;
}

// Row and column are allocated in non-contigious memory
int **assign2DArrayMethod1(int row, int col)
{
    int **arr2D = (int **)malloc(sizeof(int *)*row);

    for(int i = 0; i < row; ++i)
    {
        arr2D[i] = (int *)malloc(sizeof(int)*col);
    }

    return arr2D;
}

// Memory allocated using assign2DArrayMethod1() needs
// special method to deallocate assigned memory
void free2DArrayMethod1(int **arr2D, int row)
{
    for(int i = 0; i < row; ++i)
    {
        free(arr2D[i]);
    }

    free(arr2D);
}

void initialize2DArrayAndPrint(int **arr2D, int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            arr2D[i][j] = i + j;

            printf("%3d ", arr2D[i][j]);
        }

        printf("\n");
    }
}

int main(int argc, char ** argv)
{
    int row;
    int col;

    printf("Enter number of row : ");

    scanf("%d", &row);

    printf("Enter number of col : ");

    scanf("%d", &col);

    printf("++++++++++++ %d x %d Matrix using method1 +++++++++++\n", row, col);

    int **arr2D = assign2DArrayMethod1(row, col);

    initialize2DArrayAndPrint(arr2D, row, col);

    // Needs special API to deallocate memory
    // allocated using assign2DArrayMethod1()
    free2DArrayMethod1(arr2D, row);

    printf("++++++++++++ %d x %d Matrix using method2 +++++++++++\n", row, col);

    int **arr2D1 = assign2DArrayMethod2(row, col);

    initialize2DArrayAndPrint(arr2D1, row, col);

    // Memory allocated using assign2DArrayMethod2() 
    // can freed using standard free
    free(arr2D1);

    return 0;
}
