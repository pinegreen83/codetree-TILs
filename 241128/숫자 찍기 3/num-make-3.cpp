#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        nums[i][0] = 1;
        nums[i][i] = 1;
        for(int j=1; j<i; j++) {
            nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
        }
    }

    if(m == 1) {
        for(auto num : nums) {
            for(auto nu : num) {
                if(nu == 0) cout << " " << " ";
                else cout << nu << " ";
            }
            cout << "\n";
        }
    }

    if(m == 2) {
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<n-i-1; j++) {
                cout << " ";
            }

            for(int j=0; j<=i; j++) {
                if(nums[i][j] == 0) cout << " " << " ";
                else cout << nums[i][j] << " ";
            }
            cout << "\n";
        }
    }

    if(m == 3) {
        for(int j=n-1; j>=0; j--) {
            for(int i=n-1; i>=j; i--) {
                if(nums[i][j] == 0) cout << " " << " ";
                else cout << nums[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}