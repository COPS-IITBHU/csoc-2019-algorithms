#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define MM 998244353
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define ll long long
#define gcd __gcd
int binarysearch(vector<int> v, int x)
{
    int l =0;
    int r = v.size()-1;
    int mid = l + (r-l)/2;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(v[mid]==x)
        {
            return mid;
        }
        else if(v[mid]>x)
        {
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;

}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cout << "Enter the number of element in the array: ";
    cin >> t;
    cout << "Enter the elements: ";
    vector<int> v;
    for(int j=0; j<t ;j++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    cout << "Enter the element you want to search: ";
    int z;
    cin >> z;
    int y = binarysearch(v,z);
    cout << "The index of the element in the given vector is " << y+1;
}
