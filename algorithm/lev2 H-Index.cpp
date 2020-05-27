#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end()); 
    int cs = citations.size();
    int end_c = citations[cs - 1];
    int cnt_c = 0; // h이상 인용된 논문의 개수
    int max_c = 0;

    for (int h = 0; h < end_c; h++) {
        cnt_c = 0;
        for (int j = 0; j < cs; j++) {
            if (h <= citations[j]) ++cnt_c;
        }
        if (cnt_c >= h && cs - cnt_c <= h) max_c = max(max_c, h);
    }
    return answer=max_c;
}


//다른 사람 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();
}
