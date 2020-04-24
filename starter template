/**********************
    Vikas Kumar Jha
	  vkjha1010
**********************/
#include<bits/stdc++.h>
using namespace std;

#define int			long long int 
#define double		long double
#define mod			1000000007
#define fi			first
#define se			second
#define pb			push_back
#define mp			make_pair
#define pii			pair<int,int>
#define vi			vector<int>
#define vb			vector<bool>
#define mii			map<int,int>
#define pqb			priority_queue<int>
#define pqs			priority_queue<int, vi, greater<int> >
#define ps(x,y)	 	fixed << setprecision(y) << x
#define fast		ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define w(x)		int t; cin >> t; while(t--)	 
#define fr(be,en)   for(int i = be; i < en; i++)
int pow(int x,int y){ if(y==0) return 1; if(y%2==1) return (((pow(x,y/2)*pow(x,y/2)%mod)*x)%mod); else return (pow(x,y/2)*pow(x,y/2))%mod;}
vb prime;	vi spf; 
void sieve(int n) 
{ 	prime.resize(n+1,true);	prime[0]=prime[1]=false;
	spf.resize(n+1,1);	spf[2]=2;
    for(int i=4;i<=n;i+=2){	prime[i]=false; spf[i]=2; } 
    for (int p=3; p*p<=n; p+=2) 
    {	if (prime[p] == true) 
        {   spf[p]=p;
        	for (int i=p*p; i<=n; i += p) 
            {   if(prime[i]==true)
            	{	spf[i]=p;
	            	prime[i] = false;
            	}
            } 
        } 
    } 
} 

int32_t main() {
	
	fast;

    return 0;
}
