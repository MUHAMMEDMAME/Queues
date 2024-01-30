#include<iostream>
using namespace std;
struct Queue {
	int size;
	int r;
	int* Q;
};
void create(Queue* q, int size) {
	q->size = size;
	q->r = -1;
	q->Q = (int*)malloc(sizeof(int) * size);

}

void enqueue(Queue* q, int x) {
	if (q->r == q->size - 1)
		cout << "Queue is full\n";
	else {
		q->r++;
		q->Q[q->r] = x;
	}
}

void dequeue(Queue* q) {
	int i;
	if (q->r == -1)
		cout << "Queue is empty\n";
	else {
		for (i = 0;i <= q->r;i++)
			q->Q[i] = q->Q[i + 1];

		q->r--;
	}

}

void Display(Queue q) {
	int i;
	for (i = 0;i <= q.r;i++)
		cout << q.Q[i]<<" ";
	cout << endl;
}
int main() {
	Queue q;
	create(&q, 5);
	enqueue(&q, 2);
	enqueue(&q, 4);
	enqueue(&q, 6);
	enqueue(&q, 8);
	enqueue(&q, 10);
	dequeue(&q);
	enqueue(&q, 14);
	enqueue(&q, 14);
	Display(q);
}