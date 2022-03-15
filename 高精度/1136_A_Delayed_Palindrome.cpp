#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n,k;

vector<int> add(vector<int>&A,vector<int>&B){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
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

void print(vector<int>& A, vector<int>& B, vector<int>&C)
{
    for(int i = A.size() - 1; i >= 0; i --) cout << A[i];
    cout << " + " ;
    for(int i = B.size() - 1; i >= 0; i --) cout << B[i];
    cout << " = ";
    for(int i = C.size() - 1; i >= 0; i --) cout << C[i];

    cout << endl;


}

int main()
{
    string s;
    cin >> s;
    vector<int> A, B, C;
    for(int j = s.size() - 1; j >= 0; j --)
    {
        A.push_back(s[j] - '0');
    }

    if(!check_palindromic(A))
    {
        for(int i = 1;i <= 10; i ++)
        {   
            B = A;
            reverse(B.begin(), B.end());
            C = add(A, B);
            print(A, B, C);

            if(check_palindromic(C))
            {   
                
                for(int i = C.size() - 1; i >= 0; i --) cout << C[i];

                cout << " is a palindromic number.\n";
                break;
            } 
            else
            {
                if(i == 10)
                {
                    cout << "Not found in 10 iterations.\n";
                }
            }

            // reverse(C.begin(), C.end());
            A = C;
        }
    }
    else 
    {
        for(int i = A.size() - 1; i >= 0; i --) cout << A[i];    
        cout << " is a palindromic number.\n";
    }
    

    return 0;

    
   
    
}