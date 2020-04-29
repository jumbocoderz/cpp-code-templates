/**********************
    Vikas Kumar Jha
    vkjha1010
**********************/
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

                    /********************
                                convex hull trick
                                        **************************/

struct line
{
    int m,c;   //  y = mx + c
};

double intersectX(line A,line B)
{
    if(A.m == B.m)  //  if slope is same then it doesnot meet
        return LLONG_MAX;   
    else 
        return (double)(B.c-A.c)/(double)(A.m-B.m); 
}

int eval(int x,line A)
{
    return ((A.m)*x + A.c);  // return value of y after putting x in given line A
}

deque<line> st;
vector<double> points;
void addline(line A)
{
    if(st.empty()){ // currently no line present
        st.pb(A);
        return;
    }
    if(st.size()==1){ // only one line present 
        points.pb(intersectX(A,st.back()));
        st.pb(A);
        return;
    }
    while(points.size()){ // loop will work till current line give lesser intersection wtih previuos line
        line l2=st.back();
        st.pop_back();
        line l1=st.back();
        if( intersectX(A,l1) > points.back() ){
            st.pb(l2);
            break;
        }
        else{
            points.pop_back();
        }
    }
    points.pb(intersectX(A,st.back()));
    st.pb(A);
}

int findbest(int x) // returns the optimal result for any given point x
{
    int idx = lower_bound(points.begin(),points.end(),x) - points.begin();
    return eval(x, st[idx]);
}

                /*********************
                            convex hull trick end
                                    ************************/


int32_t main() {
    
    // fast;
    int n,ans=0;
    cin >> n;
    vi vec(n),pre(n+1),sum(n+1);
    fr(0,n)
    {   cin >> vec[i];
        pre[i+1]=pre[i]+(i+1)*vec[i];
        sum[i+1]=sum[i]+vec[i];
    }

    line l;
    l.m = 0;
    l.c = 0;
    addline(l);
    fr(1,n+1)
    {
        ans = max(ans, findbest(-sum[i]) + pre[i]) ;
        l.m=i;
        l.c=i*sum[i] - pre[i];
        addline(l);
    }
    cout << ans;

    return 0;
}
