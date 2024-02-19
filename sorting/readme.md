#1
void selection_sort(data *list, int n)
data 구조체 포인터 list와 int형 n(data의 개수)을 인자로 받아서
list의 data를 selection sort하여 list에 저장한다.

void selection_sort_stable(data *list, int n)
data 구조체 포인터 list와 int형 n(data의 개수)을 인자로 받아서
list의 data를 stable하게 selection sort하여 list에 저장한다.

int main()
data의 id와 score, size를 강의 ppt 값으로 초기화한 다음
input data를 차례로 출력한다.
이 data들을 selection_sort_stable 함수에 넣은 다음
sorted data를 차례로 출력한다.

#3
Counting_Sort(int D[], int A[])
int형 배열 D(기준 digit)와 int형 배열 A(data)를 인자로 받아서
기준 digit에 따라 stable하게 A를 counting sort하여 A에 저장.

void radix_sort(int list[])
int형 배열 list를 인자로 받아서 radix sort
(digit 별로 counting sort)하여 list에 저장

int main(void)
0 ~ (2^24)-1 범위의 값을 랜덤으로 N개 생성하여 배열에 저장하고,
radix sort한 다음 차례로 출력한다. 
또한 list가 제대로 정렬되었는지 확인한다.



