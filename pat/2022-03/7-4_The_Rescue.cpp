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

#define xx first
#define yy second

using namespace std;

typedef pair<int, int> PII;

const int N = 110, M = 110;

int n, m, x, y;
char g[N][N];
int cnt = 0;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool st[N][N];
bool success[N][N], backsuccess[N][N];
vector<int>l[N];

struct Node
{
	int x, y, level;
};

int maxd;

vector<PII> A;
int path[N][M];
vector<int>tmp, tmp2;
int calc(int a, int b)
{
	return pow(a - x, 2) + pow(b - y, 2);
}

bool cmp(PII a, PII b)
{	
    if(calc(a.xx, a.yy) != calc(b.xx, b.yy)) return calc(a.xx, a.yy) > calc(b.xx, b.yy);
}

void bfs()
{
	queue<Node> q;
    memset(path,-1,sizeof(path));
	q.push({x ,y, 0});
	maxd = 0;
	st[x][y] = true;
	while(q.size())
	{
		auto t = q.front();
		q.pop();
    
		for(int i = 0; i < 4; i ++)
		{   

			int a = t.x + dx[i], b = t.y + dy[i];
			if(a <= 0 || a > n || b <= 0 || b > m) continue;
			if(g[a][b] == '#') continue;
			if(st[a][b]) continue;
            
			
			q.push({a, b, t.level + 1});
            path[a][b]=path[t.x][t.y]+1;
			st[a][b] = true;

			if(maxd == t.level + 1 && !success[a][b])
			{
				A.push_back(make_pair(a, b));
			}
			
			if(maxd <= t.level + 1 && !success[a][b])
			{
				maxd = t.level + 1;
				A.clear();
				A.push_back(make_pair(a, b));
			}
			
		}
	}
}

void dfs(int aa,int bb)
{   
    if(aa==x&&bb==y)return;
    int a,b;

    a=aa-1,b=bb;
    if(a>=1&&path[a][b]==path[aa][bb]-1 && st[a][b] == true)
    {   
        tmp.push_back(0);
        dfs(a,b);
        return;
    }

    a=aa,b=bb+1;
    if(b<=m&&path[a][b]==path[aa][bb]-1 && st[a][b] == true)
    {   
        tmp.push_back(1);
        dfs(a,b);
        return;
    }

    a=aa+1,b=bb;
    if(a<=n&&path[a][b]==path[aa][bb]-1 && st[a][b] == true)
    {
        tmp.push_back(2);
        dfs(a,b); 
        return;
    }

    a=aa,b=bb-1;
    if(b>=1&&path[a][b]==path[aa][bb]-1 && st[a][b] == true)
    {   
        tmp.push_back(3);
        dfs(a,b);
        return;
    }
}



int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			cin >> g[i][j];
			if(g[i][j] == '#') success[i][j] = true;
			if(g[i][j] == 'O') cnt ++;
			
			if(g[i][j] == 'X')
			{	
				success[i][j] = true;
				x = i;
				y = j;
			}
		}
		
	}
	vector<int>res;

    int next = 0;
	while(1)
	{   

        A.clear();
        memset(st, 0, sizeof st);
        tmp.clear();

        bfs();
        
		sort(A.begin(), A.end(), cmp);
		auto t = A[0];
        dfs(t.xx, t.yy);
        vector<int> tt = tmp;
        // cout << endl;
        int i;
        for(i = 0; i < A.size(); i ++)
        {   
            if(i != 0)
            {   
                tmp.clear();
                dfs(A[i].xx, A[i]. yy);
                // for(int i = 0; i < tt.size(); i ++) cout << tt[i];
                for(int j = 0; j < tmp.size() || j < tt.size(); j++)
                    {
                        if(tmp[j] != tt[j])
                        {
                            if(tmp[j] > tt[j])
                            {
                                break;
                            }
                            else 
                            {
                                tmp == tt;
                                break;
                            }
                        }
                    }
            }
        }
        
        tmp = tt;
        // cout << i << endl;
        for(int i = 0; i < tmp.size(); i ++) cout << tmp[i];
        memcpy(backsuccess, success, sizeof success);
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                if(backsuccess[i][j]) continue;

                int lasti = i, lastj = j;
                for(int k = 0; k < tmp.size(); k ++)
                {   
                    
                    int a = lasti + dx[tmp[k]], b = lastj + dy[tmp[k]];
                    if(a <= 0 || a > n || b <= 0 || b > m) continue;
                    if(g[a][b] == '#') continue;
                    
                    lasti = a, lastj = b;

                    if(g[a][b] == 'X') break;
                }
                
                if(lasti != i || lastj != j)
                {   
                    // cout  << i << " " << j << " " << lasti << " " << lastj << endl;
                    success[i][j] = true;
                    if(lasti != x || lastj != y) success[lasti][lastj] = false;
                }
            }
        }

        // memcpy(success, backsuccess, sizeof backsuccess);

		int sum = 0;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= m; j ++)
			{
				if(success[i][j] && g[i][j] == 'O') sum++;
			}
		}
        if(sum == cnt) break;
        
    }

        
        
	

	
}