#include<bits/stdc++.h>
using namespace std;

const int  inf = 1e5;

int main(){

    int r,c;
    cout<<"Enter the number of routers\n";
    cin>>r;
    int n = r;
    
    vector< vector<int> >adj(n,vector<int>(n,0));
    vector< vector<int> >par(n,vector<int>(n,-1));
    vector< vector<int> >dist(n,vector<int>(n,inf));

    
    int temp;

    int u,v;
    
    

    cout<<"Enter the number of router-router connections \n";
    cin>>temp;
    cout<<"Enter the router-router connection and the distance:\n";
    for(int i=0;i<temp;i++){
      cin>>u>>v;
      u--;
      v--;
      cin>>adj[u][v];
      adj[v][u] = dist[u][v] = dist[v][u] = adj[u][v];
      
      par[u][v] = u;
      par[v][u] = v;
    }
    cout<<"The initial routing table is\n";
    
    for(int i=0;i<n;i++){
        if(1){
          cout<<"The initial routing table for router "<<i+1<<"is\n";
          for(int j=0;j<n;j++){
        if(i!=j){
          cout<<"node: "<<j+1<<" - dist "<<dist[i][j]<<" - nexthop "<<par[i][j]+1<<"\n"; 
        }
          }
        }
    }

    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(dist[i][j] > dist[i][k] + dist[k][j]){
        dist[i][j] = dist[i][k] + dist[k][j];
        par[i][j] = k;
          }
        }
      }
    }

        
    for(int i=0;i<n;i++){
        if(1){
          cout<<"The final routing table for router "<<i+1<<"is\n";
          for(int j=0;j<n;j++){
        if(i!=j){
          cout<<"node: "<<j+1<<" -dist "<<dist[i][j]<<" -next hop "<<par[i][j]+1<<"\n"; 
        }
          }
        }
    }
}
