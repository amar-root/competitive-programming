#include <iostream>
using namespace std;

template<typename T>
class uptr{
    T* a;
    public:
        uptr(T* x = nullptr) : a(x){
            cout << "Ctor\n";
        }
        uptr(const uptr<T>& obj) = delete;
        uptr& operator=(const uptr<T>& obj) = delete;

        uptr(uptr&& obj){
            a = obj.a;
            obj.a = nullptr;
        }
        uptr& operator=(uptr<T>&& obj){
            if(this != &obj){
                if(a){
                    delete a;
                }
                a = obj.a;
                obj.a = nullptr;
            }
            return *this;
        }

        T& operator*(){
            return *a;
        }
        T* get(){
            return a;
        }
        void reset(T* newa){
            if(a){
                delete a;
            }
            a = newa;
        }

        ~uptr(){
            cout << "dtor\n";
            if(a){
                delete a;
                a = nullptr;
            }
        }
};

int main(){
    uptr<int> p1(new int(10));
    //uptr<int> p2(p1);
    //uptr<int> p3 = p1;
    //uptr<int> p4;
    //p4 = p1;
    uptr<int> p5 = std::move(p1); 
    uptr<int> p6;
    p6 = std::move(p5);
    //cout << *(p1);
    cout << *(p6) << endl;
    p6.get();
    p6.reset(new int(20));

    cout << *(p6);
}