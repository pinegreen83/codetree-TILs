#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> umap;
vector<char> tree(100, '.');

void preorder(int start)
{
    if(tree[start] != '.')
    {
        cout << tree[start];
        preorder(start*2);
        preorder(start*2 + 1);
    }
}

void inorder(int start)
{
    if(tree[start] != '.')
    {
        inorder(start*2);
        cout << tree[start];
        inorder(start*2 + 1);
    }
}

void postorder(int start)
{
    if(tree[start] != '.')
    {
        postorder(start*2);
        postorder(start*2+1);
        cout << tree[start];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    umap['A'] = 1;
    tree[umap['A']] = 'A';
    for(int i=0; i<n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        int parent = umap[a];
        umap[b] = parent*2;
        tree[umap[b]] = b;
        umap[c] = parent*2 + 1;
        tree[umap[c]] = c;
    }

    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);

    return 0;
}