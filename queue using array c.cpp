#include<iostream>
using namespace std;
struct Queue {
	int size;
	int front;
	int Rear;
	int* Q;
};
void create(Queue* q,int size) {
	q->size = size;
	q->front = q->Rear = -1;
	q->Q = (int*)malloc(sizeof(int) * q->size);
}
void enqueue(Queue *q,int x) {
	if (q->Rear == q->size - 1)
		cout << "queue is full\n";
	else
	{
		q->Rear++;
		q->Q[q->Rear] = x;

	}

}
int dequeue(Queue* q) {
	int x = -1;
	if (q->Rear == q->front)
		return x;
	else{
		q->front++;
		x = q->Q[q->front];
	}
	return x;
}
void Display(Queue q) {
	int i;
	for (i = q.front + 1;i <= q.Rear;i++)
		cout << q.Q[i] << " ";
	cout << endl;
}
int main(){
	Queue q;
	create(&q,5);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	cout<<dequeue(&q)<<endl;
	Display(q);
}