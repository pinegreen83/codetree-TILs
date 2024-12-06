#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    string seats;
    cin >> seats;

    priority_queue<int> pq;
    
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(seats[i] == '0') {
            cnt++;
        }
        else {
            pq.push(cnt);
            cnt = 0;
        }
    }

    int now = pq.top();
    pq.pop();
    pq.push(now - 2);
    pq.push(1);

    now = pq.top();
    pq.pop();
    pq.push(now - 2);
    pq.push(1);

    cout << pq.top();

    return 0;
}