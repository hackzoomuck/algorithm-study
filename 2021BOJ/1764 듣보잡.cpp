#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;
int n,m;
string s;
int main() {
    //일단 먼저 v1에 듣도 못한 사람을 넣고
    //보도 못한 사람을 체크하면서 듣도 있는 지 보고 없으면 v1에 넣는다, 있으면 듣도에서 제거를 한다.
    //vector find() 사용시에 500,000  10^12*(1/4) * 10^2
    cin>>n>>m;
    vector<string> v1;
    vector<string> v2;
    for(int i=0;i<n;i++){
        cin>>s;
        v1.push_back(s);
    }
    sort(v1.begin(),v1.end());
    for(int j=0;j<m;j++){
        cin>>s;
        if(binary_search(v1.begin(),v1.end(), s)){
            v2.push_back(s);
        }
    }
    sort(v2.begin(),v2.end());
    cout<<v2.size()<<"\n";
    for(auto name : v2){
        cout<<name<<"\n";
    }
    return 0;
}

