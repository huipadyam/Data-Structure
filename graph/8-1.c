#include <math.h>
#include <stdio.h>

// increases A[i] to key
void increase_key_min_heap(int A[], int i, int key) {
  if (key <= A[i]) { // key를 증가시킬 것이므로 key가 원래보다 작거나 같으면
                     // 오류메시지 출력 후 종료
    printf("new key is not larger than current key.");
    return;
  }

  A[i] = key; // 배열의 i번째 원소의 key를 key로 변경

  i *= 2; // i번째와 i/2번째 원소로 연산할 것이므로 i에 미리 2를 곱해준다.

  while (i <= A[0] && A[i / 2] > A[i]) {
    // A[0]에는 heap size가 저장되어있다.(heap 인덱스는 1부터 시작함에 주의하자)
    // i가 heap의 마지막 원소의 index를 벗어나거나 부모가 자식보다 작거나
    // 같아지면(min heap property 만족하면) 반복 종료
    int tmp = A[i]; // 자식노드(A[i])와 부모노드(A[i/2])를 교환한다.
    A[i] = A[i / 2];
    A[i / 2] = tmp;

    i *= 2; // 한 단계 내려가서 또 수행하기 위해 i를 자식의 index로 바꿔준다.
  }
}

// decreases A[i] to key
void decrease_key_min_heap(int A[], int i, int key) {
  if (key >= A[i]) { // key를 감소시킬 것이므로 key가 원래보다 크거나 같으면
                     // 오류메시지 출력 후 종료
    printf("new key is not smaller than current key.");
    return;
  }

  A[i] = key; // 배열의 i번째 원소의 key를 key로 변경

  while (i > 1 &&
         A[i / 2] > A[i]) { // i가 root의 index가 되거나 부모가 자식보다 작거나
                            // 같아지면(min heap property 만족하면) 반복 종료
    int tmp = A[i]; // 자식노드(A[i])와 부모노드(A[i/2])를 교환한다.
    A[i] = A[i / 2];
    A[i / 2] = tmp;

    i /= 2; // 한 단계 올라가서 또 수행하기 위해 i를 부모의 index로 바꿔준다.
  }
  return;
}

void print(int *A) { // heap의 원소들을 인덱스와 함께 차례로 출력
  for (int i = 1; i <= A[0]; i++)
    printf("i = %2d  %2d\n", i, A[i]);
  printf("\n\n");
}

int main(void) {
  int A[] = {10, 1, 4, 2, 7, 5, 3, 3, 7, 8, 9}; // 주어진 값으로 heap 초기화

  print(A);                        // heap 출력
  increase_key_min_heap(A, 3, 10); // heap의 인덱스 3의 값을 10으로 증가시킨다.
  print(A);                        // heap 출력
  decrease_key_min_heap(A, 4, 3); // heap의 인덱스 4의 값을 3으로 감소시킨다.
  print(A);                       // heap 출력

  return 0;
}