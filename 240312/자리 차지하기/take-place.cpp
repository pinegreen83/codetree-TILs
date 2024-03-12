#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a, answer = 0;
    cin >> n >> m;
    vector<int> chairs(m+1);

    for(int i=0; i<n; i++)
    {
        cin >> a;
        chairs[a]++;
    }

    for(int i=1; i<=m; i++)
    {
        answer += chairs[i];
        if(answer > i) answer = i;
    }
    cout << answer;

    return 0;
}