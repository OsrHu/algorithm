#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;

int t, n, m;
int g[N][N];
unordered_map<int, int> callpeoples;
unordered_map<int, int> backpeoples;

vector<int> ans[N];
int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool cmp(vector<int>a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    cin >> t >> n >> m;

    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] += c;
    }

    vector<int> people;
    for(int i = 1; i <= n; i ++)
    {   
        for(int j = 1; j <= n; j ++)
        {   
            if(g[i][j] > 0 && g[i][j] <= 5)
            {   
                callpeoples[i] ++;
                if(g[j][i] > 0)
                {
                    backpeoples[i] ++;
                }
            }
        }
        if(callpeoples[i] > t && (backpeoples[i]  * 5.0 <= callpeoples[i]) ) 
        {
            people.push_back(i);
        }
        
    }
    

    for(int i = 0; i < people.size(); i ++)
    {
        p[people[i]] = people[i];
    }

    for(int i = 0 ; i < people.size(); i ++)
    {   
        int a = people[i];
        int pa = find(a);

        for(int j = i + 1; j < people.size(); j ++)
        {   
            int b = people[j];
            int pb = find(b);
            if(pa != pb && g[a][b] && g[b][a])
            {   
                if(pb > pa) swap(pa, pb);
                p[pa] = pb;
            }
        }
    }

    int k = 0;
    vector<int> head;
    for(int i = 0; i < people.size(); i ++)
    {
        if(people[i] == p[people[i]])
        {
             k++;
             head.push_back(people[i]);
        }
    }
    if(k == 0)
    {
        cout << "None" << endl;
        return 0;
    }

    for(int i = 0; i < k; i ++)
    {   
        int root = head[i];
        ans[i].push_back(head[i]);
        for(int j = 0; j < people.size(); j ++)
        {      
            if(root == people[j]) continue;
            int x = find(people[j]);
            if(root == x) ans[i].push_back(people[j]);
        }
    }
    sort(ans, ans + k, cmp);
    for(int i = 0; i < k; i ++)
    {   
        cout << ans[i][0];
        for(int j = 1; j < ans[i].size(); j ++)
            cout << " " << ans[i][j];
        cout << endl;
    }

}