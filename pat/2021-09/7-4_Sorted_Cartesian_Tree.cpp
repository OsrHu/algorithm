#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 35, INF = 0x3f3f3f3f;

int n;
vector<PII> v;
vector<int> ans;
unordered_map<int, int>pos, inorder,l, r, um;
unordered_map<int, bool> st;

bool cmp(PII a, PII b)
{
    return a.first < b.first;
}

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
    st[root] = true;

    while(q.size())
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
        int k, p;
        cin >> k >> p;
        um[p] = k;
        v.push_back(make_pair(k, p));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i ++)
    {
        inorder[i] = v[i].second;
    }

    for(int i = 0; i < n; i ++)
    {
        pos[inorder[i]] = i;
    }

    int root = build(0, n - 1);

    bfs(root);

    for(int i = 0; i < n; i ++)
    {
        if(i != 0) cout << " ";
        cout << um[ans[i]];
    }

    cout << endl;

    for(int i = 0; i < n; i ++)
    {
        if(i != 0) cout << " ";
        cout << ans[i];
    }

}