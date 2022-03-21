#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100005;

int a[N];

bool is_prime(int x)
{
    if(x < 2) return false;
    
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }

    return true;
}

struct Factor
{
    int p, k;
};

int main()
{
    int n, num;
    cin >> n;
    num = n;
    vector<int> primes;

    int cnt = 0;
    for(int i = 0; i < N; i ++)
    {
       if(is_prime(i))
       {
            a[cnt ++] = i;
       }
    }

    vector<Factor> ans;
    for(int i = 0; i < cnt; i ++)
    {   
        if(n == 0) break;
        int k = 0;
        while(n % a[i] == 0)
        {
            k ++;
            n /= a[i];
        }
        if(k ==0) continue;

        Factor f = {a[i], k};
        ans.push_back(f);
    }

    cout << num << "=";
    
    if(ans.size() != 0)
    {
        if(ans[0].k == 1)   cout << ans[0].p;
        else    cout << ans[0].p << "^" << ans[0].k;
    }
    else cout << num;

    for(int i = 1; i < ans.size(); i ++)
    {   
        cout << "*";
        if(ans[i].k == 1)   cout << ans[i].p;
        else    cout << ans[i].p << "^" << ans[i].k;
    }

}