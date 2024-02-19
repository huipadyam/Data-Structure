#1
강의자료에서 제가 수정한 함수만 작성했습니다!

char *hash_chain_delete(element item, ListNode *ht[])
element형 item과 ListNode 포인터 배열 ht를 인자로 받아
hasg table ht에서 element가 item인 node를 삭제하고 item의 key를 리턴합니다.
이때 item이 hash table에 없으면 NULL을 리턴합니다.

void main()
hash table을 초기화한 뒤 operation과 key를 입력받아
그에 맞는 operation을 수행하고 hash table을 출력한 뒤
사용자가 3을 입력하면 terminate합니다.


#2

int random(int n)
int형 n을 인자로 받아 범위가 [0,n]인 랜덤 정수를 리턴합니다.

void insert_node(TreeNode **root, int key)
TreeNode형 이중 포인터 root와 int형 key를 인자로 받아
key를 binary search tree의 올바른 위치에 terminal node로 삽입합니다.
(메인함수에서 중복되는 key를 거르기 때문에 이는 고려할 필요 없습니다.)

void inorder(TreeNode *t)
TreeNode형 포인터 t를 인자로 받아 t의 자식 node들을 inorder traversal하면서 
data를 출력합니다.

int is_exist(int n, int *A, int size)
int형 n과 int형 포인터 A, int형 size를 인자로 받아 
크기가 size인 배열 A에 값이 n인 원소가 있으면 1을, 없으면 0을 리턴합니다.

int main(void)
input size가 1000이고 input 값의 범위가 [0,10000]인 input 배열에 
값을 중복 없이 랜덤으로 할당하고 이 값들을
binary search tree에 넣어 inorder traversal하며 크기 순으로 출력합니다.
마지막에는 0을 리턴합니다.

