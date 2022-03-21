#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 1010;

int n;
int inorder[N], preorder[N],postorder[N];
// unordered_map<int, int> l,r;
int cnt;

bool build(int il, int ir, int pl, int pr, int type)
{   
    if(il > ir) return true;

    int root = preorder[pl];
    int k;
    if(type == 0)
    {
        for(k = il; k <= ir; k ++)
        {
            if(inorder[k] == root) break;
        }
        if(k > ir) return false;
    }
    else
    {
        for(k = ir; k >= il; k --)
        {
            if(inorder[k] == root) break;
        }
        if(k < il) return false;
    }

    bool res = true;
    if(!build(il,k-1,pl + 1, k - il + pl, type)) res =false;
    if(!build(k+1,ir,k - il + pl + 1, pr, type)) res =false;
    postorder[cnt ++] = root;
    return res;
}

int main()
{   
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> preorder[i];
        inorder[i] = preorder[i];
    }

    sort(inorder, inorder + n);

    if(build(0, n-1, 0, n-1, 0))
    {
        cout << "YES" << endl;
        for(int i = 0; i < cnt; i ++)
        {   
            if(i) cout << " ";
            cout << postorder[i];
        }
    }
    else
    {
        reverse(inorder, inorder + n);
        cnt = 0;
        if(build(0, n-1, 0, n-1, 1))
        {
            cout << "YES" << endl;
            for(int i = 0; i < cnt; i ++)
            {
                if(i) cout << " ";
                cout << postorder[i];
                
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
}

