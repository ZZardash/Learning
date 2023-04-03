
//  Created by Macbook Air on 20.10.2022.

#include <stdio.h>
static int M;
static int N;


void printMatrix(float matrix[M][N])
{
    for (int i = 0; i < M ; i++)
    {
        printf("\n");
            for (int j = 0; j < N ; j++)
                printf("%.1f ", matrix[i][j]);
    } 
    printf("\n\n");
}

void createMatrix(float matrix[M][N])
{
    int i, j;
    int count = 0;
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
    for (int i = 0; i < N; i++)
        matrix[row][i] /= pivotValue;
}

void groundRowUp(float matrix[M][N], int row, int src){
    float zeroValue = matrix[row][N-1];
    for (int i = 0; i < N; i++)
        matrix[row][i] += -1 * matrix[src][N-1] * zeroValue;
}

void groundRow(float matrix[M][N], int row, int src){
    float zeroValue = matrix[row][row-1];
    for (int i = 0; i < N; i++)
        matrix[row][i] += -1 * matrix[src][i] * zeroValue;
}
void calculateVariables(float matrix[M][N]){
    makePivot(matrix, 0);
    printMatrix(matrix);
    groundRow(matrix, 1, 0);
    printMatrix(matrix);
    groundRow(matrix, 2, 0);
    printMatrix(matrix);
    makePivot(matrix, 1);
    printMatrix(matrix);
    groundRow(matrix, 2, 1);
    printMatrix(matrix);
    makePivot(matrix, 2);
    printMatrix(matrix);
    groundRowUp(matrix, 1, 2);
    printMatrix(matrix);
}

int main(){
    //Creating Matrix
    M = 3;
    N = 3; 
    float matrix[M][N];
    createMatrix(matrix);
    calculateVariables(matrix);
    
    return 0;
}


