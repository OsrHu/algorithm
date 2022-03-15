#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

int q, k, m;
vector<PII> path;

int gcd(int a,int b)
{
    return b ? gcd(b, a % b) : a;
}

bool cmp(PII a , PII b){
	if(a.x != b.x) return a.x < b.x ;
	return a.y < b.y ;
}


bool is_prime(int x)
{
    if(x <= 2) return false;
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int add(int x)
{
    int sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
// 1-6
void dfs(int sum, int idx, int num)
{       
    if(idx > k || sum > m || sum + (k - idx) * 9 < m) return ;

    if(sum == m && idx == k && num > pow(10, k - 1) && num < pow(10, k))
    {   
        int n = add(num + 1);
        if(is_prime(gcd(m, n)))
            path.push_back({n, num});

        return ;
    }

    for(int i = 0; i <= 9; i ++)
    {       
        dfs(sum + i, idx + 1, num * 10 + i);
    }
}




int main()
{   
    cin >> q;
    for(int i = 1; i <= q; i ++)
    {   
        cin >> k >> m;
        cout << "Case " << i << endl;
        path.clear();

        for(int num = 1; num <= 9; num ++)
            dfs(num, 1, num);
        
        if(path.size() == 0)
        {
            cout << "No Solution\n"; 
        }
        else
        {   
            sort(path.begin() , path.end() , cmp) ;
            for(int j = 0; j < path.size(); j ++)
            {
                auto item = path[j];
                cout << item.first << " " << item.second << endl;
            }
        }
    }

    return 0;
}