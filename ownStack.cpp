#include<iostream>

using namespace std;

class Stack{
    int *a;
    int cap;
    int top;
    public:
        Stack(int x){
            cap = x;
            a = new int[cap];
            top = -1;
        }
        void push(int x){
            if(top == cap-1){
                cout << "Stack is full :\n";
                return;
            }
            a[++top] = x;
        }
        void pop(){
            if(top == -1){
                cout << "Stack is Empty :\n";
                return;
            }
            
            top--;
        }
        int topI(){
            if(top == -1){
                cout << "Stack is empty :\n";
                return -1;
            }
            return a[top];
        }
        bool empty(){
            return top == -1;
        }
        void display(){
            cout << "Stack element are : \n";
            for(int i = top; i>=0;i--){
                cout << a[i] << " ";
            }
        }
};
int main(){
    Stack s(5);
    s.push(2);
    s.push(3);
    s.push(5);
    s.pop();
    cout << "Top of stack is - " << s.topI() << endl;
    s.push(7);
    s.push(10);
    s.push(12);
    s.push(11);
    s.display();
    return 0;
}