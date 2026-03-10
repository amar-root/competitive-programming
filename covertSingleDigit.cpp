#include <iostream>

using namespace std;

int sumSingle(int n){
    /*while(n>=10){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        cout << sum << " ";
        n = sum;
    }
    return n;*/
    if(n == 0) return 0;

    return 1+(n-1)%9;
}
int main(){
    int n;
    cout << "Enter the number : \n";
    cin >> n;
    int x = sumSingle(n);
    cout << "\nSingle digit are : " << x;
}