#문제1

void init(LinkedStackType *s)
스택 포인터 s를 인자로 받아 s의 top node를 null로 초기화합니다.

int is_empty(LinkedStackType *s)
스택 포인터 s를 인자로 받아 s의 top node가 null이면(stack이 비었으면)1을, 
그렇지 않으면 0을 리턴합니다.

void push(LinkedStackType *s, element item)
스택 포인터 s와 element형 item을 인자로 받아 
s의 top node의 오른쪽에 data가 item인 node를 추가합니다.

element pop(LinkedStackType *s)
스택 포인터 s를 인자로 받아 s의 top node를 제거하고, 
제거된 node의 data를 리턴합니다.

element peek(LinkedStackType *s)
스택 포인터 s를 인자로 받아 s의 top node의 data를 리턴합니다.

int main()
스택 구조체를 생성하고 초기화한 뒤 1, 2, 3을 차례로 스택에 넣고,
3, 2, 1을 차례로 스택에서 제거하고 출력합니다. 이후 0을 리턴합니다.





#문제2

double randomf()
0에서 1 사이의 랜덤한 실수값을 발생시켜 double 형으로 리턴합니다.

int is_empty(QueueType *q)
QueueType 구조체 포인터 q를 인자로 받아 queue가 비었다면 1을, 그렇지 않다면 0을 리턴합니다.

int is_full(QueueType *q)
QueueType 구조체 포인터 q를 인자로 받아 queue가 꽉 찼다면 1을, 그렇지 않다면 0을 리턴합니다.

void enqueue(QueueType *q, element item)
QueueType 구조체 포인터 q와 element형 item을 인자로 받아 
queue의 마지막에 data가 item인 원소를 추가합니다.

element dequeue(QueueType *q)
QueueType 구조체 포인터 q를 인자로 받아 
queue의 첫번째 원소를 제거하고 그 원소를 리턴합니다.

int is_customer_arrived()
arrival_prob의 확률로 고객이 도착했다면 1을, 그렇지 않다면 0을 리턴합니다.

void insert_customer(int arrival_time)
int형 arrival_time을 인자로 받아 고객의 id, 도착시간, 응대시간을 대입한 뒤 
고객을 enqueue하고 출력합니다.

int remove_customer()
줄의 맨 앞에서 고객을 제거하고
served_customers의 값을 1 증가시키고 고객의 대기시간을 대입하고 이들을 출력합니다.
"제거된 고객의 응대시간에서 1을 뺀 값"을 응대시간에 저장하여 리턴합니다.

void print_stat()
Number of customers served, Total wait time, Average wait time per person, 
Number of customers still waiting을 출력합니다.

void main()
시간이 흐름에 따라 랜덤하게 고객을 도착시키고, 은행원 2명이 손님을 받습니다.
설정한 시간이 흐르면 모두 멈추고 통계를 출력합니다.
