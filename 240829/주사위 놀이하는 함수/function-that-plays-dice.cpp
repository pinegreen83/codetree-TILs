#include <iostream>

#define MAX_N 10

using namespace std;

int n, nums[MAX_N];

void Backtrack(int idx, int last) {
    if(idx == n) {
        for(int i=0; i<n-1; i++) cout << nums[i] << "-";
        cout << nums[n-1] << "\n";
        return;
    }
    for(int i=last; i<=6; i++) {
        nums[idx] = i;
        Backtrack(idx+1, i); 
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    Backtrack(0, 1);

    return 0;
}