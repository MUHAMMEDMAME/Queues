#include<iostream>
using namespace std;
struct Queue {
	int size;
	int rear;
	int* Q;
};


void create(Queue* q, int size);

void enqueue(Queue* q, int x);
void dequeue(Queue* q);
void Display(Queue q);
int main() {
	Queue q;
	create(&q, 5);
	enqueue(&q, 8);
	enqueue(&q, 2);
	enqueue(&q, 6);
	enqueue(&q, 4);
	enqueue(&q, 10);
	dequeue(&q);
	Display(q);
	dequeue(&q);
	Display(q);
}

void create(Queue* q, int size) {
	q->size = size;
	q->rear = -1;
	q->Q = new int[size];
}

void enqueue(Queue* q, int x) {
	if (q->rear == q->size)
		cout << "Queue is full\n";
	else {

		q->rear++;
		q->Q[q->rear] = x;
	}
}

void dequeue(Queue* q) {
	int j = 0;
	int i;
	int proirity = q->Q[0];
	for (i = 1;i <= q->rear;i++) {
		if (proirity > q->Q[i]) {
			proirity = q->Q[i];
			j++;
		}
	}

	for ( i = j;i <= q->rear;i++) {
		q->Q[i] = q->Q[i + 1];
	}

	q->rear--;

}

void Display(Queue q) {
	int i;
	for (i = 0;i <= q.rear;i++)
		cout << q.Q[i] << " ";
	cout << endl;
}