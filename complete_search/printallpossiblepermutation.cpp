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
void search(ll &n,bool chosen[],vector<ll>permutation){
    if(permutation.size()==n){
        For(i,0,n){
            cout<<permutation[i]<<" ";
        }
        print("");
    }
    else{
        For(i,0,n){
            if(chosen[i]) continue;
            chosen[i]=true;
            permutation.push_back(i);
            search(n,chosen,permutation);
            chosen[i]=false;
            permutation.pop_back();
        }
    }
}
void solve1(){
    ll n;
    cin>>n;
    // generating permutation from 0 to n-1
    vector<ll>permutation;
    bool chosen[n];
    For(i,0,n) chosen[i]=false;
    search(n,chosen,permutation);
}
ll permutate(ll a[],ll l,ll r){
    if(l==r){
        For(i,0,r+1){
            cout<<a[i]<<" ";
        }
        print("");
    }
    else{
        For(i,l,r+1){
            // l will increase in every recursive call
            //swap
            swap(a[l],a[i]);
            // call the function again
            permutate(a,l+1,r);
            // swap it back
            swap(a[l],a[i]);
        }
    }
}
void solve2(){
    ll n;
    cin>>n;
    ll a[n];
    For(i,0,n){
        a[i]=i;
    }
    permutate(a,0,n-1);
}
int main(){
    fastio;

    // one from the pdf
    // complexity O(n!)
    // with every recusive function call no of chosen would increase n*n-1*..1 
    solve1();

    // one from the geeksforgeeks
    // complexity O(n!)
    // with every recursive function call value of l increase so first it will run for n then n-1 times and so on
    solve2();

    // obviously we are print every permutation possible so complexity would be n fractorial
    // alternate method would be using next_permutation in a do while loop,always a semi colin after a do while loop
    // do{
    //     //process permutation
    // }
    // while(next_permutation(permutation.begin(),permutation.end()));
}