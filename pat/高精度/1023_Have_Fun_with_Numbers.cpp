#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int a[10], b[10];
pair<bool, vector<int>> bv;

vector<int> mut(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(t);

    while(C.size() > 1 && C.back() ==0) C.pop_back();

    return C;
}


pair<bool, vector<int>> check_double(vector<int>&A,int b[])
{
    auto C = mut(A, 2);
    for(int i = C.size() - 1; i >= 0; i --)
    {
        b[C[i]] ++;
    }

    for(int i = 0; i < 10; i ++)
    {   
        // cout << i << " " << a[i] << " " << b[i] << endl;
        if(a[i] != b[i]) return {false, C};
    }

    return {true, C};
    

}

int main()
{
    string number;
    cin >> number;
    vector<int>A;
    for(int i = number.size() - 1; i >= 0; i --)
    {
        a[number[i] - '0'] ++;
        A.push_back(number[i] - '0');
    }

    if(check_double(A, b).first)
    {   
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }   
    auto C  = check_double(A, b).second;

    for(int i = C.size() - 1; i >= 0; i --)
    {
        cout << C[i];
    }

    
}