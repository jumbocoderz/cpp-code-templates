/**********************
    Vikas Kumar Jha
    vkjha1010
**********************/
/**************************************************
		**************************************************/

#include<bits/stdc++.h>
using namespace std;

#define int         long long int 
#define double      long double
#define mod         1000000007
#define fi          first
#define se          second
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vb          vector<bool>
#define mii         map<int,int>
#define pqb         priority_queue<int>
#define pqs         priority_queue<int, vi, greater<int> >
#define ps(x,y)     fixed << setprecision(y) << x
#define fast        ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);
#define w(t)        int t; cin >> t; while(t--)  
#define fr(be,en)   for(int i = be; i < en; i++)
int pow(int x,int y){ if(y==0) return 1; if(y%2==1) return (((pow(x,y/2)*pow(x,y/2)%mod)*x)%mod); else return (pow(x,y/2)*pow(x,y/2))%mod;}
vb prime;   vi spf; 
void sieve(int n) 
{   prime.resize(n+1,true); prime[0]=prime[1]=false;
    spf.resize(n+1,1);  spf[2]=2;
    for(int i=4;i<=n;i+=2){ prime[i]=false; spf[i]=2; } 
    for (int p=3; p*p<=n; p+=2) 
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
struct node
{
	int pre;
	int suf;
	int sum;
	int ans;
	node()
	{
		this->pre=this->suf=this->sum=this->ans=INT_MIN;
	}
};

node merg(node l,node r)
{
	node res;
	res.pre=max(l.pre,l.sum+r.pre);
	res.suf=max(r.suf,r.sum+l.suf);
	res.sum=l.sum+r.sum;
	res.ans=max(l.ans,max(r.ans,max(res.pre,max(res.suf,l.suf+r.pre))));
	return res;
}
void build(vector<int>& arr,vector<node>& tree,int s,int e,int ind)
{
	if(s==e)
	{
		node no;
		no.pre=no.suf=no.sum=no.ans=arr[s];
		tree[ind]=no;
		return;
	}
	int mid=(s+e)/2;
	build(arr,tree,s,mid,2*ind+1);
	build(arr,tree,mid+1,e,2*ind+2);
	tree[ind]=merg(tree[2*ind+1],tree[2*ind+2]);
}

/**** Point update ,,,,, change arr[idx] = value *****/
void update(vector<node>& tree,vector<int>& arr,int s,int e,int ind,int idx,int value) 
{ 
    if (s == e) { 
        tree[ind].sum = tree[ind].pre = tree[ind].suf = tree[ind].ans = value; 
    } 
    else 
    { 
        int mid = (s+e)/2; 
        if (idx <= mid) 
            update(tree,arr,s,mid,2*ind+1,idx,value); 
        else
            update(tree,arr,mid+1,e,2*ind+2,idx,value);
        tree[ind]=merg(tree[2*ind+1],tree[2*ind+2]); 
    } 
} 
  

node query(vector<node>& tree,int s,int e,int l,int r,int ind)
{	
	if(e<l || s>r)
	{
		node no;
		return no;
	}
	if(l<=s && r>=e)
		return tree[ind];

	int mid=(s+e)/2;  
	node a=query(tree,s,mid,l,r,2*ind+1);
	node b=query(tree,mid+1,e,l,r,2*ind+2);
	return merg(a,b);
}
void print(node a)
{
	cout << a.sum << "  " << a.pre << "  " << a.suf <<   "   " << a.ans << "\n";
}
int32_t main() {
    
    //fast;
    w(t)
    {
 		int n;
 		cin >> n;
 		vi vec(n);
 		vector<node> tree(4*n+1);
 		fr(0,n)
 		{
 			cin >> vec[i];
 		}	             
 		build(vec,tree,0,n-1,0);
 		fr(0,n)
 		{
 			node a=query(tree,0,n-1,i,n-1,0);
 			node b=query(tree,0,n-1,0,i-1,0);
 			node c=merg(a,b);
 			cout << c.ans << " ";
 		}
 		cout << "\n";
    }
    return 0;
}
