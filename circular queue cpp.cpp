#include<iostream>
using namespace std;
class Queue {
private:
	int size;
	int front;
	int rear;
	int* Q;
public:
	//create queue
	Queue(int size);
	//destroy queue
	~Queue();
	//insert element
	void enqueue(int x);
	//delete element
	void dequeue();
	//ckeck is queue is empty
	bool empty();
	//ckeck is queue is full
	bool full();

//Display queue
	void Display();
};
Queue::Queue(int size) {
	this->size = size;
	front = rear = 0;
	Q = new int[size];
}
void Queue::enqueue(int x) {
	if (full())
		cout << "Queue is fulll\n";
	else
	{
		rear = (rear + 1) % size;
		Q[rear] = x;
	}
}

void Queue::dequeue(){
	if (empty())
		cout << "Queue is empty\n";
	else
	{
		front = (front + 1) % 6;
	
	}
}

bool Queue::empty() {
	return rear == front;
}

bool Queue::full() {
	return (rear + 1) % size == front;
}

void Queue::Display() {
	int i = front + 1;
	do {
		cout << Q[i] << " ";
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
}
Queue::~Queue() {
	delete[]Q;
}
int main() {
	Queue q(5);
	q.enqueue(2);
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(8);
	q.enqueue(10);
	q.Display();
	
}