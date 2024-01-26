#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> comb;

void choose(int cnt, int now)
{
    if(cnt == m)
    {
        for(int i : comb)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i=now+1; i<=n; i++)
    {
        comb.push_back(i);
        choose(cnt+1, i);
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    choose(0, 0);

    return 0;
}