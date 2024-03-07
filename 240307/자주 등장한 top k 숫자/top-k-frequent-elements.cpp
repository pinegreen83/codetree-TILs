#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, a;
    cin >> n >> k;
    unordered_map<int, int> umap;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(umap.find(a) == umap.end()) umap[a] = 1;
        else umap[a]++;
    }

    unordered_map<int, int>::iterator iter;
    vector<vector<int>> nums;
    for(iter=umap.begin(); iter!=umap.end(); iter++)
    {
        vector<int> temp(2);
        temp[0] = iter->second;
        temp[1] = iter->first;
        nums.push_back(temp);
    }

    sort(nums.rbegin(), nums.rend());
    for(int i=0; i<k; i++)
    {
        cout << nums[i][1] << " ";
    }

    return 0;
}