#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout << '@' << ' ';
        }
        cout << '\n';
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j <= i) cout << ' ';
            else cout << '@';
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}