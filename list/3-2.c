#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct ListNode {
  element data;
  struct ListNode *link;
} ListNode;

void insert_last(ListNode **phead, ListNode *new_node) {
  if (*phead == NULL) {
    new_node->link = NULL;
    *phead = new_node;
  } else {
    new_node->link = NULL;
    struct ListNode *last = *phead;
    while (last->link != NULL)
      last = last->link;
    last->link = new_node;
  }
}

void add_last(ListNode **phead, element val) {
  ListNode *p = (ListNode *)malloc(sizeof(ListNode));
  p->data = val;
  p->link = NULL;
  insert_last(phead, p);
}

ListNode **merge(ListNode *a, ListNode *b) {
  ListNode **c = (ListNode **)malloc(sizeof(ListNode *));
  *c = NULL;

  while ((a) != NULL && (b) != NULL) {
    if ((a->data) < (b->data)) {
      add_last(c, (a)->data);
      (a) = (a)->link; //(**a)로 바꾼다면?
    } else if ((a)->data == (b)->data) {
      add_last(c, (a)->data);
      add_last(c, (a)->data);
      (a) = (a)->link;
      (b) = (b)->link;
    } else {
      add_last(c, (b)->data);
      (b) = (b)->link;
    }
  }

  for (; (a) != NULL; (a) = (a)->link) {
    add_last(c, (a)->data);
  }
  for (; (b) != NULL; (b) = (b)->link) {
    add_last(c, (b)->data);
  }

  return c;
}

void print(ListNode *a) {
  int count = 0;
  while ((a) != NULL) {
    printf("%d : %2d\n", count++, (a)->data);
    (a) = (a)->link;
  }
  printf("\n\n");
}

int main(void) {

  // ppt 숫자대로 a 채우기
  ListNode **a;
  a = (ListNode **)malloc(sizeof(ListNode *));
  *a = NULL;

  add_last(a, 1);
  add_last(a, 2);
  add_last(a, 5);
  add_last(a, 10);
  add_last(a, 15);
  add_last(a, 20);
  add_last(a, 25);
  print(*a);

  // ppt 숫자대로 b 채우기
  ListNode **b;
  b = (ListNode **)malloc(sizeof(ListNode *));
  *b = NULL;

  add_last(b, 3);
  add_last(b, 7);
  add_last(b, 8);
  add_last(b, 15);
  add_last(b, 18);
  add_last(b, 30);
  print(*b);

  // a와 b를 merge 해서 c에 저장
  ListNode **c = merge(*a, *b);
  print(*c);

  // d의 data 개수 m을 입력받아서 m개의 원소를 오름차순으로 0~99의 값으로 채우기
  ListNode **d;
  d = (ListNode **)malloc(sizeof(ListNode *));
  *d = NULL;
  int m;
  printf("m값을 입력하세요(1~20) : ");
  scanf("%d", &m);
  srand(time(NULL));
  int temp = rand() % 100;
  for (int i = 0; i < m; i++) {
    add_last(d, temp);
    temp += rand() % (100 - temp);
  }
  print(*d);

  // e의 data 개수 n을 입력받아서 n개의 원소를 오름차순으로 0~99의 값으로 채우기
  ListNode **e;
  e = (ListNode **)malloc(sizeof(ListNode *));
  *e = NULL;
  int n;
  printf("n값을 입력하세요(1~20) : ");
  scanf("%d", &n);
  srand(time(NULL));
  temp = rand() % 100;
  for (int i = 0; i < n; i++) {
    add_last(e, temp);
    temp += rand() % (100 - temp);
  }
  print(*e);

  // d와 e를 merge 해서 f에 저장
  ListNode **f = merge(*d, *e);
  print(*f);

  return 0;
}