#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
#include<sstream>
#include<cctype>
#include<queue>

using namespace std;

const int N = 30;

int n;
unordered_map<int, int> l, r, pos;
int inorder[N], preorder[N];

int build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];

    if(il < k) l[root] = build(il, k - 1, pl + 1, pl + k - il);
    if(k < ir) r[root] = build(k + 1, ir, pl + k - il + 1, pr);

    return root;
}
queue<int>q;
vector<int>ans[N];
unordered_map<int,int>level;
int max_level = 0;
void bfs(int root)
{
    q.push(root);
    level[root] = 0;

    while(q.size())
    {
        int t = q.front();
        ans[level[t]].push_back(t);
        max_level = max(max_level, level[t]);

        q.pop();

        if(l.count(t))
        {
            q.push(l[t]);
            level[l[t]] = level[t] + 1;
        };
        if(r.count(t))
        {
            q.push(r[t]);
            level[r[t]] = level[t] + 1;
        }
        
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    for(int i = 0; i < n; i ++)
    {
        cin >> preorder[i];
    }

    int root = build(0, n - 1, 0, n - 1);

    bfs(root);

    for(int i = 0; i <= max_level; i ++)
    {
        if(i != 0) cout << " ";
        cout << ans[i][0];
    }
    return 0;
}
