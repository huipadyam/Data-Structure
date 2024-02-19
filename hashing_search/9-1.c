// 강의자료에서 제가 수정한 부분에만 주석으로 설명 달았습니다!

#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct element {
  char key[KEY_SIZE];
} element;
typedef struct ListNode {
  element item;
  struct ListNode *link;
} ListNode;
ListNode *hash_table[TABLE_SIZE];
// Transform the string key into an integer by summing ASCII codes
int transform(char *key) {
  int number = 0;
  while (*key)
    number += *key++;
  return number;
}
// Division function ( key mod TABLE_SIZE )
int hash_function(char *key) { return transform(key) % TABLE_SIZE; }

#define equal(e1, e2) (!strcmp(e1.key, e2.key))
void hash_chain_add(element item, ListNode *ht[]) {
  int hash_value = hash_function(item.key);
  ListNode *ptr;
  ListNode *node_before = '\0';
  ListNode *node = ht[hash_value];
  for (; node; node_before = node, node = node->link) {
    if (equal(node->item, item)) {
      printf("Duplicate search key\n");
      return;
    }
  }
  ptr = (ListNode *)malloc(sizeof(ListNode));
  ptr->item = item;
  ptr->link = '\0';
  if (node_before)
    node_before->link = ptr;
  else
    ht[hash_value] = ptr;
}
void hash_chain_search(element item, ListNode *ht[]) {
  ListNode *node;
  int hash_value = hash_function(item.key);
  for (node = ht[hash_value]; node; node = node->link) {
    if (equal(node->item, item)) {
      printf("Search success\n");
      return;
    }
  }
  printf("Search failed\n");
}

void hash_chain_print(ListNode *ht[]) {
  ListNode *node;
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]", i);
    for (node = ht[i]; node; node = node->link)
      printf(" -> %s", node->item.key);
    printf(" -> null\n");
  }
}
void init_table(ListNode *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    ht[i] = '\0'; // each node is initialized as null
}

// hash table에서 element가 item인 node를 삭제하고 item의 key를 리턴
// item이 hash table에 없으면 NULL 리턴
char *hash_chain_delete(element item, ListNode *ht[]) {
  int hash_value = hash_function(item.key); // 인자로 받은 item의 hash table index 저장
  ListNode *node_before = '\0'; // 이전 node를 저장해 놓을 변수
  ListNode *node = ht[hash_value]; // 인자로 받은 item에 해당하는 hash table list 저장
  for (; node; node_before = node, node = node->link) { // hast table list 끝까지 이동하면서 반복
    if (equal(node->item, item)) { // 인자로 받은 item과 hash table list의 item이 같은 경우
      if (ht[hash_value] == node) { // 그 item이 hash tabe list의 첫번째 node일 경우
        ht[hash_value] = ht[hash_value]->link; // hash table list의 첫번째 node를 그 다음 node로 변경
        free(node); // hast table list에 있던 node에 할당되어있던 공간 해제
      } else { // 그 item이 hash tabe list의 첫번째 node가 아닐 경우
        node_before->link = node->link; // 그 item의 전 node의 link를 다음 node로 변경
        free(node); // hast table list에 있던 node에 할당되어있던 공간 해제
      }
      return item.key; // 인자로 받은 item의 key 리턴
    }
  }
  return '\0'; // hash table에 인자로 받은 item이 없을 때 실행, NULL 리턴
}
void main() {
  element tmp;
  int op;
  init_table(hash_table);
  while (1) {
    printf("Enter the operation to do (0: insert, 1: delete, 2: search, 3: "
           "termination): ");// 문제에 주어진 대로 delete를 1번 operation으로 추가
    scanf("%d", &op);
    if (op == 3)
      break;
    printf("Enter the search key: ");
    scanf("%s", tmp.key, sizeof(tmp.key));
    if (op == 0)
      hash_chain_add(tmp, hash_table);
    else if (op == 1) // 문제에 주어진 대로 delete를 1번 operation으로 추가
      hash_chain_delete(tmp, hash_table);
    else if (op == 2)
      hash_chain_search(tmp, hash_table);
    hash_chain_print(hash_table);
    printf("\n");
  }
}