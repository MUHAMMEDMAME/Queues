#include<iostream>
using namespace std;
struct Queue {
	int size;
	int front;
	int rear;
	int* Q;
};
//create queue
void create(Queue* q, int size);
//insert new elemnt
void enqueue(Queue* q,int x);
//delete element
int dequeue(Queue* q);

// queue is Empty return true else false
bool isEmpty(Queue* q);

//queue is Full return true else return true
bool isFull(Queue* q);


//Display queue
void Display(Queue q);
int main() {
	Queue q;
	create(&q, 5);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	cout << dequeue(&q)<<endl;
	Display(q);

}
void create(Queue* q, int size) {
	q->size = size;
	q->rear = q->front = 0;
	q->Q = (int*)malloc(sizeof(int) * q->size);
}

void enqueue(Queue* q,int x) {
	if (isFull(q))
		cout << "queue is full\n";
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x;

	}
}

int dequeue(Queue* q){
	int x = -1;
	if (q->front == q->rear)
		return x;
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];

	}

	return x;
}
bool isEmpty(Queue* q) {
	if (q->rear == q->front)
		return true;
	return false;
}
bool isFull(Queue* q) {
	if ((q->rear + 1) % q->size == q->front)
		return true;
	return false;
}

void Display(Queue q) {
	int i = q.front + 1;
	do {
		cout << q.Q[i]<<" ";
		i = (i + 1) % q.size;

	} while (i != (q.rear + 1) % q.size);
}

