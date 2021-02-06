#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &tmp, int num){
    int left = 0;
    int right = tmp.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(tmp[mid]==num){
            return 1;
        }
        else if(tmp[mid]<num){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return 0;
}

int main() {
cin.tie(0);
ios_base::sync_with_stdio(false);
    int n, m, x;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        cout<< binarySearch(v, x) <<" ";
    }
    
    return 0;
}
