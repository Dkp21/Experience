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

int **assign2DArrayMethod1(int row, int col)
{
    int **arr2D = (int **)malloc(sizeof(int *)*row);

    for(int i = 0; i < row; ++i)
    {
        arr2D[i] = (int *)malloc(sizeof(int)*col);
    }

    return arr2D;
}


int main(int argc, char ** argv)
{
    int **arr2D = assign2DArrayMethod1(ROW, COL);

    for(int i = 0; i < ROW; ++i)
    {
        for(int j = 0; j < COL; ++j)
        {
            arr2D[i][j] = i + j;

            printf("%d ", arr2D[i][j]);
        }

        printf("\n");
    }

    return 0;
}
