#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
int count = 0;
class Queue{
    Node* front;
    Node* rear;
    public:
        Queue(){
            front = rear = nullptr;
        }
        bool isEmpty(){
            return front == nullptr;
        }
        void enque(int x){
            Node* temp = new Node(x);
            if(isEmpty()){
                front = rear = temp;
            } else {
                rear->next = temp;
                rear = temp;
            }
            cout << "Enque value = " << x << endl;
            count++;
        }
        void deque(){
            if(isEmpty()){
                cout << "queue is empty :\n";
                return;
            }
            Node* temp = front;
            cout << "deque val : " << front->data << endl;

            front = front->next;
            delete temp;

            if(front == nullptr){
                rear = nullptr;
            }
            count--;
        }
        int peek(){
            if(isEmpty()){
                cout << "Queue is empty \n";
                return -1;
            }
            return front->data;
        }
        int element(){
            return count;
        }
};

int main(){
    Queue q;
    q.enque(5);
    q.enque(10);
    q.enque(3);
    cout << "peek data : " << q.peek() << endl;
    cout << "Element in the queue : " << q.element() << endl;
    q.deque();
    q.deque();
    cout << "Element in the queue : " << q.element() << endl;
}