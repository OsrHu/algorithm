#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

const int N = 1e4 + 10;

int n;
int s[N];
int weight[N];

int main()
{
    cin >> n;
    vector<int>v;
    for(int i =1 ; i <= n; i ++)
    {
        cin >> s[i];
        v.push_back(s[i]);
    }

    sort(v.begin(), v.end(), greater<int>());
    unordered_map<int, int>pos, poss;
    for(int i = 0; i < v.size(); i ++)
    {   
        pos[v[i]] = i + 1;
    }

    
    v.clear();
    for(int i = 1; i <= n; i ++)
    {
        cin >> weight[i];
        poss[weight[i]] = i;
        v.push_back(weight[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i = n; i >= 1; i --)
    {
        if(i != n) cout << " ";

        cout << poss[v[pos[s[i]] - 1]];
    }



}