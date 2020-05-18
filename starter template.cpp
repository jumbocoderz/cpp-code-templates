/**********************
    Vikas Kumar Jha
    vkjha1010
**********************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
using namespace std;
using namespace __gnu_pbds;


#define ll          long long int 
#define ld          long double
#define mod         1000000007
#define fi          first
#define se          second
#define pb          push_back
#define mp          make_pair
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vb          vector<bool>
#define mii         map<ll,ll>
#define pqb         priority_queue<ll>
#define pqs         priority_queue<ll, vi, greater<ll> >
#define ps(x,y)     fixed << setprecision(y) << x
#define fast        ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);
#define w(t)        ll t; cin >> t; while(t--)  
#define fr(be,en)   for(ll i = be; i < en; i++)
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbd;
ll pow(ll x,ll y){ if(y==0) return 1; if(y%2==1) return (((pow(x,y/2)*pow(x,y/2)%mod)*x)%mod); else return (pow(x,y/2)*pow(x,y/2))%mod;}
vb prime;   vi spf; 
void sieve(ll n) 
{   prime.resize(n+1,true); prime[0]=prime[1]=false;
    spf.resize(n+1,1);  spf[2]=2;
    for(ll i=4;i<=n;i+=2){ prime[i]=false; spf[i]=2; } 
    for (ll p=3; p*p<=n; p+=2) 
    {   if (prime[p] == true) 
        {   spf[p]=p;
            for (int i=p*p; i<=n; i += p) 
            {   if(prime[i]==true)
                {   spf[i]=p;
                    prime[i] = false;
                }
            } 
        } 
    } 
} 


int main()
{
    fast;
  
}
