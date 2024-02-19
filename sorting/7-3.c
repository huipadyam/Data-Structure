#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// 각 digit의 표현 범위
#define BUCKETS 64 

// 각각의 data를 이루는 digit의 개수
#define DIGITS 4 

// data의 개수
#define N 1000 

// D[N] : 0~63
// C[BUCKETS] : 0~1000
// B[N+1] : 0~2^24 -1
// A[N] : 0~2^24 -1

Counting_Sort(int D[], int A[]){

  // B에 정렬 결과 저장
  // B배열 크기는 1000보다 1 커야 함(1~1000번째 자리를 사용할 것이므로)
  int B[N+1] = {0}; 

  // C에 pdf와 cdf 저장
  int C[BUCKETS] = {0}; 

  // C에 pdf 저장
  for (int j = 0 ; j < N ; j ++){
    C[D[j]] += 1;
  }

  // C에 cdf 저장 (C의 값을 누적해서 더한다.) 
  // 이 때 C 배열 원소들의 범위가 0~999가 아니라 0~1000까지 가능해짐
  // 이는 곧 B 배열의 1000번째 인덱스도 접근 가능함을 의미함.
  // 따라서 B 배열의 크기는 1001로 정한다.
  for (int i = 1 ; i < BUCKETS ; i ++){
    C[i] += C[i - 1]; 
  }

  // A 배열의 값을 B 배열로 옮긴다.(counting sort 알고리즘에 따라서) 
  // B의 "C의 "D의 j번째 원소(A[j]의 기준 digit)"번째 원소" 번째 원소에 A[j] 넣는다. 
  // j = 1이 아니라 j = 0까지 반복해야 함(N번 반복해야 하므로)
  // 만약 C[D[j]]가 0이면 값이 없으니 실행되지 않으니 걱정할 필요 없다.
  for (int j = N-1 ; j >= 0 ; j --){
    B[C[D[j]]] = A[j];
    C[D[j]] -= 1;
  }

  // 원래 배열인 A에 B의 값을 다시 넣는다. (인덱스를 고려한다.)
  for (int j = 0 ; j < N ; j ++){
    A[j] = B[j+1]; // B의 인덱스를 고려하여 A에 다시 넣기
  }
}


void radix_sort(int list[]) {
  int factor = 1; // factor는 처음에 1로 시작한다.
  
  int D[N] = {0}; // 기준 digit들을 저장할 배열

  for (int d = 0 ; d < DIGITS ; d ++){ // digit 개수만큼 반복
    for(int i = 0 ; i < N ; i ++){ // data 개수만큼 반복
      D[i] = (list[i]/factor) % BUCKETS; // 기준 digit을 D에 저장한다.
    }
    Counting_Sort(D,list); // 기준 digit에 따라 list를 stable하게 정렬한다.
    factor *= BUCKETS; // 다음 digit으로 넘어가기 위해 factor에 BUCKETS 곱한다.
  } 
}

int main(void) { 
  
  // N개의 data를 저장할 배열
  int list [N] = {0}; 

  // 랜덤 함수의 seed를 계속 변화시킨다.
  srand(time(NULL)); 

  // list 배열에 0 ~ (2^24)-1 범위의 값을 랜덤으로 할당한다. 
  for(int i = 0 ; i < N ; i ++){
    list [i] = (int)rand() % (int)pow(2,24);
  }

  // list를 radix sort한다.
  radix_sort(list);

  // list의 N개 data를 차례로 출력한다.
  for(int i = 0 ; i < N ; i ++){
    printf("list[%3d] = %8d\n",i,list[i]);
  }

  // list가 제대로 정렬되었는지 확인한다.
  for(int i = 0 ; i < N - 1 ; i ++){
    if(list[i]>list[i+1])
      printf("%d error\n\n", i);
  }
  
  return 0; 
}