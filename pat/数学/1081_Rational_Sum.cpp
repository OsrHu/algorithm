#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

int n;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    LL a = 0, b = 1;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        LL c,d;
        scanf("%lld/%lld", &c, &d);

        LL t = gcd(c, d);
        c = c / t, d = d / t;

        t = gcd(b, d);
        a = d / t * a + b / t * c;
        b = b / t * d;

        t = gcd(a, b);
        a = a / t, b = b / t;
    }

    if(b == 1) cout << a;
    else
    {
        if(a >= b)printf("%lld ", a / b);
        printf("%lld/%lld", a % b, b);
    }

    return 0;
}