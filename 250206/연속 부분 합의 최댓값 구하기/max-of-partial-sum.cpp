#include <iostream>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Write your code here!
    int ans[n+1] = {0};
    for(int i=0; i<n; i++) {
        ans[i+1] = max(ans[i]+arr[i], arr[i]);
    }
    cout << ans[n];

    return 0;
}
