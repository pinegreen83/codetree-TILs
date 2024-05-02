#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> check(m+1, 1);
    check[1] = 0;
    for(int i=2; i*i<=m; i++)
    {
        if(check[i] == 0) continue;
        for(int j=i+i; j<=m; j+=i)
        {
            check[j] = 0;
        }
    }

    int ans = 0;
    for(int i=n; i<=m; i++)
    {
        if(check[i]) ans++;
    }
    cout << ans;

    return 0;
}