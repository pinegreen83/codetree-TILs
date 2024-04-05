#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;
    string start, goal;
    cin >> start >> goal;

    bool diff = false;
    for(int i=0; i<n; i++)
    {
        if(start[i] != goal[i]) diff = true;
        else
        {
            if(diff) ans++;
            diff = false;
        }
    }
    if(diff) ans++;
    cout << ans;

    return 0;
}