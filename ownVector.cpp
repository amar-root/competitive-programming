#include <iostream>
using namespace std;

class myVector{
    int* a;
    int cap;
    int size;
    public:
        myVector(){
            size = 0;
            cap = 0;
            a = nullptr;
        }
        void push(int x){
            if(size != cap){
                a[size++] = x;
            }

            int newcap = (cap == 0) ? 1 : 2* cap;
            //cap = 2* cap;
            int* temp = new int[newcap];

            for(int i=0;i<cap;i++){
                temp[i] = a[i];
            }
            delete a;
            a = temp;
            cap = newcap;     
        }
        void pop(){
            if(size > 0)
                size--;
        }
        int front(){
            return a[0];
        }
        int pear(){
            return a[size];
        }
        int Size(){
            return size;
        }
        void display(){
            cout << "vector elements are : \n";
            for(int i=0;i<size;i++){
                cout << a[i] << " ";
            }
        }
};

int main(){
    
    myVector v;

    v.push(2);
    v.push(5);
    v.push(7);
    cout << "size of vector : " << v.Size() << endl;
    v.pop();
    cout << "Front of vector : " << v.front() << endl;
    v.push(10);
    v.push(12);
    v.display();

    return 0;
}