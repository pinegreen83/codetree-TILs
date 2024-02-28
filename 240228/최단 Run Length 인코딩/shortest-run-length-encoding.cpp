#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int answer;
string a;
queue<char> q;

void RLEncoding()
{
    queue<char> temp = q;
    string enc = "";
    char now = temp.front();
    int num = 0;
    while(!temp.empty())
    {
        if(now != temp.front())
        {
            enc += now + to_string(num);
            now = temp.front();
            num = 1;
        }
        else num++;
        temp.pop();
    }
    enc += now + to_string(num);
    int len = enc.size();
    answer = min(answer, len);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i=0; i<a.size(); i++)
    {
        q.push(a[i]);
    }
    answer = INT_MAX;

    for(int i=0; i<a.size(); i++)
    {
        RLEncoding();
        char now = q.front();
        q.pop();
        q.push(now);
    }

    cout << answer;

    return 0;
}