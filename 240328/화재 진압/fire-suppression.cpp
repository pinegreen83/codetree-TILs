#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> fires(n);
    vector<int> firestations(m);
    for(int i=0; i<n; i++)
    {
        cin >> fires[i];
    }
    for(int i=0; i<m; i++)
    {
        cin >> firestations[i];
    }

    int j = 0;
    for(int i=0; i<n; i++)
    {
        while(j < m-1 && abs(fires[i] - firestations[j]) > abs(fires[i] - firestations[j+1]))
        {
            j++;
        }

        ans = max(ans, abs(firestations[j]-fires[i]));
    }
    cout << ans;

    return 0;
}