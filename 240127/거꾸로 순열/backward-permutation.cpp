#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> comb;
bool visited[9];

void perm(int idx)
{
    if(idx == n)
    {
        for(int i : comb)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i=n; i>=1; i--)
    {
        if(visited[i]) continue;

        visited[i] = 1;
        comb.push_back(i);
        perm(idx+1);
        visited[i] = 0;
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    perm(0);

    return 0;
}