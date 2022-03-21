#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

int main()
{
    LL a, b ,c;
    int k;
    cin >> k;
    for(int i = 1; i <= k; i ++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        LL sum = a + b;

        printf("Case #%d: ", i);
        if(a >= 0 && b >= 0 && sum < 0) printf("true\n");
        else if(a < 0 && b < 0 && sum >= 0) printf("false\n");
        else if(c < a + b) printf("true\n");
        else printf("false\n");
    }

    return 0;
}