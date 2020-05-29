#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define For(i,a,n) for(ll i=a;i<n;i++)
#define rFor(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define print(a) cout<<a<<"\n"
#define input(a) cin>>a
void search(vector<ll>&v,vector<ll>subset,ll k,vector<vector<ll>>&subsets){
    if(k==v.size()){
        subsets.push_back(subset);
    }
    else{
        search(v,subset,k+1,subsets);
        subset.push_back(v[k]);
        search(v,subset,k+1,subsets);
        // to free up the space
        subset.pop_back();
    }
    return;
}
void solve1(){
    ll n;
    cin>>n;
    vector<ll>v,subset;
    vector<vector<ll>>subsets;
    For(i,0,n){
        ll temp;
        cin>>temp;
        v.pb(temp);
    }
    search(v,subset,0,subsets);
    For(i,0,subsets.size()){
        For(j,0,subsets[i].size()){
            cout<<subsets[i][j]<<" ";
        }
        print("");
    }
}
void solve2(){
    ll n;
    input(n);
    ll a[n];
    For(i,0,n) input(a[i]);
    // print    
    For(b,0,1<<n){
        // processing the subset for example shown below
        For(i,0,n){
            if(b&(1<<i)) cout<<a[i]<<" ";
        }
        print("");
    }
}
int main(){
    fastio;
    //method 1:using recursion"
    //method 2:using bit manipulation"
    ll x;
    cin>>x;
    if(x==1){
        solve1();
    }
    else{
        solve2();
    }
}