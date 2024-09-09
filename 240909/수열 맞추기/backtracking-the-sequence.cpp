#include <iostream>
using namespace std;

struct Node {
    int index;
    Node* prev;
    Node* next;

    Node(int a) : index(a), prev(nullptr), next(nullptr) {};
};

Node* Head;
Node* Tail;

void insertAtHead(Node* node) {
    if(Head == nullptr) {
        Head = Tail = node;
    }
    else {
        node->next = Head;
        Head->prev = node;
        Head = node;
    }
}

void insertAtTail(Node* node) {
    if(Tail == nullptr) {
        Head = Tail = node;
    }
    else {
        Tail->next = node;
        node->prev = Tail;
        Tail = node;
    }
}

void insertNextHead(Node* node) {
    if(Head == nullptr || Head == Tail) {
        insertAtTail(node);
    }
    else {
        node->prev = Head;
        node->next = Head->next;
        Head->next->prev = node;
        Head->next = node;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];

    int idx = 1;
    for(int i=n-1; i>=0; i--) {
        Node* now = new Node(idx++);
        switch(nums[i]) {
            case 1:
                insertAtHead(now);
                break;
            case 2:
                insertNextHead(now);
                break;
            case 3:
                insertAtTail(now);
                break;
        }
    }

    Node* start = Head;
    while(true) {
        cout << start->index << " ";
        if(start->next == nullptr) break;
        start = start->next;
    }

    return 0;
}