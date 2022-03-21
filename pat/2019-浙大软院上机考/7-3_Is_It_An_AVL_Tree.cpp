#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
#include<cctype>
#include<cmath>

using namespace std;

const int N = 40;

int k, n;
unordered_map<int, int> l, r,pos;
int preorder[N], inorder[N];


int build(int il, int ir, int pl, int pr)
{   
    int root = preorder[pl];
    int k = pos[root];

    if(il < k) l[root] = build(il, k - 1, pl + 1, pl + k - il);
    if(k < ir) r[root] = build(k + 1, ir, pl + k - il + 1, pr);

    return root;
}
bool ans = true;
int dfs(int u)
{   
    if(pos.count(u) == 0) return 0;

   

    int h = 0;

    int lh = dfs(l[u]);
    int rh = dfs(r[u]);

    if(abs(lh - rh) > 1)
    {
        ans = false;
    }

    return max(dfs(l[u]), dfs(r[u])) + 1;
    
    
}

int main()
{
    cin >> k;
    while(k --)
    {
        cin >> n;
        l.clear();
        r.clear();
        pos.clear();
        for(int i = 0; i < n; i ++)
        {
            cin >> preorder[i];
            inorder[i] = preorder[i];
        }

        sort(inorder, inorder + n);

        for(int i = 0; i < n; i ++) pos[inorder[i]] = i;

        
        int root = build(0, n-1, 0, n - 1);
        ans = true;
        dfs(root);

        if(!ans) cout << "No\n";
        else cout << "Yes\n";
        
    }
}