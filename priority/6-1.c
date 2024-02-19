// heapsort.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define MAX_ELEMENT 2000

typedef struct element {
  int key;
} element; // element 구조체는 int형 key를 포함한다.

typedef struct {
  element *heap;
  int heap_size;
} HeapType; // HeapType 구조체는 element 포인터 heap과 int형 heap_size를
            // 포함한다.

// Integer random number generation function between 0 and n-1
int randomNum(int n) { return rand() % n; }

// Initialization (set heap size as 0)
void init(HeapType *h) { h->heap_size = 0; }

// Insert the item at heap h, (# of elements: heap_size)
void insert_max_heap(HeapType *h, element item) {
  int i;
  i = ++(h->heap_size); // i에 # of elements를 대입한 다음 # of elements를 1
                        // 증가시킨다.

  // The process of comparing with the parent node as it traverses the tree
  while ((i != 1) && (item.key > h->heap[i / 2].key)) {
    // i가 1이 되거나 주어진 item이 parent node보다 작거나 같으면 종료
    h->heap[i] = h->heap[i / 2]; // i번째 노드의 부모 노드를 i번째 노드에 대입
    i /= 2; // i에 i/2를 대입해서 i번째 노드의 부모 노드로 이동한다.
  }
  h->heap[i] = item; // Insert new node
}

// heap의 중간 계산과정을 확인하기 위해 제가 만든 함수입니다. heap을 tree
// 모양으로 출력합니다. 단 각 행의 맨 앞에 공백문자는 편의상 넣지 않았습니다.
void print_heap(HeapType *h) {
  int j = 1; // j는 각 줄의 맨 오른쪽 node의 번호
  for (int i = 1; i <= h->heap_size; i++) { // heap size만큼 반복
    printf("%04d\t", h->heap[i].key); // heap의 key를 하나씩 출력한다.
    if (i == 2 * j - 1) { // 한 줄의 출력이 끝나면(같은 높이에 있는 노드들의
                          // 출력이 끝나면)
      j *= 2;       // 다음 줄의 맨 오른쪽 node로 값 변경
      printf("\n"); //줄바꿈문자 출력
    }
  }
  printf("\n\n\n"); // 출력이 모두 끝난 후 줄바꿈문자 출력
}

// Delete the root at heap h, (# of elements: heap_size)
element delete_max_heap(HeapType *h) {
  int parent, child;
  element item, temp;

  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size) {
    // Find a smaller child node
    if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
      child++;
    if (temp.key >= h->heap[child].key)
      break;
    // Move down one level
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

void build_max_heap(HeapType *h) {

  int n = h->heap_size;              // n에 heap size 저장
  for (int i = n / 2; i >= 1; i--) { // n/2번째 node부터 1번째 node까지 반복
    int parent, child;
    element item, temp;

    temp = h->heap[i]; // i번째 node 구조체를 temp에 저장해둠
    parent = i;        // i를 부모로,
    child = 2 * i;     // 2*i는 왼쪽자식으로 저장하고 반복 시작
    while (child <= h->heap_size) { // child가 heap size보다 커지면 반복 종료
      // Find a smaller child node
      // heap[child + 1]이 null이면 key는 0임 -> 고려할 필요x
      if ((child < h->heap_size) && //자식이 마지막 node이면 다음노드인
                                    //오른자식으로 바꿔줄필요x
          (h->heap[child].key) <
              h->heap[child + 1].key) //오른자식이 왼자식보다 크면
        child++; //자식을 오른자식으로 바꿔준다.
      if (h->heap[child].key <= temp.key) // heap property를 만족하면
        break;                            //반복 종료
      // Move down one level
      h->heap[parent] = h->heap[child]; // (주의)swap 대신 한 칸씩 위로 올리기
      parent = child;                   // 한 칸씩 위로 올리기
      child *= 2; // 자식에 2를 곱해서 한 칸씩 내려가서 반복
    }
    h->heap[parent] =
        temp; //한 칸씩 위로 올려서 생긴 빈칸에 아까 저장해둔 i번째 노드 삽입
  }
}

// input: heap 'h'
// output: sorted element array 'a'
void heap_sort(HeapType *h, element *a, int n) {
  int i;

  build_max_heap(h);
  for (i = (n - 1); i >= 0; i--) {
    a[i] = delete_max_heap(h);
  }
}

int check_sort_results(element *output, int n) {
  int index = 1;
  for (int i = 0; i < n - 1; i++)
    if (output[i].key > output[i + 1].key) {
      index = 0;
      break;
    }
  return index;
}

void main() {

  // 코드 실행시간 측정
  clock_t start, finish;
  double duration;
  start = clock();

  time_t t1;
  // Intializes random number generator
  srand((unsigned)time(&t1));

  int input_size = 10; // 10, 100, 1000
  int data_maxval = 10000;

  HeapType *h1 = (HeapType *)malloc(sizeof(HeapType));
  // 'heap' is allocated according to 'input_size'.  heap starts with 1, so
  // 'input_size+1' is used.
  h1->heap = (element *)malloc(sizeof(element) * (input_size + 1));

  // output: sorted result
  element *output = (element *)malloc(sizeof(element) * input_size);

  // Generate an input data randomly
  for (int i = 0; i < input_size; i++)
    h1->heap[i + 1].key = randomNum(data_maxval); // note) heap starts with 1.
  h1->heap_size = input_size;

  if (input_size < 20) {
    printf("Input data\n");
    for (int i = 0; i < input_size; i++)
      printf("%d\n", h1->heap[i + 1].key);
    printf("\n");
  }

  // Perform the heap sort
  heap_sort(h1, output, input_size);

  if (input_size < 20) {
    printf("Sorted data\n");
    for (int i = 0; i < input_size; i++)
      printf("%d\n", output[i].key);
    printf("\n");
  }

  // Your code should pass the following function (returning 1)
  if (check_sort_results(output, input_size))
    printf("Sorting result is correct.\n");
  else
    printf("Sorting result is wrong.\n");

  // 코드 실행시간 측정
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  printf("%f seconds.\n", duration);
}