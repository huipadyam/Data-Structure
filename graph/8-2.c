#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct element {
  int num; // array에서의 index 역할을 하는 변수(0~MAX_VERTICES-1)
  int key;
} element; // element 구조체는 int형 key를 포함한다.

typedef struct {
  element *heap;
  int heap_size;
} HeapType; // HeapType 구조체는 element 포인터 heap과 int형 heap_size를
            // 포함한다.

#define MAX_VERTICES 8

// 값의 형식을 통일하기 위해 long형이 아닌 int형으로 바꾸었습니다.
#define INF 100000000

int weight[MAX_VERTICES][MAX_VERTICES] = {
    {0, 3, INF, INF, INF, INF, INF, 14}, {3, 0, 8, INF, INF, INF, INF, 10},
    {INF, 8, 0, 15, 2, INF, INF, INF},   {INF, INF, 15, 0, INF, INF, INF, INF},
    {INF, INF, 2, INF, 0, 9, 4, 5},      {INF, INF, INF, INF, 9, 0, INF, INF},
    {INF, INF, INF, INF, 4, INF, 0, 6},  {14, 10, INF, INF, 5, INF, 6, 0}};

// #define MAX_VERTICES 7

// // 값의 형식을 통일하기 위해 long형이 아닌 int형으로 바꾸었습니다.
// #define INF 100000000
// int weight[MAX_VERTICES][MAX_VERTICES] = {
//     {0, 29, INF, INF, INF, 10, INF}, {29, 0, 16, INF, INF, INF, 15},
//     {INF, 16, 0, 12, INF, INF, INF}, {INF, INF, 12, 0, 22, INF, 18},
//     {INF, INF, INF, 22, 0, 27, 25},  {10, INF, INF, INF, 27, 0, INF},
//     {INF, 15, INF, 18, 25, INF, 0}};

int selected[MAX_VERTICES]; // heap에서 나왔으면 1, 그렇지 않으면 0을 저장
int parent[MAX_VERTICES] = {0}; // 각 vertex의 parent의 index 저장
// parent가 없으면 0 저장(처음에 parent를 link로 정의했으므로 0이 될 일이 없다.)
int child[MAX_VERTICES][MAX_VERTICES] = {0};
// i번째 vertex의 child가 j번째 vertex이면 child[i][j] = 1

