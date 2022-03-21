#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int msize, n;
int h[N];

bool is_prime(int x)
{
    if(x < 2) return false;
    
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }

    return true;
}

int find(int x)
{
    int t = x % msize;

    for(int i = 0; i < msize; i ++)
    {
        int j = (t + i * i) % msize;
        if(!h[j]) return j;
    }

    return -1;
}

int main()
{
    cin >> msize >> n;
    
    while(!is_prime(msize)) msize ++;

    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        int t = find(x);

        if (t == -1) printf("-");
        else
        {
            h[t] = x;
            printf("%d", t);
        }

        if(i != n - 1) cout << " ";
    }

    return 0;
}