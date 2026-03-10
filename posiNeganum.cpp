#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int fun(vector<int> v, int n){
    for(auto& x : v){
        x = x*x;
    }

    int count = 0;
    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        int l = 0;
        int r = n-1;
        while(l<r){
            int sum = v[l] + v[r];
            if(sum == v[i]){
                count++;
                l++;
                r--;
            } else if(sum < v[i]){
                l++;
            } else {
                r--;
            }
        }
    }
    return count;
}
int main(){
    vector<int> v{-2,3,6,4,9,5,8,10,61,97,35,11,60,120,150};

    int res = fun(v,v.size());

    cout << "count = " << res;
    return 0;
}