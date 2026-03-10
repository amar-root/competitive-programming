#include <iostream>
using namespace std;

class Construct{
    int *a;
    public:
        Construct() : a(nullptr){}
        Construct(int x){
            a = new int(x);
            cout << "parameterised COnstructor" << endl;
        }
        Construct(const Construct& obj){
            a = obj.a;
            cout << "Copy COnstructor : " << endl;
            //b = obj.b;
        }
        Construct& operator=(const Construct& obj){
            cout << "Copy Assigenemt : " << endl;
            if(this != &obj){
                a = obj.a;
                //b = obj.b;
            }
            return *this;
        }
        Construct(Construct&& obj){
            cout << "Move constructor : " << endl;
            a = obj.a;
            //b = obj.b;
            obj.a = nullptr;
        }
        Construct& operator=(Construct&& obj){
            cout << "Move assigenemt : " << endl;
            if(this != &obj){
                if(a){
                    delete a;
                }
                a = obj.a;
                obj.a = nullptr  ;
            }
            return *this;
        }
        int show(){
            return *a;
        }
        ~Construct(){
            cout << "Destructor :" << endl;
            delete a;
            a = nullptr;
        }
};
int main(){
    Construct c1(5);
    Construct c2(6);
    Construct c3(c1);
    Construct c4 = c2;
    c4 = c1;
    cout << "Value = " << c1.show() << " " << c2.show() << " " << c3.show() << " " << c4.show() <<endl;

    Construct c5(10);
    Construct c6(20);
    Construct c7 = move(c5);
    Construct c8;
    c8 = move(c6);
    
    cout << "Value : " << c7.show() << " " << c8.show() << endl;
}