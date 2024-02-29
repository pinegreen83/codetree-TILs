#include <iostream>
#include <vector>

using namespace std;
int n, answer;
vector<vector<int>> lines;

void findmax(int last, int cnt)
{
    if(last == n)
    {
        answer = max(answer, cnt);
        return;
    }
    for(int i=last+1; i<=n; i++)
    {
        if(lines[last][1] < lines[i][0])
        {
            findmax(i, cnt+1);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    lines.push_back({0, 0});
    for(int i=0; i<n; i++)
    {
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        lines.push_back(temp);
    }
    findmax(0, 0);
    cout << answer;

    return 0;
}