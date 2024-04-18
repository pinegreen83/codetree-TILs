#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<char, char>> umap;

void preorder(char start)
{
    if(start != '.')
    {
        cout << start;
        preorder(umap[start].first);
        preorder(umap[start].second);
    }
}

void inorder(char start)
{
    if(start != '.')
    {
        inorder(umap[start].first);
        cout << start;
        inorder(umap[start].second);
    }
}

void postorder(char start)
{
    if(start != '.')
    {
        postorder(umap[start].first);
        postorder(umap[start].second);
        cout << start;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        umap[a] = make_pair(b, c);
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0;
}