//与1114一样
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 10010;

int n;
int p[N], cnt[N], ts[N];
bool st[N];

// unordered_map<int, int> students;

struct Edge
{
    int a, b;
}e[N];

struct Node
{
    int id, cnt, ts;
    
    bool operator<(const Node& t) const
    {
        if(ts != t.ts) return ts > t.ts;
        else if(cnt != t.cnt) return cnt < t.cnt;
        return id < t.id;
    }
};

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{       
    int m = 0;
    for(int i = 0; i < N; i ++)
    {
        p[i] = i;
        cnt[i] = 1;
        ts[i] = 0;
    }

    cin >> n;
    while(n --)
    {
        int id, k;
        cin >> id;
        st[id] = true;
        cin >> k;
        while(k --)
        {
            int b;
            cin >> b;
            e[m ++] = {id, b};
        }
        int total;
        cin >> total;
        ts[id] = total;
    }
    for(int i = 0; i < m; i ++)
    {
        int a = e[i].a, b = e[i].b;
        st[a] = true, st[b] = true;
        
        int pa = find(a), pb = find(b);
        
        if(pa != pb)
        {   
            if(pb > pa) swap(pa, pb);
            cnt[pb] += cnt[pa];
            ts[pb] += ts[pa]; 
            p[pa] = pb;
        }
    }

    vector<Node> v;
    for(int i = 0; i < N; i ++)
    {   
        if(p[i] == i && st[i])
        {   
            // cout << i << " " << cnt[i] << endl;
            v.push_back({i, cnt[i], ts[i]});
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i ++)
    {   
        printf("%04d %d %d\n", v[i].id, v[i].cnt, v[i].ts);
    }

    return 0;

}