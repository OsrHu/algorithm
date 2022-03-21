#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10;

int n;
int w[N], ne[N];

int main()
{   
    int l1, l2;
    cin >> l1 >> l2 >> n;
    for(int i = 0; i < n; i ++)
    {
        int address, data, next;
        cin >> address >> data >> next;
        w[address] = data;
        ne[address] = next;
    }

    vector<int> v1, v2;
    for(int i = l1; ~i; i = ne[i])
    {
        v1.push_back(i);
    }
    for(int i = l2; ~i; i = ne[i])
    {
        v2.push_back(i);
    }
    if(v1.size() < v2.size())
        swap(v1, v2);
    
    reverse(v2.begin(), v2.end());

    vector<int> ans;
    int j = 0;
    for(int i = 0; i < v1.size(); i ++)
    {
        ans.push_back(v1[i]);
        if((i + 1) % 2 == 0 && j < v2.size()) ans.push_back(v2[j++]);
    }

    for(int i = 0; i < ans.size();i ++)
    {
        if(i + 1 != ans.size()) printf("%05d %d %05d\n", ans[i], w[ans[i]], ans[i + 1]);
        else printf("%05d %d -1\n", ans[i], w[ans[i]]);
    }

    return 0;
}