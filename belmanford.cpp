#include<bits/stdc++.h>
using namespace std;

void bell(vector<vector<int>>& adj, vector<int>& dist, int src, int n)
{
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(auto it : adj)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[u] != 1e9 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;

    vector<int> dist(n,1e9);
    vector<vector<int>> adj;

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        adj.push_back({u,v,w});
    }

    bell(adj,dist,0,n);

    for(int i=0;i<n;i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}