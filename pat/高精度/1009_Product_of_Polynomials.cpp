#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 2010;

double a[N],b[N];
double c[N];
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
        b[ex] += coeff;
    }

    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            int ex = i + j;
            c[ex] += a[i] * b[j];
        }
    }

    int res = 0;
    for(int i = N; i >= 0; i--)
    {
        if(c[i] != 0)
        {
            res++;
        }
    }

    cout << res;

    for(int i = N; i >= 0; i--)
    {
        if(c[i] != 0)
        {
            cout << " " << i << " ";
            printf("%.1lf", c[i]);
        }
    }
    
    return 0;

}