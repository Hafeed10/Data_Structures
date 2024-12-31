#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10])
{
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[10][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int r1, int c1, int matrix1[10][10],
                      int r2, int c2, int matrix2[10][10],
                      int result[10][10])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;
    int matrix1[10][10], matrix2[10][10], result[10][10];

    // Input dimensions for the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if matrix multiplication is possible
    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible. Columns of the first matrix must equal rows of the second matrix.\n"); 
        return 0;
    }

    // Input matrices
    inputMatrix(r1, c1, matrix1);
    inputMatrix(r2, c2, matrix2);

    // Multiply matrices
    multiplyMatrices(r1, c1, matrix1, r2, c2, matrix2, result);

    // Print the result
    printf("Resultant matrix after multiplication:\n");
    printMatrix(r1, c2, result);

    return 0;
}
