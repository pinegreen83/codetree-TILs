#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string strs;
    cin >> strs;

    unordered_map<char, int> umap;

    for(int i=0; i<strs.size(); i++)
    {
        umap[strs[i]] += i+1;
    }

    int now = INT_MAX;
    char first = '0';
    unordered_map<char, int>::iterator iter;
    for(iter=umap.begin(); iter!=umap.end(); iter++)
    {
        if(iter->second < now)
        {
            now = iter->second;
            first = iter->first;
        }
    }
    if(now > strs.size()) cout << "None";
    else cout << first;


    return 0;
}