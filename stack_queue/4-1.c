// linked_stack.cpp : Defines the entry point for the console application.
//

//#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct DlistNode {
  element data;
  struct DlistNode *llink;
  struct DlistNode *rlink;
} DlistNode;

typedef struct {
  DlistNode *top;
} LinkedStackType;

void init(LinkedStackType *s) {
  s->top = NULL;
} //스택을 빈 스택으로 초기화한다.

int is_empty(LinkedStackType *s) { return (s->top == NULL); }
//스택이 비어있다면 1을 그렇지 않다면 0을 리턴한다.

void push(LinkedStackType *s, element item) {
  DlistNode *temp = (DlistNode *)malloc(sizeof(DlistNode));
  // temp에 DlistNode크기의 메모리를 할당한다.
  if (temp == NULL) { //메모리 할당이 되지 않았을 경우
    fprintf(stderr, "Memory allocation error\n"); //오류 메시지를 출력하고
    return;                                       //종료한다.
  } else {
    if (s->top == NULL) { //빈 stack에 push하는 경우
      temp->llink = temp; // doubly linked stack이므로 llink와 rlink 모두
      temp->rlink = temp; //자기자신을 가리킨다.
    } else {              // stack에 이미 node가 있는 경우
      s->top->rlink->llink = temp;
      // stack의 원래 top node의 오른쪽 node의 llink가 temp를 가리키게 함
      temp->rlink = s->top->rlink;
      // temp의 rlink가 stack의 원래 top node rlink를 가리키게 함
      s->top->rlink = temp;
      // stack의 원래 top node의 rlink가 temp를 가리키게 함
      temp->llink = s->top;
      // temp의 llink가 stack의 원래 top node를 가리키게 함
    }
    temp->data = item;
    // item을 temp의 data에 넣어줌
    s->top = temp;
    // stack의 top node를 temp로 변경함
  }
}

element pop(LinkedStackType *s) {
  if (is_empty(s)) {                     //스택이 비었을 경우
    fprintf(stderr, "Stack is empty\n"); //오류 메시지를 출력하고
    exit(1);                             //종료한다.
  } else {                               //스택이 비어있지 않을 경우
    DlistNode *temp = s->top; //원래 top node를 temp에 저장해둠
    int item = temp->data;    //원래 top node의 data를 item에 저장해둠

    if (s->top->llink == s->top && s->top->rlink == s->top) {
      // stack의 node가 하나일 경우(pop 수행 이후 빈 stack이 됨)
      s->top = NULL; // top이 null을 가리키게 함
    } else {
      // stack의 node가 두 개 이상일 경우(pop 수행 이후에도 빈 stack이 되지x)
      s->top->llink->rlink = s->top->rlink;
      // top node의 왼쪽 node의 rlink가 top node의 오른쪽 node를 가리키게 함
      s->top->rlink->llink = s->top->llink;
      // top node의 오른쪽 node의 llink가 top node의 왼쪽 node를 가리키게 함
      s->top = s->top->llink;
      // top node의 왼쪽 노드를 top node로 만들어줌
    }
    free(temp);  //원래 top node에 할당된 메모리를 해제함
    return item; //원래 top node의 data를 리턴함
  }
}

element peek(LinkedStackType *s) {
  if (is_empty(s)) {                     //스택이 비어있을 경우
    fprintf(stderr, "Stack is empty\n"); //오류 메시지를 출력하고
    exit(1);                             //종료한다
  } else {                               //스택이 비어있지 않을 경우
    return s->top->data; // node를 삭제하지 않고 top node의 data를 리턴함
  }
}

int main() {
  LinkedStackType s; //스택 구조체 선언
  init(&s);          //빈 스택으로 초기화
  push(&s, 1);       //스택에 1을 넣는다.
  push(&s, 2);       //스택에 2를 넣는다.
  push(&s, 3);       //스택에 3을 넣는다.

  printf("%d\n", pop(&s)); //스택에서 3을 꺼내고 리턴값을 출력한다.
  printf("%d\n", pop(&s)); //스택에서 2를 꺼내고 리턴값을 출력한다.
  printf("%d\n", pop(&s)); //스택에서 1을 꺼내고 리턴값을 출력한다.

  return 0; //프로그램 종료
}
