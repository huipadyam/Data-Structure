#2
TreeNode *tree_successor(TreeNode *p)
TreeNode 구조체 포인터 p를 인자로 받아 p의 successor를 찾아 TreeNode구조체 포인터 형식으로 리턴

int main(void)
설정 값으로 tree의 parent를 초기화한 뒤 leftmost node부터 inorder successor를 찾아 출력한다.

#3
TreeNode *tree_predecessor(TreeNode *p)
TreeNode 구조체 포인터 p를 인자로 받아 p의 predecessor를 찾아 TreeNode구조체 포인터 형식으로 리턴

void main()
설정 값으로 tree의 parent를 초기화한 뒤 rightmost node부터 inorder predecessor를 찾아 출력한다.

#4
void insert_node(TreeNode **root, int key)
TreeNode형 double pointer root와 int형 key를 인자로 받아 tree의 올바른 위치에 key를 삽입한다.
key가 이미 BST에 존재하면 삽입되지 않는다.

void delete_node(TreeNode **root, int key)
TreeNode형 double pointer root와 int형 key를 인자로 받아 tree에서 key를 삭제한다.

void inorder(TreeNode *root)
TreeNode형 pointer root를 인자로 받아 tree를 inorder traversal로 출력한다.

void main()
tree를 inorder traversal로 출력하고 key node를 삭제한 뒤 다시 한 번 tree를 inorder traversal로 출력한다.
