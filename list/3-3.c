#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct ListNode {
  element data;
  struct ListNode *link;
} ListNode;

typedef struct {
  ListNode *head; // Head pointer
  ListNode *tail; // Tail pointer
  int length;     // # of nodes
} ListType;

ListType list1;

void init(ListType *L) {
  L->head = NULL;
  L->tail = NULL;
  L->length = 0;
}

int is_empty(ListType *list) {
  if (list->head == NULL && list->tail == NULL)
    return 1;
  else
    return 0;
}

int get_length(ListType *list) { return list->length; }

// Return node pointer of ‘pos’ in the list.
ListNode *get_node_at(ListType *list, int pos) {
  int i;
  ListNode *tmp_node = list->head;
  if (pos < 0)
    return NULL;
  for (i = 0; i < pos; i++)
    tmp_node = tmp_node->link;
  return tmp_node;
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
  if (*phead == NULL) {
    new_node->link = NULL;
    *phead = new_node;
  } else {
    if (p == NULL) {
      printf("The preceding node cannot be NULL.\n");
      exit(1);
    } else {
      new_node->link = p->link;
      p->link = new_node;
    }
  }
}

// Insert new data at the ‘position’e
void add(ListType *list, int position, element data) {
  ListNode *p;
  if ((position >= 0) && (position <= list->length)) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL) {
      // error("Memory allocation error");
      printf("Memory allocation error");
      exit(1);
    }
    node->data = data;
    p = get_node_at(list, position - 1);
    insert_node(&(list->head), p, node);
    list->length++;
  }
}

void add_first(ListType *list, element data) {
  if (list->head == NULL) {
    ListNode *L = (ListNode *)malloc(sizeof(ListNode));
    L->data = data;
    L->link = NULL;
    list->head = L;
    list->tail = L;
    list->length = 1;
  } else {
    ListNode *L = (ListNode *)malloc(sizeof(ListNode));
    L->data = data;
    L->link = list->head;
    list->head = L;
    (list->length)++;
  }
}

void add_last(ListType *list, element data) {
  add(list, list->length, data);
  list->tail = get_node_at(list, (list->length)-1);
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
  if (*phead == NULL) {
    printf("The list is blank.\n");
  } else {
    if (p == NULL)
      printf("The preceding node cannot be NULL.\n");
    else {
      p->link = removed->link;
      free(removed);
    }
  }
}

// delete a data at the ‘pos’ in the list
void delete (ListType *list, int pos) {
  if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
    ListNode *p = get_node_at(list, pos - 1);
    ListNode *removed = get_node_at(list, pos);
    remove_node(&(list->head), p, removed);
    list->length--;
  }
}

void delete_first(ListType *list) {

  if ((list->head) == NULL) {
    printf("The list is blank.\n");
  } else {


    
      ListNode * temp = list->head;
      list->head = list->head->link;
      free(temp);
      list->length--;

  }
}

void delete_last(ListType *list) { 
  delete (list, list->length - 1); 
  list->tail = get_node_at(list, (list->length)-1);
  }

// Return the data at the ‘pos’.
element get_entry(ListType *list, int pos) {
  ListNode *p;
  if (pos >= list->length) {
    printf("Position error");
    exit(1);
  }
  p = get_node_at(list, pos);
  return p->data;
}

// Display data in the buffer.
void display(ListType *list) {
  int i;
  ListNode *node = list->head;
  printf("( ");
  for (i = 0; i < list->length; i++) {
    printf("%d ", node->data);
    node = node->link;
  }
  printf(" )\n");
}

// Find a node whose data = item
int is_in_list(ListType *list, element item) {
  ListNode *p;
  p = list->head;
  while ((p != NULL)) {
    if (p->data == item)
      break;
    p = p->link;
  }
  if (p == NULL)
    return FALSE;
  else
    return TRUE;
}

int main(void) {
  
  ListType list1;
  init(&list1);
  add_first(&list1, 20);
  add_last(&list1, 30);
  add_first(&list1, 10);
  add_last(&list1, 40);
  add(&list1, 2, 70);
  display(&list1);
  
  delete (&list1, 2);
  delete_first(&list1);
  delete_last(&list1);
  display(&list1);
  
  printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
  printf("%d\n", get_entry(&list1, 0));
}