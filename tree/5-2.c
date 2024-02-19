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

// 인자로 받은 node의 successor를 찾는다.
TreeNode *tree_successor(TreeNode *p) {
  if (p->right != NULL) {   //오른쪽 자식이 있는 노드일 경우
    TreeNode *q = p->right; //오른쪽 자식을 가리키는 node q 선언
    while (q->left != NULL) // q의 왼쪽자식이 null이 될 때까지
      q = q->left;          // q를 q의 왼쪽 자식으로 바꿔준다.
    return q;               // q를 리턴한다.
  }                         // p의 오른쪽 subtree의 leftmost node 리턴

  // 오른쪽 자식이 없는 노드일 경우
  // 부모노드를 가리키는 포인터 r 선언
  TreeNode *r = p->parent;

  // r이 null이 되거나 p가 r의 오른쪽 자식이 될 때까지
  while (r != NULL && p == r->right) {
    p = r;         // p를 r로 바꿔주고
    r = r->parent; // r을 r의 부모노드로 바꿔준다.
  }
  return r; // r을 리턴한다.
}
int main(void) {
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

  // Go to the leftmost node
  while (q->left)
    q = q->left;

  do {
    printf("%c\n", q->data); // Output data
    q = tree_successor(q);   // Call the successor
  } while (q);               // If not null
}
