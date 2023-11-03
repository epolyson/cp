#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP3(i, s, n) for(int i = (s); i < (int)(n); i++)
#define REP_R(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define REP3_R(i, s, n) for(int i = (int)(n) - 1; i >= (int)(s); i--)
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int main(){
    FAST;
    string s;
    cin >> s;
    
    size_t x_pos = s.find('x');
    ll A  = stoll(s.substr(0,x_pos));
    ll B  = stoll(s.substr(x_pos+2));
    cout << A * B << "x^" << B-1 << endl;
    return 0;
}
