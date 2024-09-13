#include <iostream>
#include <vector>

enum Alp {
    B,
    E,
    S,
    I,
    G,
    O,
    M
};

using namespace std;

int n, ans = 0;
vector<int> selected(7);
vector<vector<int>> nums(7);

void Backtrack(int cnt) {
    if(cnt == 7) {
        int a = selected[Alp::B] + selected[Alp::E]*2 + selected[Alp::S]*2 + selected[Alp::I];
        int b = selected[Alp::E] + selected[Alp::S] + selected[Alp::G] + selected[Alp::O];
        int c = selected[Alp::O]*2 + selected[Alp::M];

        if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0) ans++;
        return;
    }

    for(int i=0; i<nums[cnt].size(); i++) {
        selected[cnt] = nums[cnt][i];
        Backtrack(cnt+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int num;
    char now;
    for(int i=0; i<n; i++) {
        cin >> now >> num;

        switch(now) {
            case 'B':
                nums[Alp::B].push_back(num);
                break;
            case 'E':
                nums[Alp::E].push_back(num);
                break;
            case 'S':
                nums[Alp::S].push_back(num);
                break;
            case 'I':
                nums[Alp::I].push_back(num);
                break;
            case 'G':
                nums[Alp::G].push_back(num);
                break;
            case 'O':
                nums[Alp::O].push_back(num);
                break;
            case 'M':
                nums[Alp::M].push_back(num);
                break;
        }
    }

    Backtrack(0);
    cout << ans;

    return 0;
}