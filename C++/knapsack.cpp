#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pie 3.142857143
#define ll long long int
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define vi vector<int>
#define vlli vector<ll>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fv(i,a) for(auto i:a)
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define frv(i,c) for(auto i = c.begin(); i != c.end(); i++)

void solve()
{
    ll n, w;
    cin >> n >> w;
    vlli dp(w + 1, 0);
    fr(i, 0, n)
    {
        ll wt, vl;
        cin >> wt >> vl;
        for (ll j = w - wt; j >= 0; j--)
        {
            dp[j + wt] = max(dp[j + wt], dp[j] + vl);
        }

    }
    ll ans = 0;
    fr(i, 0, w + 1)
    {
        ans = max(ans, dp[i]);

    }
    cout << ans << endl;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }


    return 0;
}