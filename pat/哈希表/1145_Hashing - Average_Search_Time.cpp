//这道题考虑的点是当找不到这个值的时候， 要等于msize + 1;
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int msize, n, m;
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
    cin >> msize >> n >> m;
    
    while(!is_prime(msize)) msize ++;

    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        int t = find(x);

        if (t == -1) printf("%d cannot be inserted.\n", x);
        else
        {
            h[t] = x;
        }
    }

    int sum = 0;
    for(int i = 0; i < m; i ++)
    {
        int x;
        cin >> x;
        
        int t = x % msize;
        int cnt = 0;
        for(int j = 0; j < msize; j ++)
        {   
            cnt ++;

            int k = (t + j * j) % msize;
            
            if(h[k] == x || !h[k])
            {
                break;
            } 
        }

        if(cnt == msize) cnt ++;
        sum += cnt;
    }
    cout << sum << endl;

    printf("%.1lf", sum * 1.0 / m);


    return 0;
}