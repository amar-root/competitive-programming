#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

class RBuffer{
    int size;
    vector<int> buffer;
    atomic<int> front;
    atomic<int> rear;

    public:

        RBuffer(int val){
            size = val;
            buffer.resize(size);
            front = rear = 0;
        }
        bool isEmpty(){
            return front.load() == rear.load();
        }

        bool isFull(){
            int next = (rear.load()+1)%size;
            return next == front.load();
        }

        bool enque(int val){
            if(isFull()){
                return false;
            }

            int r = rear.load(memory_order_relaxed);
            buffer[r] = val;
            rear.store((r+1)%size, memory_order_release);

            return true;
        }

        bool deque(int &val){
            if(isEmpty())
                return false;

            int f = front.load(memory_order_relaxed);
            val = buffer[f];
            front.store((f+1)%size, memory_order_release);
            return true;
        }
};

int main(){
    RBuffer r(7);

    thread producer([&](){
        for(int i=1;i<=10;i++){
            while(!r.enque(i)){

            }
            cout << "Produced : " << i << endl;
        }
    });

    thread consumer([&](){
        int val;
        for(int i=1;i<=10;i++){
            while(!r.deque(val)){

            }
            cout << "Consumed : " << val << endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}