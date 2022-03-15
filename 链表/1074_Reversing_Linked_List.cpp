#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100010;

int n, k;
int h, e[N], ne[N];


int main()
{
    cin >> h >> n >> k;

    for(int i = 0; i < n; i ++)
    {
        int address, data, next;
        cin >> address >> data >> next;
        e[address] = data, ne[address] = next;
    }

    vector<int>v;
    for(int i = h; ~i; i = ne[i])
    {
        v.push_back(i);
    }

    for(int i = 0; i + k - 1< v.size(); i +=k)
    {
        reverse(v.begin() + i, v.begin() + i + k);
    }
    

    for(int i = 0; i + 1 < v.size(); i ++)
    {   
        
        printf("%05d %d %05d\n",v[i], e[v[i]], v[i + 1]);
    }

    printf("%05d %d -1\n",v[v.size() - 1], e[v[v.size() - 1]]);

    return 0;
}