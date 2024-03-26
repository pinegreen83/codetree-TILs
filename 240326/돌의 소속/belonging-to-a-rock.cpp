#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, q;
    cin >> n >> q;
    vector<int> stones(n+1);
    vector<vector<int>> group(n+1, vector<int>(4));
    for(int i=1; i<=n; i++) cin >> stones[i];
    for(int i=1; i<=n; i++)
    {
        group[i][stones[i]]++;
        for(int j=1; j<=3; j++)
        {
            group[i][j] += group[i-1][j];
        }
    }

    while(q > 0)
    {
        int a, b;
        cin >> a >> b;
        for(int i=1; i<=3; i++)
        {
            cout << group[b][i] - group[a-1][i] << " ";
        }
        cout << "\n";
        q--;
    }

    return 0;
}