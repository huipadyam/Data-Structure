
#1
void increase_key_min_heap(int A[], int i, int key)
int형 배열 A, int형 i, int형 key를 인자로 받아서 
A heap에서 i번째 원소의 값을 key로 증가시킨다.

void decrease_key_min_heap(int A[], int i, int key)
int형 배열 A, int형 i, int형 key를 인자로 받아서 
A heap에서 i번째 원소의 값을 key로 감소시킨다.

void print(int *A)
int형 포인터 A를 인자로 받아서
A heap의 1~heapSize 번째 원소를 차례로 출력한다.

int main(void)
강의자료에 주어진 값으로 heap을 초기화하고 heap의 key를 증감시키고 heap을 출력하여 결과를 확인한다.
성공적으로 실행되었다면 0을 리턴한다.


#2
element delete_min_heap(HeapType *h)
HeapType 포인터 h를 인자로 받아 heap의 root node(최솟값)를 리턴하고 
나머지 node들을 재정렬하여 min heap property를 유지하도록 한다.

void build_min_heap(HeapType *h)
HeapType 포인터 h를 인자로 받아 min heap property를 만족시키는 heap으로 변경한다.

void decrease_key_min_heap(HeapType *h, int i, int key)
HeapType 포인터 h, int형 i, int형 key를 인자로 받아서 
h heap에서 i번째 원소의 값을 key로 감소시킨다.

void prim(int s, int n)
int형 s와 int형 n을 인자로 받아 heap을 생성 및 초기화하고(heap size는 n) 
주어진 weight 값에 따라 start index를 s로 하여 heap property를 사용하여 prim 알고리즘을 실행하고 
그 결과 vertex들을 차례로 출력한다.
이때 부모자식 관계를 parent 배열에 저장한다.

void preorder(int i)
int형 i를 인자로 받아 heap의 부모자식 관계에 따라 preorder traversal로 출력한다.

void print_prim(int s)
1차원 parent 배열을 2차원 child 배열로 바꾸어 부모->자식 방향의 traversal이 가능하게 한 뒤
preorder(s)를 실행한다.(s는 start vertex의 index)

int main()
주어진 input graph에서 start vertex를 0으로 하고 graph size를 MAX_VERTICES로 하여
prim 함수를 실행하여 prim 순서를 출력한다.
print_prim함수를 실행하여 start vertex를 0으로 하고 
주어진 input graph의 부모 자식 관계와 edge weight를 출력한다.
성공적으로 실행되었다면 0을 리턴한다.
