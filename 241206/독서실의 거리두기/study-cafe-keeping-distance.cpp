#include <iostream>
#include <vector>

using namespace std;

int n;
string seats;

bool check(int mid) {
    vector<int> temp;
    for(int i=0; i<n; i++) {
        if(seats[i] == '1') temp.push_back(i);
    }

    int cnt = 0;
    if(temp.empty()) {
        for(int i=0; i<n && cnt < 2; i+=mid) {
            cnt++;
        }
        return cnt >= 2;
    }

    {
        int end = temp[0] - mid;
        for(int i=0; i<=end && cnt < 2; i+=mid) {
            cnt++;
        }
    }

    for(int i=0; i+1<(int)temp.size() && cnt < 2; i++) {
        int start = temp[i] + mid;
        int end = temp[i+1] - mid;
        for(int j=start; j<=end && cnt < 2; j+=mid) {
            cnt++;
        }
    }

    {
        int start = temp.back() + mid;
        for(int i=start; i<n && cnt < 2; i+=mid) {
            cnt++;
        }
    }

    return cnt >= 2;
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