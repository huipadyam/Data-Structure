// Simulation.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define true 1
#define false 0

#define MAX_QUEUE_SIZE 100

typedef struct element {
  int id;
  int arrival_time;
  int service_time;
} element; // Customer structure

typedef struct QueueType {
  element queue[MAX_QUEUE_SIZE];
  int front, rear;
} QueueType;
QueueType queue;

// Real random number generation function between 0 and 1
double randomf() { return rand() / (double)RAND_MAX; }

// Various state variables needed for simulation
int duration = 10; // Simulation time
double arrival_prob =
    0.7;                // Average number of customers arriving in one time unit
int max_serv_time = 10; // maximum service time for one customer
//줄이 두 개가 된 결과를 좀더 잘 보이게 하기 위해 고객응대시간을 10분으로
//늘린다.
int clock;

// Results of the simulation
int customers;        // Total number of customers
int served_customers; // Number of customers served
int waited_time;      // Time the customers waited

// Empty state detection function
int is_empty(QueueType *q) { return (q->front == q->rear); }
// Full state detection function
int is_full(QueueType *q) {
  return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Insert function
void enqueue(QueueType *q, element item) {
  if (is_full(q))
    printf("Queue is full\n");
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->queue[q->rear] = item;
}
// delete function
element dequeue(QueueType *q) {
  if (is_empty(q))
    printf("Queue is empty\n");
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->queue[q->front];
}

// Generate a random number.
// If it is smaller than ‘arrival_prov’, assume that new customer comes in the
// bank.
int is_customer_arrived() {
  if (randomf() < arrival_prob)
    return true;
  else
    return false;
}
// Insert newly arrived customer into queue
void insert_customer(int arrival_time) {
  element customer;

  customer.id = customers++;
  customer.arrival_time = arrival_time;
  customer.service_time = (int)(max_serv_time * randomf()) + 1;
  enqueue(&queue, customer);
  printf("Customer %d comes in %d minutes. Service time is %d minutes.\n",
         customer.id, customer.arrival_time, customer.service_time);
}

// Retrieve the customer waiting in the queue and return the customer's service
// time.
int remove_customer() {
  element customer;
  int service_time = 0;

  if (is_empty(&queue))
    return 0;
  customer = dequeue(&queue);
  service_time = customer.service_time - 1;
  served_customers++;
  waited_time += clock - customer.arrival_time;
  printf(
      "Customer %d starts service in %d minutes. Wait time was %d minutes.\n",
      customer.id, clock, clock - customer.arrival_time);
  return service_time;
}

// Print the statistics.
void print_stat() {
  printf("Number of customers served = %d\n", served_customers);
  printf("Total wait time =% d minutes\n", waited_time);
  printf("Average wait time per person = %f minutes\n",
         (double)waited_time / served_customers);
  printf("Number of customers still waiting = %d\n",
         customers - served_customers);
}

// Simulation program
void main() {
  int service_time_1 = 0; // banker1의 service time을 0으로 초기화
  int service_time_2 = 0; // banker2의 service time을 0으로 초기화

  clock = 0;                 //현재 시간을 0으로 초기화
  while (clock < duration) { //현재 시간이 운영할 시간과 같아지면 종료
    clock++; //반복할 때마다 현재 시간을 1씩 증가시킴
    printf("Current time=%d\n", clock); //현재시간 출력
    if (is_customer_arrived()) { //고객이 도착하면(도착 확률 반영)
      insert_customer(clock); //고객을 추가함(id, arrival time, service time과
                              //함께 추가하고 출력)
    }

    if (service_time_1 > 0 &&
        service_time_2 > 0) { // banker 두 명 다 service 중일 경우
      service_time_1--; // banker1의 남은 service time을 1 감소시킴
      service_time_2--; // banker2의 남은 service time을 1 감소시킴
      
      
    } else if (service_time_1 > 0 && service_time_2 == 0) {
      // banker1은 service 중이고 banker2는 손님이 없는 경우
      service_time_1--; // banker1의 남은 service time을 1 감소시킴
      
      service_time_2 =
          remove_customer(); //줄에 있는 고객 한 명을 꺼내 banker2에게 보내고
      // "고객의 service time-1"값을 리턴하며
      // served_customers값을 1 증가시키고 waited time을 계산해서 저장하고
      // 이 값들을 출력

      
    } else if (service_time_1 == 0 && service_time_2 > 0) {
      service_time_1 =
          remove_customer(); //줄에 있는 고객 한 명을 꺼내 banker1에게 보내고
      // "고객의 service time-1"값을 리턴하며
      // served_customers값을 1 증가시키고 waited time을 계산해서 저장하고
      // 이 값들을 출력
      
      service_time_2--; // banker2의 남은 service time을 1 감소시킴

      
    } else {
      service_time_1 =
          remove_customer(); //줄에 있는 고객 한 명을 꺼내 banker1에게 보내고
      // "고객의 service time-1"값을 리턴하며
      // served_customers값을 1 증가시키고 waited time을 계산해서 저장하고
      // 이 값들을 출력
      
      service_time_2 =
          remove_customer(); //줄에 있는 고객 한 명을 꺼내 banker2에게 보내고
      // "고객의 service time-1"값을 리턴하며
      // served_customers값을 1 증가시키고 waited time을 계산해서 저장하고
      // 이 값들을 출력
    }
  }

  
  print_stat(); // duration이 끝나면 통계(served_customers, waited_time,
  // Average wait time per person, Number of customers still waiting)을 출력함
}
