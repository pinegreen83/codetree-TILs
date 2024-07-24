#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    char diff;
    cin >> diff;
    int cnt[2] = {0};

    cnt[diff-'a']++;
    for(int i=1; i<n; i++)
    {
        char now;
        cin >> now;
        if(diff != now)
        {
            diff = now;
            cnt[diff-'a']++;
        }
    }
    cout << (cnt[0] > cnt[1] ? (cnt[1] + 1) : (cnt[0] + 1));

    return 0;
}