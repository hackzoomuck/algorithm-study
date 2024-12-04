#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool arr[201]={0,};
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size();i++){
        for(int j=0;j<numbers.size();j++){
            if(i==j) continue;
            int two_sum = numbers[i]+numbers[j];
            if(!arr[two_sum]){
                arr[two_sum]=1;
                answer.push_back(two_sum);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
