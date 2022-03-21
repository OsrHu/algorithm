//  最后的测试点， 有0这个数据
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

const int N = 40, INF = 0x3f3f3f3f;

int n;
unordered_map<int, int> l, r, pos;
int inorder[N];
bool is_first = true;

int build(int il, int ir)
{
    int root = INF;
    for(int i = il; i <= ir; i ++)
    {
        if(root > inorder[i])
            root = inorder[i];
    }
    int k = pos[root];

    if(il < k) l[root] = build(il, k - 1);
    if(k < ir) r[root] = build(k + 1, ir);

    return root;
}

void bfs(int root)
{
    queue<int> q;

    q.push(root);

    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        if(!is_first) cout << " " << t;
        else cout << t;

        if(is_first)
        {
            is_first =false;
        }
        
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]); 
    }
    
}

int main()
{   

    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >>  inorder[i];
        pos[inorder[i]] = i;
    }

    int root = build(0, n - 1);
    bfs(root);

    return 0;
}

