#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    string init, goal;
    cin >> init >> goal;

    int diff = 0;
    int iWhite = 0;
    int gWhite = 0;
    for(int i=0; i<n; i++)
    {
        if(init[i] != goal[i]) diff++;
        if(init[i] == 'W') iWhite++;
        if(goal[i] == 'W') gWhite++;
    }
    int ans = 0;
    if(iWhite > gWhite) ans = iWhite - gWhite;
    else ans = gWhite - iWhite;
    cout << (diff - ans) / 2 + ans;

    return 0;
}