#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 40;

int n;
int inorder[N],preorder[N],postorder[N];
unordered_map<int,int>l,r,pos;
bool special = true;
vector<int> ans;


// 只有满二叉树才符合要求
void build(int prel, int prer, int postl, int postr)
{
    int root = preorder[prel];
    if(postr == postl)
    {
        ans.push_back(root);
        return ;
    }
    if(postr - postl == 1) special = false;
    if(root != postorder[postr]) return;
    else
    {   
        int i = postr - 1;

        while(postorder[i] != preorder[prel + 1] && i >= postl ) i --;
        
        if(postorder[i] == preorder[prel + 1]) 
        {
            build(prel + 1, i - postl + prel + 1, postl, i);
            ans.push_back(root);
            build(i - postl + prel + 1 + 1, prer, i + 1, postr -1);
        }

        if(i < postl) return;
        
    }
}


// 直接暴力枚举区间
// int dfs(int l1, int r1, int l2, int r2, string& in)
// {
//     if (l1 > r1) return 1;
//     if (pre[l1] != post[r2]) return 0;

//     int cnt = 0;
//     for (int i = l1; i <= r1; i ++ )  // 枚举左子树包含的节点数量
//     {
//         string lin, rin;
//         int lcnt = dfs(l1 + 1, i, l2, l2 + i - l1 - 1, lin);
//         int rcnt = dfs(i + 1, r1, l2 + i - l1 - 1 + 1, r2 - 1, rin);

//         if (lcnt && rcnt)
//         {
//             in = lin + to_string(pre[l1]) + ' ' + rin;
//             cnt += lcnt * rcnt;
//             if (cnt > 1) break;
//         }
//     }

//     return cnt;
// }



int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> preorder[i];
    }
    for(int i = 0; i < n;i ++)
    {
        cin >> postorder[i];
        pos[postorder[i]] = i;
    }

    build(0, n-1, 0, n-1);

    if(special) cout << "Yes" <<endl;
    else cout << "No" << endl;

    cout << ans[0];
    for(int i = 1;i < ans.size(); i ++)
    {
        cout << ' ' << ans[i];
    }

    cout << endl;
}





