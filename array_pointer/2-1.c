#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define MAX_TERMS 10
#define MAX_RC 20

typedef struct {
  int row;
  int col;
  int value;
} element;

typedef struct {
  element data[MAX_TERMS];
  int rows;
  int cols;
  int terms;
} SparseMatrix;

void initMatrix(SparseMatrix *B) {
  (*B).rows = 6;
  (*B).cols = 6;
  (*B).terms = 7;

  (*B).data[0].row = 0;
  (*B).data[0].col = 3;
  (*B).data[0].value = 7;

  (*B).data[1].row = 1;
  (*B).data[1].col = 0;
  (*B).data[1].value = 9;

  (*B).data[2].row = 1;
  (*B).data[2].col = 5;
  (*B).data[2].value = 8;

  (*B).data[3].row = 3;
  (*B).data[3].col = 0;
  (*B).data[3].value = 6;

  (*B).data[4].row = 3;
  (*B).data[4].col = 1;
  (*B).data[4].value = 5;

  (*B).data[5].row = 4;
  (*B).data[5].col = 5;
  (*B).data[5].value = 1;

  (*B).data[6].row = 5;
  (*B).data[6].col = 2;
  (*B).data[6].value = 2;
}

void initRMatrix(SparseMatrix *B) {
  srand((unsigned)time(NULL));

  (*B).rows = (rand() % (MAX_RC)) + 1;
  (*B).cols = (rand() % (MAX_RC)) + 1;
  (*B).terms = (rand() % (MAX_TERMS)) + 1;

  for (int i = 0; i < (*B).terms; i++) {
    (*B).data[i].row = (rand() % (*B).rows);
    (*B).data[i].col = (rand() % (*B).cols);
    (*B).data[i].value = (rand() % (MAX_RC)) + 1;
  }
}

void transposeMatrix(SparseMatrix *B) {
  for (int i = 0; i < (*B).terms - 1; i++) {
    element *min = &((*B).data[i]);

    for (int j = i + 1; j < (*B).terms; j++) {
      if ((*B).data[j].col < (*min).col) {
        min = &((*B).data[j]);
      }
    }

    if (min == &((*B).data[i]))
      continue;

    int tpR = (*B).data[i].row;
    int tpC = (*B).data[i].col;
    int tpV = (*B).data[i].value;

    (*B).data[i].row = (*min).row;
    (*B).data[i].col = (*min).col;
    (*B).data[i].value = (*min).value;

    (*min).row = tpR;
    (*min).col = tpC;
    (*min).value = tpV;
  }

  for (int i = 0; i < (*B).terms; i++) {
    int temp = (*B).data[i].row;
    (*B).data[i].row = (*B).data[i].col;
    (*B).data[i].col = temp;
  }

  int swap = (*B).rows;
  (*B).rows = (*B).cols;
  (*B).cols = swap;
}

void printMatrix(SparseMatrix *B) {

  int ar[MAX_RC][MAX_RC] = {0};

  for (int i = 0; i < (*B).terms; i++) {
    ar[(*B).data[i].row][(*B).data[i].col] = (*B).data[i].value;
  }
  printf("    ");
  for (int j = 0; j < (*B).cols; j++)
    printf("%3d", j);
  printf("\n\n");
  for (int i = 0; i < (*B).rows; i++) {
    printf("%2d   ", i);
    for (int j = 0; j < (*B).cols; j++) {
      printf("%2d ", ar[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

int main(void) {

  SparseMatrix B;
  initMatrix(&B);
  printMatrix(&B);

  transposeMatrix(&B);
  printMatrix(&B);

  initRMatrix(&B);
  printMatrix(&B);

  transposeMatrix(&B);
  printMatrix(&B);

  return 0;
}