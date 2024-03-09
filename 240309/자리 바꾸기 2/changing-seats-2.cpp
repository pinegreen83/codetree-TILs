#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n+1);
    vector<vector<int>> moves(k, vector<int>(2));
    vector<unordered_set<int>> sets(n+1);
    for(int i=1; i<=n; i++)
    {
        nums[i] = i;
        sets[i].insert(i);
    }

    for(int i=0; i<k; i++)
    {
        cin >> moves[i][0] >> moves[i][1];
        int temp = nums[moves[i][0]];
        nums[moves[i][0]] = nums[moves[i][1]];
        nums[moves[i][1]] = temp;
        sets[nums[moves[i][0]]].insert(moves[i][1]);
        sets[nums[moves[i][1]]].insert(moves[i][0]);
        // cout << moves[i][0] << " " << moves[i][1] << " " << nums[moves[i][0]] << " " << nums[moves[i][1]] << endl;
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<k; j++)
        {
            int temp = nums[moves[j][0]];
            nums[moves[j][0]] = nums[moves[j][1]];
            sets[nums[moves[j][0]]].insert(moves[j][1]);
            nums[moves[j][1]] = temp;
            sets[nums[moves[j][1]]].insert(moves[j][0]);
            // cout << moves[j][0] << " " << moves[j][1] << " " << nums[moves[j][0]] << " " << nums[moves[j][1]] << endl;
        }
    }

    for(int i=1; i<=n; i++) cout << sets[i].size() << endl;

    return 0;
}