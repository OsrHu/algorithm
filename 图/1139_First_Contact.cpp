#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<string>
#define x first
#define y second

using namespace std;


const int N = 310;

int n, m, k;
unordered_map<int, vector<int>> v;
unordered_map<int, unordered_map<int, bool>> g;

int main()
{
    cin >> n >> m;
    while(m --)
    {
        string a, b;
        cin >> a >> b;
        int numa = abs(stoi(a)), numb = abs(stoi(b));

        if(a.size() == b.size())
        {
            v[numa].push_back(numb);
            v[numb].push_back(numa);
        }

        g[numa][numb] = g[numb][numa] = true;
    }

    cin >> k;
    while(k --)
    {   
        vector<pair<int, int>> res;
        string a, b;
        cin >> a >> b;
        int numa = abs(stoi(a)), numb = abs(stoi(b));

        for(int i = 0; i < v[numa].size(); i ++)
        {   
            auto c = v[numa][i];
            for(int j = 0; j < v[numb].size(); j ++)
            {   
                auto d = v[numb][j];

                if(numa != d && numb!= c && g[c][d])
                {
                    res.push_back({c, d});
                }
            }
        }

        sort(res.begin(), res.end());

        cout << res.size() << endl;

        for(int i = 0; i < res.size(); i ++)
        {   
            auto t = res[i];
            printf("%04d %04d\n", t.x, t.y);
        }

    }

    return 0;
}