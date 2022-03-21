#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;

int n;
int cnt;
struct Account
{
    string name, password;
}account[N];
vector<Account> ans;

void change(Account& a)
{
    for(auto& x: a.password)
    {
        if(x == '1') x = '@';
        if(x == '0') x = '%';
        if(x == 'l') x = 'L';
        if(x == 'O') x = 'o';
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        string name, password;
        cin >> name >> password;
        account[i] = {name, password};
    }

    for(int i = 0; i < n; i ++)
    {   
        string o = account[i].password;
        change(account[i]);
        if(o != account[i].password)
        {
            cnt ++;
            ans.push_back(account[i]);
        }
    }

    if(cnt != 0)
    {
        cout  << cnt << endl;
        for(int i = 0; i < ans.size(); i ++)
        {
            cout <<  ans[i].name << " " << ans[i].password << endl;
        }
    }
    else
    {
        if(n == 1) printf("There is %d account and no account is modified", n);
        else printf("There are %d accounts and no account is modified", n);
    }
   
    return 0;


}