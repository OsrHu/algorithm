#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int n, k;
unordered_map<string, vector<pair<string, int>>> g;
unordered_map<string, int> total;
unordered_map<string, bool> st;

int dfs(string u, vector<string>& nodes)
{
    st[u] = true;
    nodes.push_back(u);

    int sum = 0;
    for(auto egde: g[u])
    {
        sum += egde.second;
        string v = egde.first;
        if(!st[v]) sum +=dfs(v, nodes);
    }

    return sum;
}

int main()
{
    cin >> n >> k;
    while(n --)
    {
        string a,b;
        int c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        total[a] += c;
        total[b] += c;
    }

    vector<pair<string, int>> res;
    for(auto item: total)
    {
        string ver = item.first;
        vector<string> nodes;
        int sum = dfs(ver, nodes) / 2;

        if(nodes.size() > 2 && sum > k)
        {
            string boos = nodes[0];
            for(string people: nodes)
            {
                if(total[boos] < total[people])
                    boos = people;
            }
            res.push_back({boos, nodes.size()});
        }
    }

    sort(res.begin(), res.end());
    
    cout << res.size() << endl;
    for(auto item: res) cout << item.first << " " << item.second << endl;

    return 0;
}