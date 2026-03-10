#include<iostream>
#include <algorithm>

using namespace std;

string encode62(long long n){
    string recordset = "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    string s = " ";
    while(n>0){
        int x = n%62;
        s += recordset[x];
        n /= 62;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){

    long long n;
    cout << "Enter the number to encode : ";
    cin >>n;
    cout << "\nafter encode number : " <<encode62(n);
    return 0;
}