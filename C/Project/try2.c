#include <stdio.h>

static int M;
static int N;

void printMatrix(float matrix[M][N])
{
    for (int i = 0; i < M ; i++)
    {
        printf("\n");
            for (int j = 0; j < N ; j++)
                printf("%1.f ", matrix[i][j]);
    } 
    printf("\n\n");
}

void changeRows(float matrix[M][N], int target, int source){
    int array[N*2];
    for (int i = 0, j = N; i < N; i++, j++)
    {
        array[i] = matrix[target][i];
        array[j] = matrix[source][i];
    }
    for (int i = 0, j = N; i < N; i++, j++)
    {
        matrix[source][i] = array[i];
        matrix[target][i] = array[j];
    }
}

void makePivot(float matrix[M][N], int row){
    float pivotValue = matrix[row][row];
    if (pivotValue == 0.0){
        int nRow = row;
        while(matrix[nRow][row] == 0) nRow++;
        changeRows(matrix, nRow, row);
    }
    pivotValue = matrix[row][row];
    for (int i = row; i < N; i++)
        matrix[row][i] /= pivotValue;

    
}

void createMatrix(float matrix[M][N])
{
    int i, j, count = 0;
    float value;
    for (i = 0; i < M; i++)    
        for (j = 0; j < N; j++)
        {
            printf("Enter %d.Value: ", count);
            scanf("%f", &value);
            matrix[i][j] = value;
            count++;
        }
}

void makeZero(float matrix[M][N], int row, int col, int src)
{
    if (matrix[row][col] != 0)
    {
        float zeroValue = matrix[row][col];
        for (int i = 0; i < N; i++)
            matrix[row][i] += -1 * matrix[src][i] * zeroValue;
    }
}

void calculateMatrix(float matrix[M][N]){
    createMatrix(matrix); 
    if (M == N-1)
    {
        //First Row
        makePivot(matrix, 0);
        makeZero(matrix, 1, 0, 0);
        makeZero(matrix, 2, 0, 0);

        //Second Row
        makePivot(matrix, 1);
        makeZero(matrix, 2, 1, 1);
        makePivot(matrix, 2);
        makeZero(matrix, 1, 2, 2);
        makeZero(matrix, 0, 2, 2);
        makeZero(matrix, 0, 1, 1);
    }
}

int main()
{
    M = 3, N = 4;
    float matrix[M][N];
    calculateMatrix(matrix);
    printMatrix(matrix);
}