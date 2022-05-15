#include "takuzu.h"
int **startgrid(int mask[][8],int solution[][8], int size)
{
    int **grid;
    grid = (int **) malloc(8 * sizeof(int*));
    for(int k = 0; k < size;k++)
    {
        grid[k] = malloc(8*sizeof (int));
    }
    for(int i = 1; i<9; i++)
    {
        for(int j = 1; j<9;j++)
        {
            if(mask[i][j] == 1)
            {
                grid[i][j] = solution[i][j];
            }
        }
    }

    return grid;
}

int **move(int **grid, int size)
{
    int **ar;
    ar = (int**) malloc(size *sizeof(int*));
    for(int k = 0; k < size; k++)
    {
        ar = malloc(size *sizeof(int));
    }
    ar = grid;
    int nb_lig, nb_cols, val;
    char nb_col;
    printf("Enter on which line and which column you want to play :\n");
    scanf(" %d %c", &nb_lig, &nb_col);
    nb_cols = nb_lig - 'A';

    printf("Which value would you like to put ? (0 or 1):\n");
    scanf(" %d", &val);

    ar[nb_lig][nb_cols] = val;
}

/*function that check if there is more than two 1 or 0 in a row on a line or on a column
 grid : temporary array where has been added the value entered by the user
 */
int rowandcol(int** grid, int row, int col, int val)
{
    if(testcol(grid, row, col, val) == 0)
    {
        if(testrow(grid,row,col,val) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }

}



int testrow(int** grid, int row, int col, int val)
{
    if(row ==1)
    {
        if ((grid[row + 1][col] == val) && (grid[row + 2][col] == val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (row == 2)
    {
        if ((grid[row + 1][col] == val) && (grid[row + 2][col] == val))
        {
            return 1;
        }
        else if((grid[row - 1][col] == val) && (grid[row + 1][col] == val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(row >= 3 && row <= 6)
    {
        if ((grid[row + 1][col] == val) && (grid[row + 2][col] == val))
        {
            return 1;
        }
        else if((grid[row - 1][col] == val) && (grid[row + 1][col] == val))
        {
            return 1;
        }
        else if((grid[row - 1][col] == val) && (grid[row - 2][col] == val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (row == 7)
    {
        if ((grid[row - 1][col] == val) && (grid[row - 2][col] == val))
        {
            return 1;
        }
        else if((grid[row - 1][col] == val) && (grid[row + 1][col] == val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(row ==8)
    {
        if ((grid[row - 1][col] == val) && (grid[row - 2][col] == val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}


int testcol(int** grid, int row, int col, int val)
{
    if(col >=3 && col <= 6)
    {
        if(grid[row][col +1]==val)
        {
            if(grid[row][col+2] == val)
            {
                return 1;
            }
            else if(grid[row][col - 1] == val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(grid[row][col - 1] == val)
        {
            if(grid[row][col -2] == val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else if(col == 2)
    {
        if(grid[row][col +1]==val)
        {
            if(grid[row][col+2] == val)
            {
                return 1;
            }
            else if(grid[row][col - 1] == val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

    }
    else if(col == 7)
    {
        if(grid[row][col -1]==val)
        {
            if(grid[row][col-2] == val)
            {
                return 1;
            }
            else if(grid[row][col +1] == val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }

    }
    else if(col == 1)
    {
        if(grid[row][col +1] == val)
        {
            if(grid[row][col+2] == val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if(col == 8)
    {
        if(grid[row][col -1] == val)
        {
            if(grid[row][col-2] == val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }


}

int errornbrow(int** grid, int row, int size)
{
    int tmp[size][size], tmp2[size][size], false = 0, bool = 0;
    while(bool != 8 && false == 0 )
    {
        for(int i =1; i < size; i++)
        {
            for(int j = 1; j <size; j++)
            {
            tmp[i - 1][j - 1] = grid[i][j];
            tmp2[i - 1][j-1] = grid[i][j];
            }
        }
        for(int k = 0; k < size; k++)
        {
            if(bool != row)
            {

                tmp[bool][k] = tmp2[row][k];
                if (comparray(tmp, tmp2, size) == 0) {
                    false = 1;
                }
            }
        }
        bool++;
    }
    return false;
}

int comparray(int a[][8], int b[][8], int size)
{
    int same = 0;
    for(int i = 0; i <size; i++)
    {
        for(int j = 0; j<size; j++)
        {
            if(a[i][j] != b[i][j])
            {
                same = 1;
            }
        }
    }
    return same;
}





