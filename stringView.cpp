#include<iostream>
#include<string>
//#include <string_view>
using namespace std;

int main(){
    char c[] = "This is a test";
    string s = c;
    //std::string_view z = c;
    c[0] = '$';
    
    cout << "c : " << c <<endl;
    cout << "s : " << s <<endl;
    //cout << "sv : " << z <<endl;
}