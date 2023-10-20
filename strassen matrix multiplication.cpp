#include <stdio.h>

void matrixAdd(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrixSubtract(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMultiply(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = n / 2;

    int A11[m][m], A12[m][m], A21[m][m], A22[m][m];
    int B11[m][m], B12[m][m], B21[m][m], B22[m][m];
    int C11[m][m], C12[m][m], C21[m][m], C22[m][m];
    int P1[m][m], P2[m][m], P3[m][m], P4[m][m], P5[m][m], P6[m][m], P7[m][m];
    int temp1[m][m], temp2[m][m];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    // Calculate the seven products (P1 to P7)
    matrixAdd(m, A11, A22, temp1);
    matrixAdd(m, B11, B22, temp2);
    strassenMultiply(m, temp1, temp2, P1);

    matrixAdd(m, A21, A22, temp1);
    strassenMultiply(m, temp1, B11, P2);

    matrixSubtract(m, B12, B22, temp1);
    strassenMultiply(m, A11, temp1, P3);

    matrixSubtract(m, B21, B11, temp1);
    strassenMultiply(m, A22, temp1, P4);

    matrixAdd(m, A11, A12, temp1);
    strassenMultiply(m, temp1, B22, P5);

    matrixSubtract(m, A21, A11, temp1);
    matrixAdd(m, B11, B12, temp2);
    strassenMultiply(m, temp1, temp2, P6);

    matrixSubtract(m, A12, A22, temp1);
    matrixAdd(m, B21, B22, temp2);
    strassenMultiply(m, temp1, temp2, P7);

    matrixAdd(m, P1, P4, temp1);
    matrixSubtract(m, temp1, P5, temp2);
    matrixAdd(m, temp2, P7, C11);

    matrixAdd(m, P3, P5, C12);

    matrixAdd(m, P2, P4, C21);

    matrixAdd(m, P1, P3, temp1);
    matrixSubtract(m, temp1, P2, temp2);
    matrixAdd(m, temp2, P6, C22);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    if (n <= 0 || (n & (n - 1)) != 0) {
        printf("Matrix size must be a positive power of 2.\n");
        return 1;
    }

    int A[n][n], B[n][n], C[n][n];

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassenMultiply(n, A, B, C);
    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

