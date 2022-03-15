//环的问题，最直接的做法就是扩充一倍hh
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

const int N = 1e5 + 10;

using namespace std;

int S, n, k;
int e[N], ne[N];
bool st[N];

int main()
{
    cin >> S >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        int address, data, next;
        cin >> address >> data >> next;
        e[address] = data, ne[address] = next;
    }

    vector<int> v, ans;

    for(int i = S; ~i; i = ne[i])
    {
        v.push_back(i);
    }

    int cnt ;
    if(v.size() % 2 == 1) cnt = 1;
    else cnt = 0;
    
    int j = v.size() - 1;
    k = k - 1;
    while(cnt != v.size())
    {
        if(!st[j])
        {   
            st[k] = true, st[j] = true;
            ans.push_back(v[k--]);
            ans.push_back(v[j--]);
            if(k < 0) k = n - 1;
            while(st[k]) k --;; 
            if(j < 0) j = n - 1;
            while(st[j] || j == k) j --;; 
            cnt +=2;
        }
        else
        {
            while(st[j] || j == k)
            { 
                j --;
                // j --;
            }
            st[k] = true, st[j] = true;
            ans.push_back(v[k--]);
            ans.push_back(v[j--]);
            if(k < 0) k = n - 1;
            while(st[k]) k --;; 
            if(j < 0) j = n - 1;
            while(st[j] | j == k) j --;; 
            cnt +=2;
        }
    }

    if(v.size() % 2 == 1)
    {
        for(int i = 0; i < v.size(); i ++)
        {
            if(st[i] == false)
            {
                ans.push_back(v[i]);
                break;
            }
        }
    }

    for(int i = 0; i < ans.size(); i ++)
    {
        if(i == ans.size() - 1) printf("%05d %d -1\n", ans[i], e[ans[i]]);
        else  printf("%05d %d %05d\n", ans[i], e[ans[i]], ans[i + 1]);
    }



}