

///  Multiply two matirx & return answer matrix   /// 
vector<vector<ll> > multiply_matrix(vector<vector<ll> > a,vector<vector<ll>> b)
{
    vector<vector<ll>> temp(a.size(),vector<ll>(b[0].size()));
    fr(0,a.size())
    {
        for(ll j=0;j<b[0].size();++j)
        {   ll sumy=0;
            for(ll k=0;k<a[0].size();++k)
            {
                sumy+=(a[i][k]*b[k][j])%mod;
                sumy%=mod;
            }
            temp[i][j]=sumy;
        }
    }
    return temp;
}

///   power of transformation matrix in log n  ///
vector<vector<ll>> matrix_expo(vector<vector<ll>> mat,ll y)
{
    if(y==1)
        return mat;
    if (y % 2)
    return multiply_matrix(mat, matrix_expo(mat, y - 1));
    return matrix_expo(multiply_matrix(mat, mat), y / 2);
}

int main()
{
    // input by question
    
    
    ll sz=max(x,10LL);
    
    // make intial matrix
    vector<vector<ll>> initial(sz,vector<ll>(1));
    fr(1,10)    initial[i][0]=mp[i];   
    
    // make transformation matrix
    vector<vector<ll>> mat(sz,vector<ll>(sz));
    fr(0,sz)    for(ll j=1;j<=9;++j){ ll num=((i*10)+j)%x;  mat[num][i]+=(mp[j]); }
    
    // make final answer
    vector<vector<ll>> temp=matrix_expo(mat,b-1);
    vector<vector<ll>> ans=multiply_matrix(temp,initial);
    cout << ans[k][0] << "\n";
}
