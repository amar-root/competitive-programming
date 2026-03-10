#include <iostream>
#include <vector>

using namespace std;

vector<int> product(vector<int> v){
    int n = v.size();

    vector<int> l(n,1);
    vector<int> r(n,1);

    for(int i=1;i<n;i++){
        l[i] = l[i-1] * v[i-1];
    }

    for(int j=n-2;j>=0;j--){
        r[j] = r[j+1] * v[j+1];
    }

    vector<int> ans(n,1);

    for(int i=0;i<n;i++){
        ans[i] = l[i] * r[i];
    }

    return ans;
}
int main(){

    vector<int> v{-1,1,0,-3,3};

    vector<int> ans = product(v);

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}