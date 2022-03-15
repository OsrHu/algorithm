#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

const int N = 1e5 + 10;

int w[N], ne[N];

int main()
{
    int s, n;

    cin >> s >> n;

    for(int i = 0; i < n; i++)
    {
        int address, key, next;
        cin >> address >> key >> next;
        w[address] = key;
        ne[address] = next;
    }

    vector<int> v;
    set<int> se;

    for(int i = s; i != -1; i = ne[i])
    {
        v.push_back(i);
    }

    vector<int> a, b;
    for(int i = 0; i < v.size(); i ++)
    {
        if(se.count(abs(w[v[i]]))) b.push_back(v[i]);
        else a.push_back(v[i]);
        se.insert(abs(w[v[i]]));
    }

    for(int i = 0; i < a.size(); i ++)
    {
        if(i == a.size() - 1) printf("%05d %d -1\n", a[i], w[a[i]]);
        else printf("%05d %d %05d\n", a[i], w[a[i]], a[i + 1]);
    }

    for(int i = 0; i < b.size(); i ++)
    {
        if(i == b.size() - 1) printf("%05d %d -1\n", b[i], w[b[i]]);
        else printf("%05d %d %05d\n", b[i], w[b[i]], b[i + 1]);
    }


}