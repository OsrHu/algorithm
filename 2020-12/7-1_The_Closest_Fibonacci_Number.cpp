#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e8 + 10, INF = 0x3f3f3f3f;

int n;
int a[1010];

// int fib(int x)
// {   
//     if(x <= 1 ) return x;
//     return fib(x - 1) + fib(x - 2);
// }

int main()
{
    cin >> n;

    a[0] = 0, a[1] = 1;
    int len = 0;
    for(int i = 2; i < 1010; i ++)
    {
        a[i] = a[i - 1] + a[i - 2];
        if(a[i] > 1e8)
        {
            len = i;
            break;
        }
    }

    int ans;
    // int MIN = INF;
    // for(int i = 0 ; i <= len; i ++)
    // {
    //     if(abs(a[i] - n) < MIN) 
    //     {
    //         MIN = abs(a[i] - n);
    //         ans = i;
    //     }
    // }
    
    int i = 0;
    while(a[i] <= n && i <= len) i ++;

    if(abs(a[i - 1] - n) <= abs(a[i] - n)) ans = i - 1;
    else ans = i;

    cout << a[ans] << endl;
    return 0;

    
}