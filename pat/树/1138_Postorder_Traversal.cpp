#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 50010;

int n;
unordered_map<int, int>l, r, pos;
int preorder[N], inorder[N];
vector<int>ans;

int build(int il,int ir, int pl, int pr)
{
    if(il > ir) return -1;

    int root = preorder[pl];
    int k = pos[preorder[pl]];

    l[root] = build(il, k-1, pl + 1, pl + k - il);
    r[root] = build(k + 1, ir, pl + k - il + 1, pr);

    return root;
}

void dfs(int u)
{
    if(u == -1) return ;

    dfs(l[u]);
    dfs(r[u]);
    ans.push_back(u);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> preorder[i];
    }

    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    int root = build(0, n-1, 0, n-1);

    dfs(root);

    cout << ans[0] << endl;


}