// Delete the root at heap h, (# of elements: heap_size)
// delete_min_heap은 지난 과제에서 주어졌던 코드를 조금 변형해서 구현했습니다.
// 그래서 변형한 부분에만 설명 작성했습니다.
element delete_min_heap(HeapType *h) {
  int parent, child;
  element item, temp;

  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size) {
    // Find a smaller child node
    if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
      child++; //두 자식 중 key가 더 작은 자식의 index를 child변수에 저장
    if (temp.key <= h->heap[child].key)
      break; // min heap property(부모 key가 자식 key보다 작거나 같음)를
             // 만족하면 종료한다.
    // Move down one level
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

// build_min_heap은 지난 과제에서 작성했던 코드를 조금 변형해서 구현했습니다.
// 그래서 변형한 부분만 설명 변경했습니다.
void build_min_heap(HeapType *h) {

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
          (h->heap[child].key) >
              h->heap[child + 1].key) //오른자식이 왼자식보다 작으면
        child++; //자식을 오른자식으로 바꿔준다.
      if (h->heap[child].key >= temp.key) // min heap property를 만족하면
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

// decreases A[i] to key
// decrease_key_min_heap은 이번 과제 1번문제에서 작성했던 코드를 조금 변형해서
// 구현했습니다. 그래서 변형한 부분만 설명 변경했습니다.
void decrease_key_min_heap(HeapType *h, int i, int key) {
  if (key >= (h->heap[i].key)) {
    printf("new key is not smaller than current key.");
    // key를 감소시킬 것이므로 key가 원래보다 크거나 같으면 오류메시지 출력 후
    // 종료
    return;
  }

  h->heap[i].key = key; // heap의 i번째 원소의 key를 key로 변경

  while (i > 1 && h->heap[i / 2].key > h->heap[i].key) {
    // i가 root의 index가 되거나 부모가 자식보다 작거나 같아지면(min heap
    // property 만족하면) 반복 종료
    element tmp =
        h->heap[i]; // 자식노드(h->heap[i])와 부모노드(h->heap[i/2])를 교환한다.
    h->heap[i] = h->heap[i / 2];
    h->heap[i / 2] = tmp;

    i /= 2; // 한 단계 올라가서 또 수행하기 위해 i를 부모의 index로 바꿔준다.
  }
  return;
}

// n: the number of vertices on the graph
void prim(int s, int n) {
  int i, u, v;

  HeapType *h = (HeapType *)malloc(
      sizeof(HeapType)); // dist 배열을 대신할 heap 메모리공간 할당
  h->heap = (element *)malloc(sizeof(element) * n +
                              1); // heap의 element 배열 메모리공간 할당
  h->heap_size = n; // heap size는 인자로 전달받은 n = MAX_VERTICES로 초기화

  for (u = 0; u < n; u++) {
    h->heap[u + 1].key = INF; // heap의 모든 원소들 값(dist)을 INF로 초기화
    h->heap[u + 1].num =
        u; // num은 heap의 모든 원소들의 인덱스 역할. 0~(n-1)값으로 초기화.
    selected[u] =
        FALSE; // 모든 vertex들은 queue에서 꺼내지지 않았으므로 false로 초기화
  }
  h->heap[s + 1].key = 0; // start vertex의 dist를 0으로 설정

  build_min_heap(h); // 지금까지 설정한 dist 값으로 min heap을 생성한다.
  for (i = 0; i < n; i++) {
    element uel = delete_min_heap(h); // min heap의 최솟값 vertex를 꺼낸다.
    u = uel.num;      // 꺼내진 vertex의 index를 저장해둔다.
    printf("%d ", u); // 꺼내진 vertex의 index를 출력한다.
    selected[u] =
        TRUE; // u번째 vertex가 꺼내졌으므로 selected를 1로 표시해둔다.
    if (uel.key ==
        INF) { // 이때 꺼내진 vertex의 key(dist)가 INF이면 연결되어있지 않은
               // 것이므로 오류메시지를 출력하고 종료한다.
      printf("error\n");
      return;
    }

    for (v = 0; v < n; v++) {
      int j = 0;
      if (weight[u][v] !=
          INF) { // u와 v 사이 weight가 INF이면 연결되지 않은 것이므로 거른다.
        // u에 이웃한 v들만을 살펴볼 것이기 때문이다.
        for (j = 0; j < n; j++) {
          if (h->heap[j + 1].num == v) { // index가 v인 heap의 인덱스를 찾는다.
            //(heap operation들을 통해 heap의 순서가 뒤바뀌었으므로)
            break;
          }
        }
        if (!selected[v] && weight[u][v] < h->heap[j + 1].key) {
          // u와 이웃한 vertex인 v들 중에서 queue에서 빠져나오지 않았고, u와의
          // 거리가 start vertex와의 거리보다 짧은 v를 고른다.
          decrease_key_min_heap(h, j + 1, weight[u][v]);
          // 아까 구한 인덱스 (j+1)번째 heap의 key를 u와의 거리로 변경(더
          // 짧으니까)
          parent[v] = u; // v와 u가 연결되었으므로 v의 부모에 u의 인덱스 저장
        }
      }
    }
  }
  printf("\n\n");
}
void preorder(int i) {
  int count = 0;
  for (int j = 0; j < MAX_VERTICES; j++) {
    if (child[i][j] == 1) // i번째 행에 값이 1인 원소가 있으면 count 증가시킴
      count++;
  }
  if (count ==
      0) // i번째 행에 값이 1인 원소가 없다 -> i번째 원소는 child가 없다는 뜻
    return; // 더이상 child가 없으므로 함수를 종료하고 리턴한다.

  for (int j = 0; j < MAX_VERTICES; j++) {
    if (child[i][j] == 1) { // i번째 원소들의 자식을 하나하나 방문한다.
      printf("vertex %d -> %d      edge : %d\n", i, j,
             weight[i][j]); //자기 자신(i)을 먼저 출력한 후
      preorder(j); //자식인 j를 재귀적을 호출한다.(preorder이므로)
    }
  }
}
void print_prim(int s) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      // parent 1차원 배열만으로는 1대다 관계를 표현할수 없으므로
      // 2차원 배열 child에 부모자식 관계를 표시한다.
      if (i == parent[j] &&
          j != s) // 이때 j가 start node이면 부모가 없어야 하므로 제외한다.
        child[i][j] =
            1; // i-j에 부모-자식 관계가 성립하는 경우 child[i][j]를 1로 표시
    }
  }
  preorder(s); // start node를 인자로 주어 preorder traversal을 하며 출력한다.
}
int main() {
  prim(0, MAX_VERTICES); // 주어진 input graph의 prim 순서를 출력한다.
  print_prim(
      0); // 주어진 input graph의 부모 자식 관계와 edge weight를 출력한다.
  return 0;
}
