#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n,k;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if(A.size() < B.size()) return add(B,A);

    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if(t) C.push_back(t);
    return C;
}

bool check_palindromic(vector<int>& C)
{   
    vector<int>D;
    D = C;
    reverse(D.begin(), D.end());
    if(C ==  D) return true;
    else return false;
}

int main()
{
    string s;
    cin >> s >> k;
    vector<int> A, B;
    for(int j = s.size() - 1; j >= 0; j --)
    {
        A.push_back(s[j] - '0');
    }

    if(!check_palindromic(A))
    {
        for(int i = 1;i <= k; i ++)
        {   
            B = A;
            reverse(B.begin(), B.end());
            A = add(A, B);
            reverse(A.begin(), A.end());
            if(check_palindromic(A) || i == k)
            {   
                
                for(int i = 0;i < A.size(); i ++)
                {
                    cout << A[i];
                }
                cout << endl;
                cout << i;
                break;
            } 

        }
    }
    else 
    {
        cout << s << endl << "0" << endl;
    }
    

    return 0;

    
   
    
}