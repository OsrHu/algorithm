#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e3 + 10;

int tsize, msize, n;
int h[N];


int find(int x)
{
    int t = x % msize;

    for(int i = 0; i < tsize; i ++)
    {
        int j = (t + i) % tsize;
        if(h[j] == -1) return j;
    }

    return -1;
}

int main()
{   
    memset(h, -1, sizeof h);

    cin >> tsize >> msize >> n;
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;

        int t = find(x);

        h[t] = x;
    }

    int sum = 0;
    for(int i = 0; i < msize; i ++)
    {
        
        int t = i % msize;
        int cnt = 0;
        for(int j = 0; j <= tsize; j ++)
        {   
            cnt ++;

            int k = (i + j) % tsize;
            
            if(h[k] == -1)
            {
                break;
            } 
        }

        // if(cnt == tsize) cnt ++;
        sum += cnt;
    }
    printf("%.1f", (double)sum / msize);



}