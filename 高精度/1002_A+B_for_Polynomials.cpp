#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

double a[N];
int res[N];

int main()
{
    int k;
    cin >> k;
    for(int i = 0; i < k;i ++)
    {
        int ex;
        double coeff;
        cin >> ex >> coeff;
        a[ex] += coeff;
    }
    
    cin >> k;
    for(int i = 0; i < k;i ++)
    {
        int ex;
        double coeff;
        cin >> ex >> coeff;
        a[ex] += coeff;
    }

    int res = 0;
    for(int i = N; i >= 0; i--)
    {
        if(a[i] != 0)
        {
            res++;
        }
    }

    cout << res;

    for(int i = N; i >= 0; i--)
    {
        if(a[i] != 0)
        {
            cout << " " << i << " ";
            printf("%.1lf", a[i]);
        }
    }
    
    return 0;

}