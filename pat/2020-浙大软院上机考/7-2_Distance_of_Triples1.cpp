#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10, INF = 0x3f3f3f3f;

int a[N], b[N], c[N];
LL ans_min = INF;
int ans_x = 0, ans_y = 0, ans_z = 0;

int calc(int x, int y, int z)
{
    return abs(x - y) + abs(y - z) + abs(z - x);
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    for(int i = 0; i < n1; i ++) cin >> a[i];
    
    for(int i = 0; i < n2; i ++) cin >> b[i];

    for(int i = 0; i < n3; i ++) cin >> c[i];

    sort(a, a + n1,greater<int>());
    sort(b, b + n2,greater<int>());
    sort(c, c + n3,greater<int>());
    
    for(int i = 0, j = 0, k = 0; i < n1 && j < n2 && k < n3;)
    {   
        int x = a[i], y = b[j], z = c[k];
        // LL t = min(((LL)max(max(x, y), z) - min(min(x, y), z)), ans_min);
        LL t = (LL)calc(x, y, z);

        if(ans_min > t)
        {   
            ans_min = t;
            ans_x = x;
            ans_y = y;
            ans_z = z;
            // printf("MinD(%d, %d, %d) = %d\n",ans_x, ans_y, ans_z, ans_min);
        }

        if(x >= y && x >= z) i ++;
        else if(y >= x && y >= z ) j ++;
        else k ++;
    }

    printf("MinD(%d, %d, %d) = %ld",ans_x, ans_y, ans_z, ans_min);

    
}