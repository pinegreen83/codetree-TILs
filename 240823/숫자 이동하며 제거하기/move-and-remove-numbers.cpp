#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<bool> visited(n, false);
    bool clock = true;
    int idx = 0, cnt = 0, move = 0;
    while(cnt < nums.size()) {
        while(move > 0) {
            if(clock) idx++;
            else idx--;
            if(idx == nums.size()) idx = 0;
            else if(idx == -1) idx = nums.size()-1;
            if(visited[idx]) continue;
            move--;
        }
        move = abs(nums[idx]);
        cout << nums[idx] << " ";
        if(nums[idx] < 0) clock = false;
        else clock = true;
        visited[idx] = true;
        cnt++;
    }

    return 0;
}