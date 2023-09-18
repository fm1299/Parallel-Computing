#include <iostream>
#include <chrono>
#include <cstring>
#define MAX 1000
using namespace std;
using namespace std::chrono;
void first_pair(double A[][MAX],double* x,double*y)
{
    /*First pair of loops*/
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];
}
void second_pair(double A[][MAX],double* x,double*y)
{
    /*second pair of loops*/
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j]*x[j];
}
double A[MAX][MAX], x[MAX], y[MAX];
int main()
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            A[i][j] = j*2;
        }
    }
    for (int i=0;i<MAX;i++)
    {
        x[i] = i+1;
    }
    memset(y, 0, sizeof(y));

    auto start = high_resolution_clock::now();
    first_pair(A,x,y);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by first pair of loops: "
         << duration.count() << " microseconds" << endl;
    memset(y, 0, sizeof(y));

    start = high_resolution_clock::now();
    second_pair(A,x,y);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by second pair of loops: "
         << duration.count() << " microseconds" << endl;
}