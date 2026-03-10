#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort012(vector<int> a){
    int n = a.size();

    int lo = 0;
    int hi = n-1;
    int mid = 0;

    while(mid <= hi){
        if(a[mid] == 0){
            swap(a[lo++],a[mid++]);
        } else if(a[mid] == 1){
            mid++;
        } else {
            swap(a[mid],a[hi--]);
        }
    }
    cout << "Sorted array is \n";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    /*vector<int> ans;
    for(int i=0;i<n;i++){
        if(v[i] == 0){
            c0++;
        } else if(v[i] == 1){
            c1++;
        } else {
            c2++;
        }
    }
    for(int i=0;i<c0;i++){
        ans.push_back(0);
    }
        for(int i=0;i<c1;i++){
        ans.push_back(1);
    }
        for(int i=0;i<c2;i++){
        ans.push_back(2);
    }
    cout << "Sorted array is \n";
    for(int i=0;i<n;i++){
        cout << ans[i];
    }*/
}

int main(){
    vector<int> v{1,1,2,0,0,2,1,0,0,1,1,1};
    sort012(v);

    return 0;
}