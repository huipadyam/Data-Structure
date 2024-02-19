제가 조금이라도 수정한 함수들에 대한 리드미만 작성했습니다.

#1
void print_heap(HeapType *h)
HeapType 포인터 h를 인자로 받아 heap을 tree 모양으로 출력합니다.

void build_max_heap(HeapType *h)
HeapType 포인터 h를 인자로 받아 max heap property를 만족시키는 heap으로 변경합니다.

void main()
input size 크기의 heap을 만들어 build_max_heap을 활용하여 heap을 sort하고
결과를 출력합니다. 또한 결과가 옳은지를 출력하고, 코드의 실행시간을 측정합니다.

#2
int is_empty(HeapType *h)
HeapType 포인터 h를 인자로 받아 heap이 비었으면 1을, 그렇지 않으면 0을 리턴합니다.

int huffman_traversal(TreeNode *node, int ar[])
TreeNode 포인터 node(Huffman tree)를 인자로 받아 traversal하면서
문자별 codeword를 저장하는 int형 2중 포인터 m_LUT의 값을 채우고
문자별 codeword의 size를 저장하는 int형 포인터 m_bit_size의 값을 채웁니다.

void huffman_encoding(char *str, bits_stream *bits_str)
char 포인터 str과 bits_stream 포인터 bits_str를 인자로 받아 
char 배열인 str에 저장된 문자들을 codeword에 따라 인코딩하여 정수 배열인 bits_str에 저장합니다.
이후 결과를 출력합니다.

int huffman_decoding(bits_stream *bits_str, TreeNode *node, char *decoded_str)
bits_stream 포인터 bits_str과 TreeNode 포인터 node(Huffman tree), char 포인터 decoded_str를 인자로 받아
정수 배열인 bits_str에 저장된 숫자를 따라 node(Huffman tree)를 traversal하며 디코딩해서
char 배열인 decoded_str에 저장합니다.
이후 결과를 출력합니다.

void main()
주어진 data를 이용하여 Huffman tree를 만들고 codeword를 저장한 뒤
예시 문자열을 출력한 뒤, incoding해서 출력, decoding해서 출력합니다.
