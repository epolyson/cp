#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int main(){
    FAST;
    ll n;
    cin >> n;

    while(n%2 == 0) n/=2;
    while(n%3 == 0) n/=3;
    cout << (n > 1 ? "No" : "Yes") << endl;
    return 0;
}