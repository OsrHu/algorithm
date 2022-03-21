/*

*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 10010;

int n;
int p[N], cnt[N], hc[N], ha[N];
bool st[N];

struct Edge
{
    int a,b;
}e[N];

struct Family
{
    int id, cnt, hc, ha;

    bool operator<(const Family &t) const
    {
        if(ha * t.cnt != t.ha * cnt) return ha * t.cnt > t.ha * cnt;
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
    cin >> n;
    
    int m = 0;
    while(n --)
    {
        int id,father,mother,k;
        cin >> id >> father >> mother >> k;
        st[id] = true;
        if(father != -1) e[m ++ ] = {id, father};
        if(mother != -1) e[m ++ ] = {id, mother};
        while(k --)
        {
            int child;
            cin >> child;
            e[m ++ ] = {id, child};
        }
        cin >> hc[id] >> ha[id];   
    }

    for(int i = 0; i < N ; i ++ ) p[i] = i, cnt[i] = 1;

    for(int i = 0; i < m; i ++)
    {
        int a = e[i].a, b = e[i].b;

        st[a] = st[b] = true;
        int pa = find(a), pb = find(b);
        if(pa != pb)
        {
            if(pb > pa) swap(pa,pb);
            cnt[pb] += cnt[pa];
            hc[pb] += hc[pa];
            ha[pb] += ha[pa];
            p[pa] = pb;
        }
    }

    vector<Family> family;
    for(int i = 0; i < N; i ++)
    {
        if(st[i] && p[i] == i)
        {
            family.push_back({i, cnt[i], hc[i], ha[i]});
        }
    }

    sort(family.begin(), family.end());

    cout << family.size() << endl;

    for(auto f: family)
    {
        printf("%04d %d %.3lf %.3lf\n", f.id, f.cnt, (double) f.hc / f.cnt, (double) f.ha / f.cnt);
    }

    return 0;


    





}