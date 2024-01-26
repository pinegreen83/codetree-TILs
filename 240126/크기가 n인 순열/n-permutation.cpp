#include <iostream>
#include <vector>

#define MAX_INT 8
using namespace std;

int n;
int visited[MAX_INT+1];
vector<int> comb;

void choose(int cnt)
{
    if(cnt == n)
    {
        for(auto i : comb)
            cout << i << " ";
        cout << endl;
    }
    for(int i=1; i<=n; i++)
    {
        if(visited[i]) continue;

        comb.push_back(i);
        visited[i] = 1;
        choose(cnt+1);
        comb.pop_back();
        visited[i] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    choose(0);

    return 0;
}