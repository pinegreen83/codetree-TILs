#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int answer = 0;
vector<int> ints(20);
vector<int> comb;

void choose(int cnt, int now)
{
    if(cnt == m)
    {
        int temp = ints[comb[0]];
        for(int i=1; i<comb.size(); i++)
        {
            temp = temp ^ ints[comb[i]];
        }
        answer = max(answer, temp);
    }
    for(int i=now+1; i<n; i++)
    {
        comb.push_back(i);
        choose(cnt+1, i);
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> ints[i];
    }

    choose(0, -1);
    cout << answer;

    return 0;
}