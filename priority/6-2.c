// huffman.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_ELEMENT 1000
#define MAX_BIT 10
#define MAX_CHAR 20

// Input data for huffman code
typedef struct input_huff {
  char *data; // Character array (a ~ f)
  int *freq;  // Frequency array
  int size;   // Number of characters
} input_huff;

// Structure for huffman binary tree
typedef struct TreeNode {
  char data;          // Character (a ~ f)
  int key;            // Frequency
  int bits[MAX_BIT];  // Huffman codeword
  int bit_size;       // Huffman codeword's size
  struct TreeNode *l; // Left child of huffman binary tree
  struct TreeNode *r; // Right child of huffman binary tree
} TreeNode;

// Structure for bits stream
typedef struct bits_stream {
  int *stream;
  int length;
} bits_stream;

// Elements used in the heap
typedef struct element {
  TreeNode *ptree;
  int key; // frequency of each character
} element;

// Heap
typedef struct HeapType {
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;

int **m_LUT, *m_bit_size;
int m_char_size = 6;

// Initialization
void init(HeapType *h) { h->heap_size = 0; }
//
int is_empty(HeapType *h) {
  if (h->heap_size == 0)
    return 1; // c로 구현하기 위해 true를 1로 바꿈
  else
    return 0; // c로 구현하기 위해 false를 0으로 바꿈
}

void insert_min_heap(HeapType *h, element item) {
  int i;
  i = ++(h->heap_size);

  // compare it with the parent node in an order from the leaf to the root
  while ((i != 1) && (item.key < h->heap[i / 2].key)) {
    h->heap[i] = h->heap[i / 2];
    i /= 2;
  }
  h->heap[i] = item; // Insert new node
}

element delete_min_heap(HeapType *h) {
  int parent, child;
  element item, temp;
  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size) {
    if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
      child++;
    if (temp.key <= h->heap[child].key)
      break;
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

// Node generation in binary tree
TreeNode *make_tree(TreeNode *left, TreeNode *right) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  if (node == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(1);
  }
  node->l = left;
  node->r = right;
  return node;
}

// Binary tree removal
void destroy_tree(TreeNode *root) {
  if (root == NULL)
    return;
  destroy_tree(root->l);
  destroy_tree(root->r);
  free(root);
}

// Huffman code generation
element huffman_tree(input_huff *huff) {
  int i;
  TreeNode *node, *x;
  HeapType heap;
  element e, e1, e2;
  init(&heap);

  int n = huff->size;

  for (i = 0; i < n; i++) {
    node = make_tree(NULL, NULL);
    e.ptree = node;
    node->data = huff->data[i];
    e.key = node->key = huff->freq[i];
    memset(node->bits, 0, sizeof(int) * MAX_BIT);
    node->bit_size = 0;

    insert_min_heap(&heap, e);
  }

  for (i = 1; i < n; i++) {
    // Delete two nodes with minimum values
    e1 = delete_min_heap(&heap);
    e2 = delete_min_heap(&heap);

    // Merge two nodes
    x = make_tree(e1.ptree, e2.ptree);
    e.ptree = x;
    x->data = NULL;
    e.key = x->key = e1.key + e2.key;
    memset(x->bits, 0, sizeof(int) * MAX_BIT);
    x->bit_size = 0;

    insert_min_heap(&heap, e);
  }
  e = delete_min_heap(&heap); // Final Huffman binary tree

  return e;
  //	destroy_tree(e.ptree);
}

// Generate the huffman codeword from the huffman binary tree
// Hint: use the recursion for tree traversal
// input: root node
// output: m_LUT, m_bit_size
int i = 0; // m_LUT의 행 인덱스, 함수가 재귀적으로 실행되어도 값이 유지되어야
           // 하므로 함수 밖에서 선언
int j = 0; // j는 node의 깊이이고 이는 곧 bit size를 나타낸다.
int huffman_traversal(TreeNode *node,
                      int ar[]) { //호출할 때마다 codeword를 함께 인자로 전달
  if (node->l == NULL &&
      node->r == NULL) { // 재귀함수의 초기조건 부분, terminal node일때
    i = (int)(node->data) -
        (int)'a'; // 행 인덱스를 a일때 0, b일때 1,...으로 지정
    for (int k = 0; k < MAX_BIT; k++) {
      m_LUT[i][k] = ar[k]; // ar의 모든 원소를 m_LUT[i]에 옮긴다.
      // m_LUT[i] = ar; 이렇게 하면 안됨
    }

    m_bit_size[i] = j; //재귀적으로 실행될때마다 j가 증가하므로 j는 bit size다.
    return 0; //초기조건 종료
  }

  ar[j] = 0;                      // ar의 j번째 원소에 0 대입
  j++;                            // node의 깊이인 j를 1 증가시킨 후
  huffman_traversal(node->l, ar); // 왼쪽 자식으로 재귀 호출
  j--; //자식 호출이 끝나면 다시 부모로 돌아오므로 node의 깊이인 j를 1
       //감소시킨다.

  ar[j] = 1;                      // ar의 j번째 원소에 1 대입
  j++;                            // node의 깊이인 j를 1 증가시킨 후
  huffman_traversal(node->r, ar); // 오른쪽 자식으로 재귀 호출
  j--; //자식 호출이 끝나면 다시 부모로 돌아오므로 node의 깊이인 j를 1
       //감소시킨다.

  return 0; // 함수를 빠져나가고 호출한 곳으로 돌아감
}

int **mem_2D_int(int row, int col) {
  int **m2 = (int **)malloc(sizeof(int *) * row);
  for (int i = 0; i < row; i++)
    m2[i] = (int *)malloc(sizeof(int) * col);
  return m2;
}

void print_codeword() {
  printf("* Huffman codeword\n");
  for (int i = 0; i < m_char_size; i++) {
    switch (i) {
    case 0:
      printf("%c: ", 'a');
      break;
    case 1:
      printf("%c: ", 'b');
      break;
    case 2:
      printf("%c: ", 'c');
      break;
    case 3:
      printf("%c: ", 'd');
      break;
    case 4:
      printf("%c: ", 'e');
      break;
    case 5:
      printf("%c: ", 'f');
      break;
    }

    for (int j = 0; j < m_bit_size[i]; j++)
      printf("%d ", m_LUT[i][j]);

    printf("\n");
  }
}

// Input: 'str'
// Output: 'bits_stream' (consisting of 0 or 1)
// 'bits_stream' is generated using 'm_LUT' generated by the huffman binary tree
// Return the total length of bits_stream
void huffman_encoding(char *str, bits_stream *bits_str) {
  //문자 배열을 정수 배열로 인코딩
  int k = 0;                              // 정수 배열의 인덱스 변수
  for (int i = 0; i < strlen(str); i++) { // 문자 배열의 길이만큼 반복
    for (int j = 0; j < m_bit_size[str[i] - 'a']; j++) {
      // 각 문자의 codeword 길이만큼 반복
      bits_str->stream[k++] = m_LUT[str[i] - 'a'][j];
      // 인코딩 결과를 담을 정수 배열에 각 문자의 codeword를 차례로 저장,
      // 그때마다 k 증가
      // switch case문 사용할 필요x
      bits_str->length++;
      // 인코딩 결과를 담을 정수 배열의 길이를 1씩 증가시킨다.
    }
  }

  printf("\n* Huffman encoding\n");
  printf("total length of bits stream: %d\n", k);
  printf("bits stream: ");
  for (int i = 0; i < k; i++) // bit stream의 각 원소(인코딩 결과) 출력
    printf("%d", bits_str->stream[i]);
  printf("\n");
}

// input: 'bits_stream' and 'total_length'
// output: 'decoded_str'
int huffman_decoding(bits_stream *bits_str, TreeNode *node, char *decoded_str) {
  // 정수 배열을 문자 배열로 디코딩
  int j = 0; // 문자 배열의 인덱스 변수
  TreeNode *root = node;
  for (int i = 0; i <= bits_str->length; i++) {
    // 정수 배열 길이가 될 때까지 반복
    // -1까지 반복이 아닌 이유는, 마지막 terminal node에 도달하기 직전에
    // traversal을 하는 과정에서 이미 i 값이 정수 배열 길이 -1 이 되기 때문이다.
    if (node->l == NULL && node->r == NULL) { // terminal node일 경우
      i--; // 정수 배열 인덱스 i의 증가를 상쇄하기 위해 감소시킴
      decoded_str[j++] = node->data; // terminal node의 data를 문자 배열에 저장
      node = root; // 다시 root node부터 내려가면서 탐색
    } else {       // terminal node가 아닐 경우
      if (bits_str->stream[i] == 0) { // 주어진 정수 배열의 원소가 0이면
        node = node->l;               // 왼쪽 자식 노드로 이동
      } else            // 주어진 정수 배열의 원소가 1이면
        node = node->r; // 오른쪽 자식 노드로 이동
    }
  }

  printf("\n* Huffman decoding\n");
  printf("total number of decoded chars: %d\n", j);
  printf("decoded chars: ");
  for (int i = 0; i < j; i++) // decoded_str의 각 원소(디코딩 결과) 출력
    printf("%c", decoded_str[i]);
  printf("\n");

  return j;
}

void main() {
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {45, 13, 12, 16, 9, 5};

  input_huff *huff1 = (input_huff *)malloc(sizeof(input_huff));
  huff1->data = data;
  huff1->freq = freq;
  huff1->size = m_char_size;

  // m_LUT: each row corresponds to the codeword for each character
  // m_bit_size: 1D array of codeword size for each character
  // For instance, a = 0, b = 101, ...
  // 1st row of 'm_LUT': 0 0 ... 0
  // 2nd row of 'm_LUT': 1 0 1 ...0
  // m_bit_size = {1, 3, ...}
  m_LUT = mem_2D_int(m_char_size, MAX_BIT);
  m_bit_size = (int *)malloc(sizeof(int) * m_char_size);

  // Generate the huffman binary tree on heap
  // 'element_root': element containing the root node
  element element_root = huffman_tree(huff1);

  // Generate the huffman codeword from the huffman binary tree
  int ar[MAX_BIT] = {0};
  // traversal 과정에서 인자로 전달할 배열 ar, codeword를 저장한다.
  huffman_traversal(element_root.ptree, ar);

  // printf out the huffman codeword
  print_codeword();

  // example of input data
  char str[MAX_CHAR] = {"abacdebaf"};
  // char str[MAX_CHAR] = { "ab" };
  char decoded_str[MAX_CHAR];

  printf("\n* input chars: ");
  for (int i = 0; i < strlen(str); i++)
    printf("%c", str[i]);
  printf("\n");

  // start encoding
  bits_stream *bits_str1 = (bits_stream *)malloc(sizeof(bits_stream));
  bits_str1->stream = (int *)malloc(sizeof(int) * MAX_BIT * MAX_CHAR);
  memset(bits_str1->stream, -1, sizeof(int) * MAX_BIT * MAX_CHAR);
  bits_str1->length = 0;

  huffman_encoding(str, bits_str1);

  // start decoding
  int decoded_char_length =
      huffman_decoding(bits_str1, element_root.ptree, decoded_str);
}