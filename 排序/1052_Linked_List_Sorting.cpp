#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100010;

int n;
int h,e[N], ne[N];
vector<int> v;

bool cmp(int a, int b)
{
    return e[a] < e[b];
}

int main()
{
    cin >> n >> h;

    for(int i = 0; i < n; i ++)
    {
        int address, key, next;
        cin >> address >> key >> next;
        e[address] = key, ne[address] = next;
    }


    for(int i = h; ~i; i = ne[i])
    {
        v.push_back(i);
    }

    sort(v.begin(), v.end(), cmp);


    if(v.size() > 0) printf("%d %05d\n", v.size(), v[0]);
    else cout << "0 -1" << endl;
    for(int i = 0; i < v.size(); i ++)
    {   
        if(i + 1 == v.size()) printf("%05d %d -1\n", v[i], e[v[i]]);
        else printf("%05d %d %05d\n", v[i], e[v[i]], v[i+1]);
    
    }
    return 0;

}
