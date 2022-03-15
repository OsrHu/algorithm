//O(logn)
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

const int N = 50010;

int n, k;
struct Item
{
    int cnt;
    int id;
    bool operator<(const Item& t) const
    {
        if(cnt != t.cnt) return cnt > t.cnt;
        return id < t.id;
    }
}items[N];
unordered_map<int, int>um;
set<Item>s;

int main()
{
    cin >> n >> k;
    int id;
    cin >> id;
    um[id] = 1;
    items[0].cnt = um[id];
    items[0].id = id;
    s.insert(items[0]);
    for(int i = 1; i < n; i ++)
    {
        cin >> id;
    
        cout << id << ":";

        int cnt = 0;
        for(auto x: s)
        {
            cout << " " << x.id;
            cnt ++;
            if(cnt == k) break;
        }
        cout << endl;

        if(s.count({um[id], id}))
        {
            s.erase({um[id], id});
        }
        um[id] += 1;
        items[i].cnt = um[id];
        items[i].id = id;
        s.insert(items[i]);

        
    }

    return 0;
}