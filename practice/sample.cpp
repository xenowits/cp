#include<bits/stdc++.h>
using namespace std;
int n,source,destination,t;
vector<float> energy;
vector<vector<vector<float> > > array_graphs;
class Mdijkstra{
    int v;
    public:
        bool *visited;
        int *weight;
        vector<int> parent;
        Mdijkstra(int vertices)
        {
            v = vertices;
            visited = new bool[v];
            weight = new int[v];
            parent.resize(v);
            for(int i=0;i<v;i++)
            {
                visited[i]=false;
                weight[i]=INT_MAX;
                parent[i]=-1;
            }
        }
};
int give_hop_count(int s,vector<int> parent,int count)
{
    if(s == source)
    return count;
    return give_hop_count(parent[s],parent,count+1);
}
vector<int> dijkstra(vector<vector<float> > g,int source)
{
    Mdijkstra dij(n);
    dij.weight[source]=0;
    for(int i=0;i<n;i++)
    {
        //get the vertex with the minimum weight which should be unvisited.
        //mark that as visited
        int min = INT_MAX;
        int min_index = -1;
        for(int j=0;j<n;j++)
        {
            if(!dij.visited[j] && min>=dij.weight[j])
            {
                min = dij.weight[j];
                min_index = j;
            }
        }
        dij.visited[min_index]=true;
        //now update the adjacent vertices of the above chosen vertex;
        for(int i=0;i<n;i++)
        {
            if(g[min_index][i] && !dij.visited[i] && (g[min_index][i]+dij.weight[min_index]<dij.weight[i]))
            {
                dij.weight[i] = g[min_index][i]+dij.weight[min_index];
                dij.parent[i] = min_index;
            }
        }
    }
    return dij.parent;
}
int main()
{
    //cout<<"enter the no of nodes\n";
    //cin>>n;
    n = 10;
    //cout<<"enter the no of testcases\n";
    cin>>t;
    //energy.resize(n,100.0);

    array_graphs.resize(t);
    //cout<<"start entering the graphs \n";
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>array_graphs[i][j][k];
            }
        }
    }
    //cout<<"enter the source and destination\n";
    //cin>>source;
    source = 0;
    //cin>>destination;
    destination = 3;
    bool found=false;

    vector<int> current_active;
    //cout<<"how many are adjacent to source\n";
    int count_adjacent;
    cin>>count_adjacent;
    current_active.resize(count_adjacent);
    //cout<<"enter the initial adjacents to source\n";
    for(int i=0;i<count_adjacent;i++)
    cin>>current_active[i];


    vector<vector<int> > hop_counts(count_adjacent);
    int curr_time=0;
    int break_index=-1;
    while(!found)
    {
        //find the optimum path , apply dijkstra on every active node
        for(int i=0;i<count_adjacent;i++)
        {
            if(current_active[i] == destination)
            {
                found=true;
                break_index=i;
                break;
            }
        }
        if(found)
        break;

        for(int i=0;i<count_adjacent;i++)
        {
            vector<int> par(n);
            par = dijkstra(array_graphs[curr_time],current_active[i]);
            for(int j=0;j<n;j++)
            {
                if(par[j] == current_active[i])
                current_active[i]=par[j];
            }
            hop_counts[i].push_back(give_hop_count(current_active[i],par,0));
        }
        curr_time++;
    }
    // sum up all the values of vector and find the average
    int average_k;
    int sum=0;
    for(int i=0;i<hop_counts[0].size();i++)
    {
        sum += hop_counts[break_index][i];
    }
    average_k = sum/hop_counts[0].size();
    return 0;
}
