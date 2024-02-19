#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
  element data;
  struct DlistNode *llink;
  struct DlistNode *rlink;
} DlistNode;

void init(DlistNode *phead) {
  phead->llink = phead;
  phead->rlink = phead;
}

void dinsert_node(DlistNode *before, DlistNode *new_node) {
  new_node->llink = before;
  new_node->rlink = before->rlink;
  before->rlink->llink = new_node;
  before->rlink = new_node;
}

void dinsert_first_node(DlistNode *head, DlistNode *new_node) {
  dinsert_node(head, new_node);
}

void dinsert_last_node(DlistNode *a, DlistNode *new_node) {

  DlistNode *temp = a;

  while ((a)->rlink != (temp)) {
    a = (a)->rlink;
  }

  dinsert_node(a, new_node);

  a = (a)->rlink;
}

void print(DlistNode **start) {
  int count = 0;
  DlistNode *temp = *start;
  *start = (*start)->rlink;

  while (*start != temp) {
    printf("%d : %d\n", count++, (*start)->data);
    *start = (*start)->rlink;
  }
  printf("\n");
}

int main(void) {
  DlistNode *a = (DlistNode *)malloc(sizeof(DlistNode));
  init(a);
  print(&a);

  DlistNode *a1 = (DlistNode *)malloc(sizeof(DlistNode));
  a1->data = 10;
  dinsert_node(a, a1);
  print(&a); // 1

  DlistNode *a2 = (DlistNode *)malloc(sizeof(DlistNode));
  a2->data = 20;
  dinsert_node(a1, a2);
  print(&a); // 2

  DlistNode *a3 = (DlistNode *)malloc(sizeof(DlistNode));
  a3->data = 30;
  dinsert_node(a2, a3);
  print(&a); // 3

  DlistNode *a4 = (DlistNode *)malloc(sizeof(DlistNode));
  a4->data = 40;
  dinsert_first_node(a, a4);
  print(&a); // 4

  DlistNode *a5 = (DlistNode *)malloc(sizeof(DlistNode));
  a5->data = 50;
  dinsert_last_node(a, a5);
  print(&a); // 5

  DlistNode *a6 = (DlistNode *)malloc(sizeof(DlistNode));
  a6->data = 60;
  dinsert_last_node(a, a6);
  print(&a); // 6

  DlistNode *a7 = (DlistNode *)malloc(sizeof(DlistNode));
  a7->data = 70;
  dinsert_first_node(a, a7);
  print(&a); // 7

  DlistNode *a8 = (DlistNode *)malloc(sizeof(DlistNode));
  a8->data = 80;
  dinsert_last_node(a, a8);
  print(&a); // 8

  return 0;
}