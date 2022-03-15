// 二分法必须考虑到一开始S1,S2,S3三范围的数据大小给定
// 以及一个点来看的话，其有四个点都可能是最优解
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

const int N = 1e4 + 10, INF = 0x3f3f3f3f;

int a[N], b[N], c[N];
int ans_min = INF;
int ans_x = 0, ans_y = 0, ans_z = 0;

int bsearch(int l, int r, int x, int d[])
{
    while(l < r)
    {   
        int mid = l + r >> 1;
        if(d[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l;
}

int bsearch1(int l, int r, int x, int d[])
{
    while(l < r)
    {   
        int mid = l + r + 1 >> 1;
        if(d[mid] <= x) l = mid;
        else r = mid - 1;
    }

    return l;
}



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

    sort(a, a + n1);
    sort(b, b + n2);
    sort(c, c + n3);
    

    for(int i = n1 - 1; i >= 0; i --)
    {   

        int j = bsearch(0, n2 - 1, a[i], b);
        int k = bsearch(0, n3 - 1, a[i], c);
        int t = calc(a[i], b[j], c[k]);
        if(ans_min > t)
        {
            ans_min = t;
            ans_x = a[i];
            ans_y = b[j];
            ans_z = c[k];
        }    
        // cout << a[i] << " " << b[j] << " " << c[k] << " " << t << endl;
    }

    for(int i = n2 - 1; i >= 0; i --)
    {   


        int j = bsearch(0, n1 - 1, b[i], a);
        int k = bsearch(0, n3 - 1, b[i], c);
        int t = calc(b[i], a[j], c[k]);
        if(ans_min > t)
        {
            ans_min = t;
            ans_x = b[i];
            ans_y = a[j];
            ans_z = c[k];
        }    
        // cout << a[i] << " " << b[j] << " " << c[k] << " " << t << endl;
    }

    for(int i = n3 - 1; i >= 0; i --)
    {   

        int j = bsearch(0, n2 - 1, c[i], b);
        int k = bsearch(0, n1 - 1, c[i], a);
        int t = calc(c[i], b[j], a[k]);
        if(ans_min > t)
        {
            ans_min = t;
            ans_x = c[i];
            ans_y = b[j];
            ans_z = a[k];
        }    
        // cout << a[i] << " " << b[j] << " " << c[k] << " " << t << endl;
    }







    printf("MinD(%d, %d, %d) = %d",ans_x, ans_y, ans_z, ans_min);

    return 0;

    
}