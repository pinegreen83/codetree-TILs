#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> blocks(n);

    for(int i=0; i<n; i++)
    {
        cin >> blocks[i];
    }

    int start, end;
    for(int i=0; i<2; i++)
    {
        cin >> start >> end;
        vector<int> temp;
        for(int i=0; i<blocks.size(); i++)
        {
            if(start-1 <= i && i <= end-1) continue;
            else
            {
                temp.push_back(blocks[i]);
            }
        }
        blocks = temp;
    }

    cout << blocks.size() << endl;
    if(blocks.size())
    {
        for(auto i : blocks)
        {
            cout << i << endl;
        }
    }

    return 0;
}