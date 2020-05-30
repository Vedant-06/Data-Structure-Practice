#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[100];
bool v[100] = {0};
int parent[100];
int disc[100];
int low[100];
int ap[100];


void AP(int u, int n, int m)
{
    static int time  = 0;
    int child = 0;
    v[u] = true;
    
    disc[u] = low[u] = ++time;
    for(int i=0;i<adj[u].size();i++)
    {
        int s = adj[u][i];
        
        if(!v[s])
        {
            child++;
            parent[s] = u;
            AP(s,n,m);
            
            low[u] = min(low[u],low[s]);
            
            if(parent[u] == -1 && child > 1)
                ap[u] = true;
            
            if(parent[u] != -1 && low[s] >= disc[u])
                ap[u] = true;
        }
        else if(s != parent[u])
            low[u] = min(low[u],disc[v]);
    }
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

	memset(parent,-1,sizeof(int));
	memset(disc,-1,sizeof(int));
	memset(low,-1,sizeof(int));
	memset(ap,-1,sizeof(int));
	
	for (int i = 0; i < n; i++) 
    {
        if (v[i] == false)
        {
            AP(i,n,m);
        }
    }
    
    for (int i = 0; i < V; i++) 
        if (ap[i] == true) 
            cout << i << " ";
    
	return 0;
}
