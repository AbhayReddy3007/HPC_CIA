#include <iostream>
#include <omp.h>
#include <ctime>

void matrix_multiplication(int **A, int **B, int **C, int n, int num_threads) {
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int **A, **B, **C;
    int n;
    int m;
    std::cout << "Enter the number of threads (m): ";
    std::cin >> m;
    std::cout << "Enter the size n (nxn): ";
    std::cin >> n;
    
    const double BILLION = 1000000000.0;
    struct timespec start, end;

    // Set the number of OpenMP threads
    omp_set_num_threads(m);

    // Allocate memory for matrices A, B, and C
    A = new int*[n];
    B = new int*[n];
    C = new int*[n];
    for(int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    // Initialize matrices A and B
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    clock_gettime(CLOCK_REALTIME, &start);
    matrix_multiplication(A, B, C, n, m);
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate elapsed time
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;

    std::cout << "The elapsed time is " << time_spent << " seconds" << std::endl;

    // Free dynamically allocated memory
    for(int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}