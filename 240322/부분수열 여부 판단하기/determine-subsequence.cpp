#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> numA(n);
    vector<int> numB(m);
    for(int i=0; i<n; i++)
    {
        cin >> numA[i];
    }
    for(int i=0; i<m; i++)
    {
        cin >> numB[i];
    }

    bool isin = true;
    int j=0;
    for(int i=0; i<m; i++)
    {
        while(j < n && numA[j] != numB[i])
        {
            j++;
        }

        if(j == n)
        {
            isin = false;
            break;
        }
    }
    cout << (isin ? "Yes" : "No");

    return 0;
}