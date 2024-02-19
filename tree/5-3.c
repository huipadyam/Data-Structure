#include <stdio.h>

//왼쪽자식인 left, 오른쪽자식인 right, 부모인 parent와 값인 data를 갖는
//구조체 TreeNode 선언
typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right, *parent;
} TreeNode;

//    G
//  C   F
// A B D E
// 위 모양대로 tree를 만든다.(data, left, right 초기화)
TreeNode n1 = {'A', NULL, NULL, NULL};
TreeNode n2 = {'B', NULL, NULL, NULL};
TreeNode n3 = {'C', &n1, &n2, NULL};
TreeNode n4 = {'D', NULL, NULL, NULL};
TreeNode n5 = {'E', NULL, NULL, NULL};
TreeNode n6 = {'F', &n4, &n5, NULL};
TreeNode n7 = {'G', &n3, &n6, NULL};

// root node 구조체를 가리키는 exp1
TreeNode *exp1 = &n7;

// 인자로 받은 node의 predecessor를 찾는다.
TreeNode *tree_predecessor(TreeNode *p) {
  if (p->left != NULL) { // 왼쪽 자식이 있는 경우
    TreeNode *q = p->left; // 왼쪽 자식 노드를 가리키는 포인터 q
    while (q->right != NULL) //q의 오른자식이 NULL이 될 때까지
      q = q->right; // q를 q의 오른자식으로 바꿔준다.
    return q; // q를 리턴한다.
    } // p의 왼쪽 subtree의 rightmost node 리턴

  // 왼쪽 자식이 없는 노드일 경우
  // 부모노드를 가리키는 포인터 r 선언
  TreeNode *r = p->parent;

  // r이 null이 되거나 p가 r의 왼쪽 자식이 될 때까지
  while (r != NULL && p == r->left) {
    p = r; // p를 r로 바꿔주고
    r = r->parent; // r을 r의 부모노드로 바꿔준다.
  }
  return r;// r을 리턴한다.
}

void main() {
  // q는 root node를 가리킨다.
  TreeNode *q = exp1;

  //위 구조대로 node들의 parent 초기화
  n1.parent = &n3;
  n2.parent = &n3;
  n3.parent = &n7;
  n4.parent = &n6;
  n5.parent = &n6;
  n6.parent = &n7;
  n7.parent = NULL;
  
  // Go to the rightmost node
  while (q->right)
    q = q->right;

  do {
    printf("%c\n", q->data); // Output data
    q = tree_predecessor(q); // Call the predecessor
  } while (q); // If not null
}