#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

void print(LL a, LL b)
{
    LL t = gcd(a, b);

    a = a/t, b = b/t;

    bool flag = true;
    if(a * b < 0) //如果乘法溢出，可以考虑约分
    {   
        flag = false;
    }

    if(!flag) printf("(-");

    if(abs(b) == 1)
    {
        printf("%lld", abs(a));
    }
    else
    {   
        if(abs(a) > abs(b)) printf("%lld ", abs(a)/abs(b));
        printf("%lld/%lld", abs(a) % abs(b), abs(b));
    }

    if(!flag) printf(")");
}

void add(LL a, LL b, LL c, LL d)
{      
    print(a, b);
    printf(" + ");
    print(c, d);
    printf(" = ");

    a = a * d + b * c;
    b = b * d;
    

    // cout << gcd(a, b) << endl;
    print(a, b);
    cout << endl;

}


void sub(LL a, LL b, LL c, LL d)
{      
    print(a, b);
    printf(" - ");
    print(c, d);
    printf(" = ");

    a = a * d - b * c;
    b = b * d;

    print(a, b);
    cout << endl;
}

void mul(LL a, LL b, LL c, LL d)
{      
    print(a, b);
    printf(" * ");
    print(c, d);
    printf(" = ");

    a = a * c ;
    b = b * d;

    print(a, b);
    cout << endl;
}

void div(LL a, LL b, LL c, LL d)
{      
    print(a, b);
    printf(" / ");
    print(c, d);
    printf(" = ");

    

    if(c == 0) printf("Inf");
    else
    {   

        a = a * d;
        b = b * c;
        print(a, b);
    }

    cout << endl;
}



int main()
{
    LL a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);


    add(a, b, c, d);
    sub(a, b, c, d);
    mul(a, b, c, d);
    div(a, b, c, d);

    return 0;
}