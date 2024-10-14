// Relations.h
#ifndef RELATIONS_H
#define RELATIONS_H
#define MAX_SET_ELEMENTS 10
#define MAX_CHAR_IN_NAME 10
#define MAX_DIMENSION_OF_ZERO_ONE_MATRIX 20

void ZeroOneRepresentation(int cardinalNo, int R[20][20],char Name[10]);
void Store(int cardinalNo, int A[], int R[20][20]);
void CopyMatrixAtoB(int size ,int A[20][20] , int B[20][20]);
int BooleanAddition (int a, int b);
int BooleanMultiplication (int a, int b);
void WarshallAlgorithm(int cardinalNo, int R[20][20], int Closure[20][20]);
void Union(int nA, int A[MAX_SET_ELEMENTS], int nB, int B[MAX_SET_ELEMENTS], int Result[2*MAX_SET_ELEMENTS] );
void Intersection(int nA, int A[MAX_SET_ELEMENTS], int nB, int B[MAX_SET_ELEMENTS], int Result[2 * MAX_SET_ELEMENTS]);
int belongsTo(int a ,int cardinalNo, int A[MAX_SET_ELEMENTS]);
int F(int n);
int P(int n , int r);
int C(int n , int r);
int S(int m, int n);
int B(int n);


#endif // MY_FUNCTIONS_H