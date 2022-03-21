#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 40;

int n;
int inorder[N],postorder[N];
unordered_map<int, int>l, r, pos;
unordered_map<int, vector<int>> d;
int maxdepth;

int build(int il, int ir, int pl, int pr)
{   
    // if(il > ir) return 0;
    int root = postorder[pr];
    int k = pos[root];
   
    if(il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if(k < ir) r[root] = build(k+1, ir, pr - ir + k  ,pr -1);
     
    return root;
}


void dfs(int u, int depth)
{
    if(!u) return;
    maxdepth = max(depth, maxdepth);

    d[depth].push_back(u);
    dfs(r[u], depth + 1);
    dfs(l[u], depth + 1);

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    for(int i = 0; i < n;i ++)
    {
        cin >> postorder[i];
    }

    int root = build(0, n-1, 0, n-1);
    

    dfs(root, 0);
    int cnt = 0;
    for(int i = 0; i <= maxdepth; i ++)
    {
        if(i % 2 == 1)  reverse(d[i].begin(), d[i].end());

        for(int j = 0; j < d[i].size(); j ++)
            {   
                cout << d[i][j];
                if(++cnt != n) cout << " ";
            }
    }

}