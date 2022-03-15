#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<cctype>
#include<string>
#include<sstream>
#include<queue>
#include<cmath>
#include<queue>

using namespace std;

const int N = 1e6 + 10;

int n, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    vector<int> res;
    int cnt = 0;
    int tmp;
    priority_queue<int,vector<int>, greater<int>> q; 
    for(int i = 0; i < n; i ++)
    {   
        cin >> tmp;
        q.push(tmp);
        while(q.size() > k)
        {
            q.pop();
        }
    }

    bool is_first = false;
    int s = q.size();
    while(q.size())
    {
        int t = q.top();
        q.pop();
        
        res.push_back(t);

    }

    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i ++)
    {
        if(i != 0) cout  << " ";
        cout << res[i];
    }

    return 0;
    
}