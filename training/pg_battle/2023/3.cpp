#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP3(i, s, n) for(int i = (s); i < (int)(n); i++)
#define REP_R(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define REP3_R(i, s, n) for(int i = (int)(n) - 1; i >= (int)(s); i--)
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define ALL(x) x.begin(),x.end()

#define INF (int)1e9
#define LLINF (long long)1e18
#define PI 3.141592653589

#define VI vector<int>
#define VL vector<ll>
#define VVI vector<vector<int> >
#define VVL vector<vector<ll> >


int main(){
    FAST;
    string A10;
    cin >> A10;
    string B2;
    cin >> B2;

    vector<char> B10;
    REP(i,B2.size()){
        if(B2[i] == '1') 
    }
    if(A10 > B10) cout << '>' << endl;
    else if(A10 == B10) cout << '=' << endl;
    else cout << '<' << endl;
    return 0;
}

