#include <iostream>
#include <cstring>

using namespace std;

class String{
    char* res;
    unsigned int len;
    public:
        String() : res(nullptr), len(0){}
        String(const char* str){
            len = strlen(str);
            res = new char[len + 1];
            strcpy(res, str);
        }
        String(const String& str){
            len = str.len;
            res = new char[len+1];
            strcpy(res, str.res);
        }
        String& operator=(const String& str){
            if(this != &str){
                delete[] res;
                len = str.len;
                res = new char[len+1];
                strcpy(res, str.res);
            }
            return *this;
        }
        int length(){
            return len;
        }
        friend istream& operator>>(istream& in, const String& str);
        friend ostream& operator<<(ostream& out, const String& str);

        ~String(){
            if(res){
                delete[] res;
                res = nullptr;
                len = 0;
            }
        }
};

istream& operator>>(istream& in, const String& str){
    in >> str.res;
    return in;
}
ostream& operator<<(ostream& out, const String& str){
    out << str.res;
    return out;
}
int main(){
    String s1;
    String s2 = "Hello World";
    String s3(s2);
    String s4;
    s4 = s3;
    int len = s2.length();
    String s5;
    cout << s3;
    cin >> s5;
    cout << s5;
}