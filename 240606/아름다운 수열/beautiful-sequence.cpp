#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ans, a, b;

bool isBeautiful(vector<int>& sub)
{
    int diff = sub[0] - b[0];
    for(int i=1; i<m; i++)
    {
        if((sub[i] - b[i]) != diff) return false;
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    a = vector<int>(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cin >> m;
    b = vector<int>(m);
    for(int i=0; i<m; i++) cin >> b[i];
    sort(b.begin(), b.end());

    for(int i=0; i<=n-m; i++)
    {
        vector<int> temp;
        for(int j=i; j<i+m; j++)
        {
            temp.push_back(a[j]);
        }
        sort(temp.begin(), temp.end());
        if(isBeautiful(temp)) ans.push_back(i+1);
    }

    cout << ans.size() << "\n";
    for(auto a : ans) cout << a << "\n";

    return 0;
}