#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a;
    cin >> n;

    string s;
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> a;
            pq.push(a);
        }
        else if(s == "pop")
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        else if(s == "size")
        {
            cout << pq.size() << endl;
        }
        else if(s == "empty")
        {
            cout << (pq.empty() ? 1 : 0) << endl;
        }
        else if(s == "top")
        {
            cout << pq.top() << endl;
        }
    }

    return 0;
}