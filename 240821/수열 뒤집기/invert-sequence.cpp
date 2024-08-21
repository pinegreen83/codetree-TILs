#include <iostream>
#include <vector>

using namespace std;

int n, k, a1, a2, b1, b2;
vector<int> nums;

void swap(int start, int end) {
    while(start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int findPattern() {
    vector<int> original(nums);
    int cnt = 0;

    while(true) {
        cnt++;
        swap(a1, a2);
        swap(b1, b2);

        if(nums == original) break;
    }

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;

    nums = vector<int>(n+1);
    for(int i=1; i<=n; i++) nums[i] = i;
    cin >> a1 >> a2 >> b1 >> b2;

    int cnt = findPattern();
    k %= cnt;
    for(int t=1; t<=k; t++) {
        swap(a1, a2);
        swap(b1, b2);
    }

    for(int i=1; i<=n; i++) cout << nums[i] << "\n";

    return 0;
}