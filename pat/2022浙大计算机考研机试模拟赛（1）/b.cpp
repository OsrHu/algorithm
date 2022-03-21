#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

typedef long long ll;

using namespace std;

const int N = 1e7 + 1e6;

int primes[N], cnt;
int a[N];
bool st[N];
unordered_map<int,int>pos, ne;

void get_primes(int n)
{
    for(int i = 2; i <= n ; i ++)
    {
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0 ;primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break; 
        }
    }
}

int n;
int main()
{

    scanf("%d", &n);

    get_primes(N);
    int num = 0;
    int last = -1;
    for(int i = 1; i < cnt - 1; i ++)
    {
        if(primes[i - 1] + primes[i + 1] == primes[i] * 2)
        {  
            if(last != -1) ne[last] = primes[i];
            pos[primes[i]] = num;
            a[num++] = primes[i];
            last = primes[i];
        }
    }


    while(n--)
    {   
        int t;
        cin >> t;
        if(pos.count(t))
        {
            printf("Yes\n");
            continue;
        }
        int p = lower_bound(a, a + num, t) - a;
        printf("No %d\n", a[p]);
    }

}