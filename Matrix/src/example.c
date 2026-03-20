#include <stdio.h>

#include "s21_matrix.h"

void print_matrix(matrix_t *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      printf("%6.2f ", m->matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  printf("Пример использования библиотеки матриц\n\n");

  printf("1. Сложение матриц:\n");
  matrix_t A, B, C;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  printf("Матрица A:\n");
  print_matrix(&A);

  printf("\nМатрица B:\n");
  print_matrix(&B);

  s21_sum_matrix(&A, &B, &C);
  printf("\nA + B = C:\n");
  print_matrix(&C);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

  printf("\n2. Умножение матриц:\n");
  matrix_t D, E, F;

  s21_create_matrix(2, 3, &D);
  s21_create_matrix(3, 2, &E);

  D.matrix[0][0] = 1;
  D.matrix[0][1] = 2;
  D.matrix[0][2] = 3;
  D.matrix[1][0] = 4;
  D.matrix[1][1] = 5;
  D.matrix[1][2] = 6;

  E.matrix[0][0] = 7;
  E.matrix[0][1] = 8;
  E.matrix[1][0] = 9;
  E.matrix[1][1] = 10;
  E.matrix[2][0] = 11;
  E.matrix[2][1] = 12;

  printf("Матрица D (2x3):\n");
  print_matrix(&D);

  printf("\nМатрица E (3x2):\n");
  print_matrix(&E);

  s21_mult_matrix(&D, &E, &F);
  printf("\nD * E = F (2x2):\n");
  print_matrix(&F);

  s21_remove_matrix(&D);
  s21_remove_matrix(&E);
  s21_remove_matrix(&F);

  printf("\n3. Определитель и обратная матрица:\n");
  matrix_t G, inverse;
  double det;

  s21_create_matrix(3, 3, &G);

  G.matrix[0][0] = 2;
  G.matrix[0][1] = 5;
  G.matrix[0][2] = 7;
  G.matrix[1][0] = 6;
  G.matrix[1][1] = 3;
  G.matrix[1][2] = 4;
  G.matrix[2][0] = 5;
  G.matrix[2][1] = -2;
  G.matrix[2][2] = -3;

  printf("Матрица G:\n");
  print_matrix(&G);

  s21_determinant(&G, &det);
  printf("\nОпределитель матрицы G: %.2f\n", det);

  s21_inverse_matrix(&G, &inverse);
  printf("\nОбратная матрица G^(-1):\n");
  print_matrix(&inverse);

  matrix_t identity_check;
  s21_mult_matrix(&G, &inverse, &identity_check);
  printf("\nПроверка: G * G^(-1) (должна быть единичная матрица):\n");
  print_matrix(&identity_check);

  s21_remove_matrix(&G);
  s21_remove_matrix(&inverse);
  s21_remove_matrix(&identity_check);

  printf("\nПрограмма завершена\n");

  return 0;
}