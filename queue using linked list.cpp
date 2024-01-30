#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
}*front=NULL,*rear=NULL;
//insert new node
void enqueue(int x);

//delete Node
int dequeue();

//Display queue
void Display();

int main() {
	enqueue(2);
	enqueue(4);
	enqueue(6);
	enqueue(8);
	enqueue(10);
	Display();

}
void enqueue(int x) {
	Node* t = new Node;
	if (t == NULL)
		cout << "queue is full\n";
	else
	{
		t->data = x;
		t->next = NULL;
		if (front == NULL)
			front = rear = t;
		else {
			rear->next = t;
			rear = t;

		}
	}

	}


int dequeue() {
	int x = -1;
	Node* p;
	if (front == NULL)
		return x;
	else
	{
		p = front;
		front = front->next;
		x = p->data;
		delete p;

	}

	return x;

}

void Display() {
	Node* p = front;
	while (p) {
		cout << p->data<<" ";
		p = p->next;
	}
	cout << "\n";
}
