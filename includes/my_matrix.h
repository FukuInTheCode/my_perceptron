#pragma once
#define MYMATRIXH

typedef struct my_Matrix {
    unsigned int m;
    unsigned int n;
    double **arr;
} my_Matrix;

typedef double (*UnaryFunction)(double);

void my_Matrix_Create(unsigned int m, unsigned int n, const unsigned int count, ...);
void my_Matrix_Identity(const unsigned int count, ...);
void my_Matrix_Set(my_Matrix* A, unsigned int x, unsigned int y, double n);
void my_Matrix_Print(const unsigned int count, ...);
void my_Matrix_Free(const unsigned int count, ...);
void my_Matrix_MultiplyByScalar(my_Matrix* A, double scalar, my_Matrix* result);
void my_Matrix_Add(my_Matrix* result, const unsigned int count, ...);
void my_Matrix_T(my_Matrix* A, my_Matrix* T);
void my_Matrix_GetColumn(my_Matrix* A, unsigned int n, double result[]);
double* my_Matrix_GetRow(my_Matrix* A, unsigned int i);
void my_Matrix_Product(my_Matrix* result, const unsigned int count, ...);
void my_Matrix_Copy(my_Matrix* A, my_Matrix* copy);
void my_Matrix_PowerInt(my_Matrix* A, const unsigned int n, my_Matrix* result);
void my_Matrix_RandInt(int minN, int maxN, const unsigned int count, ...);
void my_Matrix_RandFloat(double minN, double maxN, const unsigned int count, ...);
double my_Matrix_Det(my_Matrix *A);
void my_Matrix_GetSubMatrix(my_Matrix *A, const unsigned int m, const unsigned int n, my_Matrix *result);
void my_Matrix_Adjugate(my_Matrix *A, my_Matrix *result);
void my_Matrix_Inverse(my_Matrix *A, my_Matrix *result);
void my_Matrix_AddScalar(my_Matrix* A, double scalar, my_Matrix* result);
void my_Matrix_ApplyFunc(my_Matrix *A, UnaryFunction func, my_Matrix *result);