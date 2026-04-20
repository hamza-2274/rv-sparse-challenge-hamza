#include <stdio.h>


void sparse_multiply(const float* dense_A, int M, int N, const float* x, 
                     float* values, int* col_idx, int* row_ptr, float* y) {
    
    int nnz = 0; // nu of non -zero elm
    row_ptr = 0;

//scan and extract
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            float val = dense_A[i * N + j];
            
            if (val != 0.0f) {
                values[nnz] = val;
                col_idx[nnz] = j;
                nnz++;
            }
        }
        row_ptr[i + 1] = nnz;
    }

    // compu y = A * x using the CSR data..
    for (int i = 0; i < M; i++) {
        float sum = 0.0f;
        int start = row_ptr[i];
        int end = row_ptr[i + 1];

        for (int k = start; k < end; k++) {
            sum += values[k] * x[col_idx[k]];
        }
        y[i] = sum;
    }
}