#include<iostream>

using namespace std;

class Queue{
    int *a;
    int front,rear,capacity;
    public:
        Queue(int size){
            capacity = size;
            a =  new int[capacity];
            front = rear = -1;
        }

        bool isEmpty(){
            return front == -1;
        }
        bool isFull(){
            return (rear + 1) % capacity == front;
        }

        void enque(int x){
            if(isFull()){
                cout << "Queue is full :\n";
                return;
            }
            
            if(isEmpty()){
                front = 0;
            }
            rear = (rear+1) % capacity;
            a[rear] = x;
            cout << "Enque in the queue : " << a[rear] << endl;
        }

        void deque(){
            if(isEmpty()){
                cout << "Queue is Empty \n";
                return;
            }
            cout << "Deque fron queue : " << a[front] << endl;
            if(front == rear){
                front = rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
        }
        int peek(){
            if(isEmpty()){
                cout << "Queue is Empty \n";
                return -1;
            }
            return a[front];
        }
};

int main(){
    Queue q(5);
    q.enque(2);
    q.enque(5);
    q.enque(7);
    q.deque();
    cout << "front item in queue : " << q.peek() << endl;
}