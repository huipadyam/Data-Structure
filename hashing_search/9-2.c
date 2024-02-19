#include <stdio.h>
typedef struct TreeNode {
  int key;
  struct TreeNode *left, *right;
} TreeNode; // TreeNode 구조체는 int형 key와 자기참조 left, right를 갖는다.

// 범위가 [0,n]인 랜덤 정수를 리턴한다.
int random(int n) { return rand() % (n + 1); }

// Insert the key into the binary search tree.
// 메인함수에서 중복되는 key를 거르기 때문에 이는 고려할 필요 없다.
void insert_node(TreeNode **root, int key) {
  TreeNode *p, *t; // p: parent node, t: current node
  TreeNode *n;     // n: new node to be inserted
  t = *root; // current node를 root node로 설정
  p = NULL; // root node의 parent는 NULL
  // Search first
  while (t != NULL) { // terminal node에 도달할 때까지
    p = t; // current node를 parent node로 만들어줌
    if (key < t->key) // 주어진 key가 parent node key보다 작을경우 
      t = t->left; // parent의 left child를 current로 만들어줌
    else // 주어진 key가 parent node key보다 클 경우(같은 경우는 발생x)
      t = t->right; // parent의 right child를 current로 만들어줌
  }

  n = (TreeNode *)malloc(sizeof(TreeNode)); // 삽입할 node 메모리 공간 할당
  if (n == NULL) // 메모리 할당이 제대로 되지 않은 경우
    return; // 함수 종료
  n->key = key; // 삽입할 node에 인자로 받은 key 넣어줌
  n->left = n->right = NULL; // 삽입할 node는 terminal node이므로 자식이 NULL
  if (p != NULL) // 삽입 전 tree에 node가 있었을 경우 
    if (key < p->key) // 인자로 받은 key가 parent key보다 작은 경우
      p->left = n; // parent의 왼쪽 노드로 삽입
    else // 인자로 받은 key가 parent key보다 큰 경우
      p->right = n; // parent의 오른쪽 노드로 삽입
  else // 삽입 전 tree가 빈 tree였을 경우
    *root = n; // root node로 삽입
}

// inorder : left -> current -> right 순으로 traversal
void inorder(TreeNode *t) {
  if (t != NULL) { // t가 terminal이면 바로 함수 종료
    inorder(t->left); // 왼쪽 자식 traversal
    printf("%5d ", t->key); // 현재 node key 출력
    inorder(t->right); // 오른쪽 자식 traversal
  }
}

// 크기가 size인 배열 A에 값이 n인 원소가 있으면 1을, 없으면 0을 리턴
int is_exist(int n, int *A, int size) {
  int count = 0; // 값이 n인 원소 개수 세는 변수 count
  for (int i = 0; i < size; i++) { // 배열 size만큼 반복
    if (A[i] == n) { // i번째 원소가 n이면
      count++; // count 증가시키고 
      return count; // count 값 리턴
    }
  }
  return count; // if문이 실행되지 않은 경우 실행, count = 0 리턴
}

int main(void) {
  int input_size = 1000; // tree node 개수는 1,000개
  int data_maxval = 10000; // tree node 값 범위는 0~10,000
  
  // output: sorted result
  // input array역할을 할 pointer에 메모리 할당
  int *input = (int *)malloc(sizeof(int) * input_size);

  // Binary search tree에 메모리 할당
  TreeNode **root = (TreeNode **)malloc(sizeof(TreeNode *));
  
  for (int i = 0; i < input_size; i++) { // 배열 size 만큼 반복
    int val = random(data_maxval);  // Generate an input data randomly
    while (is_exist(val, input, input_size)) // 중복되는 인풋은 거른다.
      val = random(data_maxval);
    input[i] = val; // 중복 없이 생성한 인풋을 인풋 배열에 넣는다.
    // printf("insert %3d\n", input[i]);
    insert_node(root, input[i]); // 인풋 배열의 원소를 tree에 넣는다.
  }
  inorder(*root); // tree를 inorder traversal하며 결과 출력
  // 왼쪽 -> 자신 -> 오른쪽 순으로 값이 커지므로 inorder traversal을 해야함
  // &root라고 하면 안됨!
  return 0;
}
