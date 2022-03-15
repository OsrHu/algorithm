#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

const int N = 100010;

int n,k;
int h, e[N], ne[N];

int main()
{
    cin >> h >> n >> k;
    for(int i = 0; i < n;i ++)
    {
        int address, data, next;
        cin >> address >> data >> next;

        e[address] = data, ne[address] = next;
    }

    vector<int> v;
    for(int i = h; ~i; i = ne[i])
    {
        v.push_back(i);
    }

    unordered_set<int> s;
    vector<int>ans;
    for(auto address: v)
    {
        if(e[address] < 0)
        {   
            ans.push_back(address);
            s.insert(address);
        }
    }

    for(auto address: v)
    {
        if(!s.count(address) && e[address] <= k)
        {
             ans.push_back(address); 
             s.insert(address);
        }
    }

    for(auto address: v)
    {   
        if(!s.count(address) && e[address] > k)
        {
             ans.push_back(address); 
             s.insert(address);
        }
    }
        

    for(int i = 0; i < ans.size();i ++)
    {
        if(i + 1 != ans.size()) printf("%05d %d %05d\n", ans[i], e[ans[i]], ans[i + 1]);
        else printf("%05d %d -1\n", ans[i], e[ans[i]]);
    }

    return 0;

}