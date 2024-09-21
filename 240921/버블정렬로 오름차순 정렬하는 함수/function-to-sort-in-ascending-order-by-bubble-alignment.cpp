#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t;
    cin >> n;

    t = n;
    vector<int> list(n);
    for(int i=0; i<n; i++) cin >> list[i];

    while(t-- > 1) {
        vector<int> temp;
        int now = list[0];
        for(int i=1; i<n; i++) {
            if(now > list[i]) {
                temp.push_back(list[i]);
            }
            else {
                temp.push_back(now);
                now = list[i];
            }
        }
        temp.push_back(now);
        list = temp;

        for(auto& l : list) cout << l << " ";
        cout << "\n";
    }

    return 0;
}