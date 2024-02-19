1. transposing sparse matrix

1) void initMatrix(SparseMatrix *B)
sparse matrix 구조체 포인터를 인자로 받아서 matrix를 강의 ppt 의 matrix와 똑같이 sparse matrix form으로 초기화하는 함수입니다. 
row 개수, col 개수, term 개수와 각각의 term의 value를 ppt 예시와 같은 값으로 초기화합니다.

2) void initRMatrix(SparseMatrix *B) 
sparse matrix 구조체 포인터를 인자로 받아서 matrix를 랜덤하게 sparse matrix form으로 초기화하는 함수입니다.
row와 col은 1~MAX_RC의 값으로, term의 개수는 1~MAX_TERMS의 값으로 랜덤으로 할당합니다.
그 후 각각의 term에 0~(row-1) 범위의 row를, 0~(col-1) 범위의 col을, 1~MAX_RC 범위의 value를 랜덤으로 할당합니다.

3) void transposeMatrix(SparseMatrix *B)
sparse matrix 구조체 포인터를 인자로 받아 transpose시켜 sparse matrix form으로 저장합니다.
sparse matrix 구조체 포인터를 인자로 받아서 matrix의 data배열의 원소들을 col이 작은 순으로 재정렬합니다.
그 후 각각의 data 배열의 원소들의 row와 col을 swap하고, matrix의 row 개수와 col 개수를 swap합니다.

4) void printMatrix(SparseMatrix *B)
sparse matrix의 구조체 포인터를 인자로 받아 dense matrix form으로 출력합니다. 이때 가독성을 위해 row index와 col index도 함께 출력합니다.
dense matrix form으로 나타냈을 때의 값들을 모두 저장할 2차원 배열을 선언하여 값을 저장한 뒤 반복문을 이용하여 출력합니다.

5) main 함수에서는 SparseMatrix 구조체 B를 선언하고
ppt 값으로 초기화한 뒤 출력, transpose시킨 뒤 출력합니다. 
그리고 다시 랜덤으로 초기화한 뒤 출력, transpose시킨 뒤 출력합니다.



2. memory allocating 3D double matrix

1) void mem_alloc_3D_double (double **** A)
double형 4중 포인터(double형 3D 행렬인 3중 포인터의 주소)를 인자로 받아서 각 face, row, col의 메모리를 할당하고 
각 원소를 0.00~4.99의 double형 값으로 초기화합니다.
face, row, col의 개수는  코드 맨 위에 매크로 상수로 정의되어 있습니다. 

2) void addition_3D(double ****A, double ****B, double ****C)
double형 4중 포인터(double형 3D 행렬인 3중 포인터의 주소) A, B, C를 인자로 받아서 
*A(3D행렬)의 i면 j행 k열 원소와 *B(3D행렬)의 i면 j행 k열 원소를 더해 *C(3D행렬)의  i면 j행 k열 원소에 저장합니다.

3) void print_3D(double ****A)
double형 4중 포인터(double형 3D 행렬인 3중 포인터의 주소)를 인자로 받아서 double형 3D배열의 모든 원소를 출력합니다.
이때 각 원소는 소숫점 둘째자리까지 출력하고, 한 원소를 출력한뒤 공백문자 하나도 같이 출력합니다.
한 row의 출력이 끝나면 줄바꿈문자를 1회 출력하고, 한 face의 출력이 끝나면 줄바꿈문자를 3회 출력하고,
3D matrix의 모든 면의 출력이 끝나면 줄바꿈문자를 5회 출력합니다. 

4) main 함수에서는 3D matrix A, B, C를 선언하여 메모리를 할당하고, A, B만 출력합니다.
그리고 A와 B를 더한 결과를 C에 저장해서 C를 출력합니다.
이후 A, B, C의 모든 원소의 메모리를 deallocate합니다.
