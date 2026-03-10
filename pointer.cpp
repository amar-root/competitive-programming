#include<iostream>

using namespace std;

int res;
int* inc(int*);
int* sqr(int*);

int* (*funArray[])(int *) = {inc, sqr};

int* inc(int *x){
    //int res;
    res = (*x) + 1;
    return &res;
}

int* sqr(int *x){
    //int res;
    res = (*x) * (*x);
    return &res;
}

int main(){

    int val = 5;
    
    int* res1 = funArray[0](&val);
    int* res2 = funArray[1](&val);

    cout << "Increament = " << *res1 << endl;
    cout << "Square = " << *res2;
    return 0;
}