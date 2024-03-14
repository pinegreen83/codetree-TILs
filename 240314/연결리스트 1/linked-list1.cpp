#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *prev, *next;

    Node(string data) : 
        data(data),
        prev(nullptr),
        next(nullptr) {}
};

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    Node *init = new Node(str);
    Node* cur = init;
    int n, a;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> str;
            Node *pre = new Node(str);
            pre->prev = cur->prev;
            pre->next = cur;

            if(pre->prev != nullptr) pre->prev->next = pre;
            if(pre->next != nullptr) pre->next->prev = pre;
        }
        else if(a == 2)
        {
            cin >> str;
            Node *nex = new Node(str);
            nex->prev = cur;
            nex->next = cur->next;

            if(nex->prev != nullptr) nex->prev->next = nex;
            if(nex->next != nullptr) nex->next->prev = nex;
        }
        else if(a == 3)
        {
            if(cur->prev != nullptr) cur = cur->prev;
        }
        else if(a == 4)
        {
            if(cur->next != nullptr) cur = cur->next;
        }
        if(cur->prev == nullptr)
        {
            cout << "(Null) ";
        }
        else
        {
            cout << cur->prev->data << " ";
        }
        cout << cur->data << " ";
        if(cur->next == nullptr)
        {
            cout << "(Null)" << endl;
        }
        else
        {
            cout << cur->next->data << endl;
        }
    }

    return 0;
}