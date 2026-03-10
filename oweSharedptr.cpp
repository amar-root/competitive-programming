#include <iostream>
using namespace std;

template<typename T>
class sptr{
    T* res;
    int* counter;
    void incrementcounter(){
        if(counter){
            (*counter)++;
        }
    }
    void decrementcounter(){
        if(counter){
            (*counter)--;
            if((*counter) == 0){
                if(res){
                    delete res;
                    delete counter;
                    res = nullptr;
                    counter = nullptr;
                }
            }
        }
    }
    public:
        sptr(T* x = nullptr) : res(x), counter(new int(1)){
            cout << "Parameterised COnstructor \n";
        }
        sptr(const sptr<T>& ptr){
            cout << "Copy Constructor \n";
            res = ptr.res;
            counter = ptr.counter;
            incrementcounter();
        }
        sptr(sptr<T>&& ptr){
            cout << "Move constructor\n";
            res = ptr.res;
            counter = ptr.counter;
            ptr.res = nullptr;
            ptr.counter = nullptr;
        }
        sptr<T>& operator=(const sptr<T>& ptr){
            cout << "Copy assignment constructor\n";
            if(this != &ptr){
                decrementcounter();
                res = ptr.res;
                counter = ptr.counter;
                incrementcounter();
            }
            return *this;
        }
        sptr<T>& operator=(sptr<T>&& ptr){
            cout << "Move assignment constructor\n";
            if(this != &ptr){
                decrementcounter();
                res = ptr.res;
                counter = ptr.counter;
            }
            return *this;
        }
        ~sptr(){
            cout << "Destructor\n";
            decrementcounter();
        }

        void reset(T* renew){
            decrementcounter();
            if(renew){
                res = renew;
                counter = new int(1);
            } else {
                res = nullptr;
                counter = nullptr;
            }
        }
        T& operator*(){
            return *res;
        }
        int use_count(){
            return counter ? *counter : 0;
        }

};

int main(){
    sptr<int> p1;
    sptr<int> p2(new int(5));
    sptr<int> p3(p2);
    sptr<int> p4;
    p4 = p3;
    sptr<int> p5 = move(p2);
    sptr<int> p6; 
    p6 = move(p2);

    p3.reset(new int(10));
    cout << "\nValue of pointer : " <<  *(p3) << endl;

    cout << "count of pointer - " << p2.use_count();

    return 0;
}