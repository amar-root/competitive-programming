#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

class cQueue{
    int size;
    vector<int> buf;
    int front, rear, count;
    public:
        cQueue(int val){
            size = val;
            buf.resize(size);
            front = rear = -1;
            count = 0;
        }

        bool isEmpty(){
            return front == -1;
        }
        bool isFull(){
            return ((rear+1)%size == front);
        }
        void enque(int val){
            if(isFull()){
                cout << "Queue is full : \n";
                return;
            } 

            if(isEmpty()){
                front = rear = 0;
            } else {
                rear = (rear+1)%size;
            }
            buf[rear] = val;
            cout << "Enque value : " << val << endl;
            count++;
        }
        void deque(){
            if(isEmpty()){
                cout << "Queue is Empty : \n";
                return;
            }

            int temp = buf[front];
            cout << "Deque value : " << temp << endl;

            if(front == rear){
                front = rear = -1;
            } else {
                front = (front+1)%size;
            }
            
            count--;
        }
        int capacity(){
            return count;
        }
        void printQueue(){
            if(isEmpty()){
                cout << "Queue is Empty :\n";
                return;
            }
            cout << "Element in the queue : \n";
            int i = front;
            while(true){
                cout << buf[i] << " ";
                if(i == rear){
                    break;
                }
                i = (i+1)%size;
            }
        }
};
int main(){
    cQueue q(5);
    q.enque(4);
    q.enque(3);
    q.enque(6);
    q.enque(7);
    q.enque(8);
    cout << "Size of Queue is : " << q.capacity() << endl;
    q.enque(9);
    cout << "Size of Queue is : " << q.capacity() << endl;
    q.deque();
    q.deque();
    cout << "Size of Queue is : " << q.capacity() << endl;
    q.enque(10);
    q.enque(11);
    q.enque(12);
    cout << "Size of Queue is : " << q.capacity() << endl;
    q.deque();
    q.deque();
    q.deque();
    cout << "Size of Queue is : " << q.capacity() << endl;
    q.enque(21);

    cout << "Size of Queue is : " << q.capacity() << endl;
    q.printQueue();
}