#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10;

int l, n, k;
int w[N], ne[N];

int main()
{
    cin >> l >> n >> k;
    while(n --)
    {
        int address, data, next;
        cin >> address >> data >> next;
        w[address] = data, ne[address] = next; 
    }

    vector<int> v;
    for(int i = l; ~i; i = ne[i])
    {
        v.push_back(i);
    }
    vector<int> ans;
    int zushu = (v.size() + k - 1 )/ k;
    int cnt = 0;
    int i;
    for(i = 0; i +  k - 1< v.size(); i += k )
    {
        reverse(v.begin() + i, v.begin() + i + k);
        cnt ++;
    }

    if(cnt != zushu)
    {
        int number = v.size() % k;
        reverse(v.end() - number, v.end());
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i ++)
    {   
        if(i == v.size() - 1) printf("%05d %d -1\n", v[i], w[v[i]]);
        else printf("%05d %d %05d\n", v[i], w[v[i]], v[i + 1]);
    }

    return 0;

}