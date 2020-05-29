#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[100];
bool v[100] = {0};

bool isBiparite(int n, int m)
{
    //Source Node
    int s = 0;
    queue<int> q;
    
    //Colour array
    int c[n];
    memset(c,-1,sizeof(int))
    
    c[0] = 0;
    
    q.push(s);
    
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        
        for(int i=0;i<adj[s].size();i++)
        {
            if(!v[adj[s][i])
            {
                v[adj[s][i]] = true;
                q.push(adj[s][i]);
                
                if(c[adj[s][i]] == -1)
                {
                    c[adj[s][i]] = (c[s] + 1) % 2;
                }
            }
            else
            {
                if(c[s] == c[adj[s][i]])
                return false;
            }
        }
    }
    
    return true;
}

int main() 
{
    // Nos. of Nodes
    ll n;
    cin >> n;
    
    // Nos. of Edges
    ll m;
    cin >> m;
    
    for(int i=0;i<m;i++)
	{
	    int a,b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
    
    cout << isBiparite(n,m);
    
	return 0;
}
