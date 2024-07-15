#include <iostream>

#define MAXN 100

using namespace std;

int places[MAXN+1];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i=1; i<=MAXN; i++) places[i] = -1;

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int num, place;
        cin >> num >> place;
        if(places[num] == -1) places[num] = place;
        else
        {
            if(places[num] != place)
            {
                places[num] = place;
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}