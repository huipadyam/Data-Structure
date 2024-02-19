// selection_sort.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct data {
  int *id;
  int *score;
} data;

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(data *list, int n) {
  int i, j, least, temp;
  for (i = 0; i < n - 1; i++) {
    least = i;
    for (j = i + 1; j < n; j++)
      if (list->score[j] < list->score[least])
        least = j;
    SWAP(list->score[i], list->score[least], temp);
    SWAP(list->id[i], list->id[least], temp);
  }
}

void selection_sort_stable(data *list, int n) {

  for (int i = 0; i < n - 1; i++) { // i = 0 ~ (n-2)까지 반복

    // i번째부터 n-1번째까지의 값 중 최솟값의 인덱스를 min에 저장
    int min = i;
    for (int j = i + 1; j < n; j++) { // j = (i+1) ~ (n - 1)까지 반복
      if (list->score[j] <
          list->score[min]) { // j번째 값이 min번째 값보다 작으면
        min = j;              // 최솟값의 인덱스를 j로 변경
      }
    }

    // 최솟값의 점수와 id를 저장해 둔다.
    int scr = list->score[min]; // scr에 점수 최솟값 저장
    int d = list->id[min];      // d에 최솟값인 점수의 id 저장

    // i ~ ( min - 1 ) 번째 데이터를 모두 오른쪽으로 한 칸씩 이동시킴
    for (int j = min - 1; j >= i; j--) { // j = (min - 1)부터 i까지 반복
      list->score[j + 1] =
          list->score[j]; // j번째 점수를 j + 1번째로 한칸씩 뒤로 이동
      list->id[j + 1] =
          list->id[j]; // j번째 점수의 id도 함께 j + 1번째로 한칸씩 뒤로 이동
    }

    // 빈 i번째 자리에 i ~ (n - 1)번째 값 중 최솟값(min번째 값)을 넣는다.
    list->score[i] = scr;
    list->id[i] = d;
  }
}

int main() {
  int data_id[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int data_score[] = {30, 25, 10, 20, 80, 30, 25, 10};

  int in_size = 8;
  data *input = (data *)malloc(sizeof(data));

  input->id = data_id;
  input->score = data_score;

  // Print out the input data
  printf("Input data\n");
  for (int i = 0; i < in_size; i++)
    printf("%d\t %d\n", input->id[i], input->score[i]);
  printf("\n");

  // Produce the stable sorting results by replacing 'selection_sort' with
  // 'selection_sort_stable'.
  selection_sort_stable(input, in_size);

  // Print out the sorted data
  printf("Sorted data\n");
  for (int i = 0; i < in_size; i++)
    printf("%d\t %d\n", input->id[i], input->score[i]);
  printf("\n");

  return 0;
}
