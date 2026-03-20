#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));

  if (result->matrix == NULL) return INCORRECT_MATRIX;

  int error = 0;
  for (int i = 0; i < rows && !error; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      error = 1;
      for (int j = 0; j < i; j++) free(result->matrix[j]);
      free(result->matrix);
      result->matrix = NULL;
      return INCORRECT_MATRIX;
    }
  }

  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_is_correct(matrix_t *A) {
  return (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0)
             ? OK
             : INCORRECT_MATRIX;
}

int s21_is_square(matrix_t *A) {
  if (s21_is_correct(A) != OK) return INCORRECT_MATRIX;
  return (A->rows == A->columns) ? OK : CALC_ERROR;
}

int s21_are_equal_size(matrix_t *A, matrix_t *B) {
  if (s21_is_correct(A) != OK || s21_is_correct(B) != OK) return FAILURE;
  return (A->rows == B->rows && A->columns == B->columns) ? SUCCESS : FAILURE;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_is_correct(A) != OK || s21_is_correct(B) != OK) return FAILURE;
  if (!s21_are_equal_size(A, B)) return FAILURE;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_correct(A) != OK || s21_is_correct(B) != OK)
    return INCORRECT_MATRIX;
  if (!s21_are_equal_size(A, B)) return CALC_ERROR;

  int code = s21_create_matrix(A->rows, A->columns, result);
  if (code != OK) return code;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_correct(A) != OK || s21_is_correct(B) != OK)
    return INCORRECT_MATRIX;
  if (!s21_are_equal_size(A, B)) return CALC_ERROR;

  int code = s21_create_matrix(A->rows, A->columns, result);
  if (code != OK) return code;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_is_correct(A) != OK) return INCORRECT_MATRIX;

  int code = s21_create_matrix(A->rows, A->columns, result);
  if (code != OK) return code;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_correct(A) != OK || s21_is_correct(B) != OK)
    return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERROR;

  int code = s21_create_matrix(A->rows, B->columns, result);
  if (code != OK) return code;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_is_correct(A) != OK) return INCORRECT_MATRIX;

  int code = s21_create_matrix(A->columns, A->rows, result);
  if (code != OK) return code;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}

void s21_get_minor(matrix_t *A, matrix_t *minor, int row, int col) {
  int minor_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    int minor_j = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;
      minor->matrix[minor_i][minor_j] = A->matrix[i][j];
      minor_j++;
    }
    minor_i++;
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_is_correct(A) != OK) return INCORRECT_MATRIX;
  if (s21_is_square(A) != OK) return CALC_ERROR;

  int code = s21_create_matrix(A->rows, A->columns, result);
  if (code != OK) return code;

  if (A->rows == 1) {
    result->matrix[0][0] = 1;
    return OK;
  }

  matrix_t minor;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      s21_get_minor(A, &minor, i, j);

      double det = 0;
      s21_determinant(&minor, &det);

      result->matrix[i][j] = det * pow(-1, i + j);

      s21_remove_matrix(&minor);
    }
  }

  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_correct(A) != OK) return INCORRECT_MATRIX;
  if (s21_is_square(A) != OK) return CALC_ERROR;

  *result = 0;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  }

  if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return OK;
  }

  double det = 0;
  matrix_t minor;

  for (int j = 0; j < A->columns; j++) {
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    s21_get_minor(A, &minor, 0, j);

    double minor_det = 0;
    s21_determinant(&minor, &minor_det);

    det += A->matrix[0][j] * pow(-1, j) * minor_det;

    s21_remove_matrix(&minor);
  }

  *result = det;
  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_is_correct(A) != OK) return INCORRECT_MATRIX;
  if (s21_is_square(A) != OK) return CALC_ERROR;

  double det = 0;
  int code = s21_determinant(A, &det);
  if (code != OK) return code;

  if (fabs(det) < EPSILON) return CALC_ERROR;

  if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1.0 / det;
    return OK;
  }

  matrix_t complements, transposed;
  code = s21_calc_complements(A, &complements);
  if (code != OK) return code;

  code = s21_transpose(&complements, &transposed);
  if (code != OK) {
    s21_remove_matrix(&complements);
    return code;
  }

  code = s21_mult_number(&transposed, 1.0 / det, result);

  s21_remove_matrix(&complements);
  s21_remove_matrix(&transposed);

  return code;
}