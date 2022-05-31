
// C++ program to find adjoint and inverse of a matrix
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
#define N 25

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int A[N][N], int n)
{
    int D = 0;
    if (n == 1) { return A[0][0]; }
    int temp[N][N];
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}
 
void adjoint(int A[N][N],int adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    int sign = 1, temp[N][N];
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            getCofactor(A, temp, i, j, N);
 
            sign = ((i+j)%2==0)? 1: -1;
 
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

bool inverse(int A[N][N], float inverse[N][N])
{
    int det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
 
    int adj[N][N];
    adjoint(A, adj);
 
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            inverse[i][j] = adj[i][j]/float(det);}}

    return true;
}

template<class T>
void display(T A[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}
 
int main()
{
    int A[N][N] = { 0 };
    for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++) {
			A[i][j]= rand() % 100;
		}
    }
    float inv[N][N];
    cout << "Input matrix is :\n";
    display(A);
    cout << "\n1 thread"
    opm_set_num_threads(1);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;
   
    cout << "\n2 threads"
    opm_set_num_threads(2);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;

    cout << "\n3 threads"
    opm_set_num_threads(3);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;

    cout << "\n4 threads"
    opm_set_num_threads(4);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;

    cout << "\n5 threads"
    opm_set_num_threads(5);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;

    cout << "\n6 threads"
    opm_set_num_threads(6);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;

    cout << "\n7 threads"
    opm_set_num_threads(7);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;

    cout << "\n8 threads"
    opm_set_num_threads(8);
    double start = opm_get_wtime();
    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);
    double end = omp_get_wtime();
    double time = end - start;
    cout << "\nOmp Time:" << time << endl;
    return 0;

}
