// 离散化
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N =  10010;

int m,n;
int in[N],pre[N],seq[N];
unordered_map<int,int> pos;
int depth[N], p[N];

int build(int il,int ir,int pl, int pr,int d)
{
    int root = pre[pl];
    int k = root;
    
    depth[root] = d;
    if (il < k) p[build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), d + 1)] = root;
    if (k < ir) p[build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, d + 1)] = root;

    return root;
}


int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> pre[i];
        seq[i] = pre[i];
    }

    sort(seq, seq + n);

    for(int i = 0; i < n ; i ++)
    {
        pos[seq[i]] = i;
        in[i] = i;
    }

    for(int i = 0; i < n; i ++)
    {
        pre[i] = pos[pre[i]];
    }

    build(0, n-1, 0, n-1, 0);

    while(m --)
    {   
        int a,b;
        cin >> a >> b;
        if(pos.count(a) && pos.count(b))
        {
            a = pos[a], b = pos[b];
            int x = a, y = b;
            while(a != b)
            {
                if(depth[a] > depth[b]) a = p[a];
                else b = p[b];
            }
            if (a != x && a != y) printf("LCA of %d and %d is %d.\n", seq[x], seq[y], seq[a]);
            else if (a == x) printf("%d is an ancestor of %d.\n", seq[x], seq[y]);
            else printf("%d is an ancestor of %d.\n", seq[y], seq[x]);
        }
        else if (pos.count(a) == 0 && pos.count(b) == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos.count(a) == 0)
            printf("ERROR: %d is not found.\n", a);
        else
            printf("ERROR: %d is not found.\n", b);
    }

    return 0;


}
