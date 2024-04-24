#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> result(n+1);
    for(int i=1; i<=n; i++) cin >> result[i];

    vector<int> stack;
    vector<char> answer;
    int idx = 1;
    for(int i=1; i<=n; i++)
    {
        stack.push_back(i);
        answer.push_back('+');
        while(stack.size() > 0 && stack.back() == result[idx])
        {
            stack.pop_back();
            answer.push_back('-');
            idx++;
        }
    }

    if(answer.size() != n*2) cout << "NO";
    else for(auto i : answer) cout << i << "\n";

    return 0;
}