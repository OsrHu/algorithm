#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<int, int> l, r, pos;
unordered_map<int, int> inorder, postorder;
vector<int>ans;

int build(int il,int ir, int pl, int pr)
{   
    int root = postorder[pr];
    int k = pos[root];
    ans.push_back(root);
    if(il < k) l[root] = build(il, k - 1, pl, pl + k - il - 1);
    if(k < ir) r[root] = build(k + 1, ir, pl + k - il, pr - 1);

    return root;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) cin >> postorder[i];
    
    for(int i = 0; i < n; i ++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    int root = build(0, n-1, 0, n-1);

    cout << ans[ans.size() - 1];

    
}