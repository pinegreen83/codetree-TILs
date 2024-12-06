#include <iostream>

using namespace std;

int n;
string seats;

bool check(int mid) {
    int cnt = 0;
    int last = -1e9;

    for(int i=0; i<n; i++) {
        if(seats[i] == '1') {
            last = i;
        }
        else {
            if(i - last >= mid) {
                cnt++;
                last = i;
                if(cnt == 2) return true;
            }
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> seats;

    int left = 1, right = n;
    int ans = 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(check(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;

    return 0;
}