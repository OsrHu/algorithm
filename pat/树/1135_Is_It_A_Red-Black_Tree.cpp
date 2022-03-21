// 坑点 ：建树不成功？

#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 40;

int k, n;
unordered_map<int, int> l, r, pos;
bool ans;

int pre[N], in[N];

// sum表示以这个节点的左右子树的黑色数量
int build(int il,int ir, int pl, int pr,int& sum)
{   
    int root = pre[pl];
    int k = pos[abs(root)];

    if(k < il || k > ir)
    {
        ans = false;
        return 0;
    }

    int left = 0, right = 0;
    int lsum = 0, rsum = 0;
    if(il < k) left = build(il, k - 1, pl + 1, pl + k - il, lsum);
    if(k < ir) right = build(k + 1, ir, pl + k - il + 1, pr, rsum);


    if(lsum != rsum)
    {
        ans = false;
    }

    sum = lsum;

    if(root > 0) sum ++;
    else
    {
        if(left < 0 || right < 0) ans = false;
    }

    return root;

}

int main()
{
    cin >> k;
    while(k --)
    {
        cin >> n;
        for(int i = 0; i < n; i ++)
        {
            cin >> pre[i];
            in[i] = abs(pre[i]);
        }

        sort(in, in + n);

        pos.clear();
        for(int i = 0; i < n; i ++)
        {
            pos[in[i]] = i;
        }
        int sum = 0;
        ans = true;
        int root = build(0, n - 1, 0, n - 1, sum);

        if(root < 0) ans = false;

        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}