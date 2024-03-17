#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node *prev, *next;

    Node(int data) :
        data(data),
        prev(nullptr),
        next(nullptr) {}
};

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<int, Node*> umap;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        Node *node = new Node(i);
        umap[i] = node;
    }

    int Q, a;
    cin >> Q;
    for(int q=0; q<Q; q++)
    {
        cin >> a;
        if(a == 1)
        {
            int i;
            cin >> i;
            Node *now = umap[i];
            if(now->prev != nullptr) now->prev->next = now->next;
            if(now->next != nullptr) now->next->prev = now->prev;
            now->prev = nullptr;
            now->next = nullptr;

        }
        else if(a == 2)
        {
            int i, j;
            cin >> i >> j;
            Node *now = umap[i];
            Node *pre = umap[j];
            if(now->prev != nullptr)
            {
                now->prev->next = pre;
                pre->prev = now->prev;
                pre->next = now;
                now->prev = pre;
            }
            else
            {
                now->prev = pre;
                pre->next = now;
            }
        }
        else if(a == 3)
        {
            int i, j;
            cin >> i >> j;
            Node *now = umap[i];
            Node *nex = umap[j];
            if(now->next != nullptr)
            {
                now->next->prev = nex;
                nex->next = now->next;
                nex->prev = now;
                now->next = nex;
            }
            else
            {
                now->next = nex;
                nex->prev = now;
            }
        }
        else if(a == 4)
        {
            int i;
            cin >> i;
            Node *now = umap[i];
            if(now->prev == nullptr) cout << 0 << " ";
            else cout << now->prev->data << " ";
            if(now->next == nullptr) cout << 0 << endl;
            else cout << now->next->data << endl;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(umap[i]->next == nullptr) cout << 0 << " ";
        else cout << umap[i]->next->data << " ";
    }

    return 0;
}