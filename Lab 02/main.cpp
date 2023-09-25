#include <iostream>
#include <chrono>
#include <math.h>
using namespace std::chrono;
void create_matrix(int**& matrix, int rows, int columns)
{
    matrix = new int* [rows];
    for (int i = 0;i < rows;i++)
    {
        matrix[i] = new int[columns];
    }
}
void fill(int**& matrix, int rows, int columns, bool zero)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < columns;j++)
        {
            if(zero)
            {
                matrix[i][j] = 0;
            }
            else if(!zero)
            {
                matrix[i][j] = (i + 1) * (j + 1);
            }
        }
    }
}
void print(int**& matrix, int rows, int columns)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < columns;j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void blockMatrixMultiplication(int**& mat1, 
int**& mat2,int**& result, int size, int blockSize)
{
    for(int i=0; i<size; i+=blockSize)
        for(int j=0; j<size; j+=blockSize)
            for(int k=0; k<size; k+=blockSize)
                for(int x=i; x < std::min(i + blockSize, size); x++)
                    for(int y=j; y<std::min(j + blockSize, size); y++)
                        for(int z=k; z<std::min(k + blockSize, size); z++)
                            result[x][y] += mat1[x][z] * mat2[z][y];
}
void matrix_multiplication(int**& mat1, int**& mat2, 
int**& result, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0;k < size; k++)
            {
                result[i][j] += mat1[i][k]
                * mat2[k][j];
            }
        }
        
    }
}
int main()
{
    int rows = 500;
    int columns = 500;
    int** matrix1;
    create_matrix(matrix1, rows, columns);
    fill(matrix1, rows, columns, false);
    int** matrix2;
    create_matrix(matrix2, rows, columns);
    fill(matrix2, rows, columns, false);
    int** result;
    create_matrix(result, rows, columns);
    fill(result, rows, columns, true);
    int blockSize = round(sqrt(rows));
    
    //matrix_multiplication(matrix1,matrix2, result, rows);
    auto start = high_resolution_clock::now();
    blockMatrixMultiplication(matrix1, matrix2, result, rows, blockSize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: "
         << duration.count() << " microseconds" << std::endl;
    
    // print(result, rows, columns);
}