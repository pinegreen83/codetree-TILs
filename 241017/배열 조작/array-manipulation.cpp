#include <iostream>
#include <deque>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    string opers;
    cin >> opers;

    int n;
    cin >> n;

    deque<int> deq;
    for(int i=0; i<n; i++) {
        int now;
        cin >> now;
        deq.push_back(now);
    }

    bool isReverse = false;
    for(auto oper : opers) {
        if(oper == 'R') {
            if(isReverse) isReverse = false;
            else isReverse = true;
        }
        else {
            if(deq.empty()) {
                cout << "error";
                return 0;
            }
            if(isReverse) {
                deq.pop_back();
            }
            else deq.pop_front();
        }
    }

    if(deq.empty()) cout << "error";
    else {
        if(isReverse) {
            for(auto i=deq.rbegin(); i!=deq.rend(); i++) cout << *i << ' ';
        }
        else {
            for(auto i=deq.begin(); i!=deq.end(); i++) cout << *i << ' ';
        }
    }

    return 0;
}