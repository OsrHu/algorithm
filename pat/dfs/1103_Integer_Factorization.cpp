#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, k, p;
vector<int> fac;
vector<int>ans, temp;

int s;
void dfs(int idx, int num, int target, int facsum)
{   

    if(num == k && target == 0 && s < facsum)  //到达目的
    {
        ans = temp;
        s = facsum;
        return ;
    }
    
    if(num >= k || target <= 0 || idx <= 0) //可行性剪纸
    {
        return ;
    }

    temp.push_back(idx);
    dfs(idx, num + 1, target - fac[idx], facsum + idx);
    temp.pop_back();

    dfs(idx- 1, num, target, facsum);


}

int main()
{
    cin >> n >> k >> p;
    int i = 0;
    int tmp = 0;
    while(tmp < n)
    {   
        tmp = pow(i, p);
        fac.push_back(tmp);
        i ++;
    }

    dfs(fac.size() - 1, 0, n, 0);


    if(ans.size() == 0) cout << "Impossible\n";
    else
    {
        cout << n << " = " << ans[0] << "^" << p;
        for(int i = 1 ; i < ans.size(); i ++)
        {
            cout << " + " << ans[i] << "^" << p; 
        }
    }
    

    return 0;
}