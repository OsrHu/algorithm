#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

const int N = 40;

int n;
unordered_map<int, int> pos, l, r;
int postorder[N], inorder[N];
queue<int> q;
vector<int>ans;

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];

    int k = pos[root];

    if(il < k) l[root] = build(il, k-1, pl, pl + k - 1 - il);
    if(k < ir) r[root] = build(k+1, ir, pr - ir + k, pr-1);

    return root; 
}

void bfs(int root)
{
    q.push(root);
    while(!q.empty())
    {
        int t = q.front();
        ans.push_back(t);
        q.pop();
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }

    
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> postorder[i];
    }

    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n-1, 0, n-1);

    bfs(root);

    for(int i = 0; i < ans.size(); i ++ )
    {
        if(i) cout <<" ";
        cout<< ans[i];
        
    }

    return 0;
}


