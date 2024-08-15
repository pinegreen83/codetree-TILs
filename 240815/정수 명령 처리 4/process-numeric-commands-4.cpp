#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int now;
    int capacity;
    int* nums;

    void reallocate() {
        int tempCapacity = capacity * 2;
        int* temp = new int[tempCapacity];
        int j = 0;
        for(int i=now; i<size; i++) {
            temp[j++] = nums[i];
        }
        delete[] nums;
        nums = temp;
        capacity = tempCapacity;
        now = 0;
        size = j;
    }

public:
    Queue() : size(0), now(0), capacity(2) {
        nums = new int[capacity];
    }

    ~Queue() {
        delete[] nums;
    }

    void push(int x) {
        if(size == capacity) {
            reallocate();
        }
        nums[size++] = x;
    }

    int pop() {
        if(empty()) return -1;
        int result = nums[now++];
        if(now == size)
        {
            now = 0;
            size = 0;
        }
        return result;
    }

    int getSize() const {
        return size - now;
    }

    bool empty() const {
        return size == now;
    }

    int front() const {
        if(empty()) return -1;
        return nums[now];
    }

    int back() const {
        if(empty()) return -1;
        return nums[size-1];
    }
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, num;
    cin >> n;

    Queue q;
    string str;
    for(int i=0; i<n; i++) {
        cin >> str;
        if(str == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if(str == "pop")
        {
            cout << q.pop() << "\n";
        }
        else if(str == "size")
        {
            cout << q.getSize() << "\n";
        }
        else if(str == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if(str == "front")
        {
            cout << q.front() << "\n";
        }
        else
        {
            cout << q.back() << "\n";
        }
    }

    return 0;
}