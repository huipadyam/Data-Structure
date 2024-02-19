#Question2
void insert_last(ListNode **phead, ListNode *new_node)
리스트의 헤드노드의 주소를 갖고있는 phead와 삽입할 노드의 주소 new_node를 인자로 받아
리스트 phead의 마지막에 삽입할 노드 new_node를 삽입합니다.

void add_last(ListNode **phead, element val)
리스트의 헤드노드의 주소를 갖고있는 phead와 삽입할 노드의 data인 val를 인자로 받아
리스트 phead의 마지막에 data가 val인 노드를 삽입합니다.

ListNode **merge(ListNode *a, ListNode *b)
오름차순으로 정렬된 두 리스트의 첫번째 노드의 주소 a, b를 인자로 받아
두 리스트를 오름차순으로 merge한 리스트의 헤드노드의 주소 c를 리턴합니다.

void print(ListNode *a)
리스트의 첫번째 노드의 주소 a를 인자로 받아
리스트의 모든 원소를 인덱스와 함께 출력합니다.

int main(void)
ppt 숫자대로 두 리스트 a와 b를 채워서 a와 b를 출력한 뒤, 
a와 b를 merge해서 c에 저장하고 c를 출력합니다.
이후 리스트 d, e의 node 개수 m, n을 입력받아
각각의 리스트에 m, n개의 원소(0~99범위의 무작위 값을 가짐)를 오름차순으로 채워서 d와 e를 출력한 뒤, 
d와 e를 merge해서 f에 저장하고 f를 출력합니다.



#Question3
void init(ListType *L)
ListType형 포인터 L을 인자로 받아 L을 빈 리스트로 초기화합니다.

int is_empty(ListType *list)
ListType형 포인터 list를 인자로 받아 list가 빈 리스트이면 1을, 그렇지 않으면 0을 리턴합니다.

int get_length(ListType *list)
ListType형 포인터 list를 인자로 받아 list의 길이를 리턴합니다.

ListNode *get_node_at(ListType *list, int pos)
ListType형 포인터 list와 int형 pos를 인자로 받아 list의 pos번째 노드의 주소를 리턴합니다.

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
ListNode형 이중 포인터 phead와 ListNode형 포인터 p, ListNode형 포인터 new_node를 인자로 받아 
phead가 가리키는 리스트의 p노드 다음에 new_node를 삽입합니다.

void add(ListType *list, int position, element data)
ListType형 포인터 list, int형 position, element형 data를 인자로 받아
data가 data인 node를 list의 position번째에 삽입합니다.

void add_first(ListType *list, element data)
ListType형 포인터 list, element형 data를 인자로 받아
data가 data인 node를 list의 첫번째에 삽입합니다.

void add_last(ListType *list, element data)
ListType형 포인터 list, element형 data를 인자로 받아
data가 data인 node를 list의 마지막에 삽입합니다.

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
ListNode형 이중 포인터 phead와 ListNode형 포인터 p, ListNode형 포인터 removed를 인자로 받아 
phead가 가리키는 리스트의 p노드 다음에 있는 removed를 삭제합니다.

void delete (ListType *list, int pos)
ListType형 포인터 list, int형 pos를 인자로 받아
list의 pos번째 node를 삭제합니다.

void delete_first(ListType *list)
ListType형 포인터 list를 인자로 받아
list의 첫번째 node를 삭제합니다.

void delete_last(ListType *list)
ListType형 포인터 list를 인자로 받아
list의 마지막 node를 삭제합니다.

element get_entry(ListType *list, int pos)
ListType형 포인터 list, int형 pos를 인자로 받아
list의 pos번째 node의 data를 리턴합니다.

void display(ListType *list)
ListType형 포인터 list를 인자로 받아 list의 모든 node의 data를 순서대로 괄호 안에 출력합니다.

int is_in_list(ListType *list, element item)
ListType형 포인터 list, element형 item을 인자로 받아 
list 안에 item의 값을 data로 갖는 node가 있으면 1을, 없으면 0을 리턴합니다.

int main(void)
리스트의 첫번째에 20을, 마지막에 30을, 첫번째에 10을, 마지막에 40을 추가하고 
2번째 위치에 70을 추가한 뒤 리스트의 모든 원소를 출력합니다.
이후 2번째 원소를 삭제하고 맨 처음 원소를 삭제하고 맨 마지막 원소를 삭제한 뒤
리스트의 모든 원소를 출력합니다.
이후 리스트에 20을 data로 갖는 노드가 존재하므로 TRUE를 출력합니다.
이후 리스트의 0번째 원소인 20을 출력합니다.
