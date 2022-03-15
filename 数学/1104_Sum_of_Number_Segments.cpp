#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long double sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        long double x;
        cin >> x;
        sum += x * i * (n - i + 1) ; 
    }

    printf("%.2llf", sum);
    return 0;
}