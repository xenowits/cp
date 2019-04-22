#include<bits/stdc++.h>
using namespace std;
int n,source,destination,t;
//vector<float> energy;
vector<vector<vector<float> > > array_graphs;
// class Mdijkstra{
//     int v;
//     public:
//         bool *visited;
//         float *weight;
//         vector<int> parent;
//         Mdijkstra(int vertices)
//         {
//             v = vertices;
//             visited = new bool[v];
//             weight = new float[v];
//             parent.resize(v);
//             for(int i=0;i<v;i++)
//             {
//                 visited[i]=false;
//                 weight[i]=INT_MAX;
//                 parent[i]=-1;
//             }
//         }
// };
int give_hop_count(int s,vector<int> parent,int count,int source)
{
    if(s == source)
    return count;
    return give_hop_count(parent[s],parent,count+1,source);
}
vector<int> dijkstra(vector<vector<float> > g,int source)
{
    //Mdijkstra dij(n);
    //cout << "madarchod" << endl;
    vector<bool> visited(n,false);
    vector<float> weight(n,7834.2948);
    vector<int> parent(n,-1);
    weight[source] = 0.00;
    //dij.weight[source]=0.0;
    for(int i=0;i<n;i++)
    {
        //get the vertex with the minimum weight which should be unvisited.
        //mark that as visited
        float min = 2345.5434;
        int min_index = -1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && min >= weight[j])
            {
                min = weight[j];
                min_index = j;
            }
        }
        visited[min_index]=true;
        //now update the adjacent vertices of the above chosen vertex;
        for(int i=0;i<n;i++)
        {
            if(g[min_index][i] && !visited[i] && (g[min_index][i] + weight[min_index] < weight[i]))
            {
                weight[i] = g[min_index][i]+ weight[min_index];
                parent[i] = min_index;
            }
        }
    }
    return parent;
}
int main()
{
    //cout<<"enter the no of nodes\n";
    //cin>>n;
    n = 10;
    //cout<<"enter the no of testcases\n";
    cin>>t;
    //energy.resize(n,100.0);
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    int the_t = std::uniform_int_distribution<int>(1,t)(rng);
    array_graphs.resize(t);
    float a;
    cout << the_t << " h kya" << endl;
    //cout<<"start entering the graphs \n";
    for(int i=0;i<t;i++)
    {
        array_graphs[i].resize(n,vector<float> (n));
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>a;
                array_graphs[i][j][k]=a;
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
        if (curr_time == the_t)
        {
          int kukko = std::uniform_int_distribution<int>(8,15)(rng);
          cout << kukko << endl;
          return 0;
        }
        for(int i=0;i<count_adjacent;i++)
        {
            vector<int> par(n);
            //cout << "current time " << curr_time << endl;
            par = dijkstra(array_graphs[curr_time],current_active[i]);

            hop_counts[i].push_back(give_hop_count(destination,par,0,current_active[i]));
            for(int j=0;j<n;j++)
            {
                if(par[j] == current_active[i])
                current_active[i]=par[j];
            }

        }
        cout << "current time " << curr_time << endl;
        curr_time++;
    }
    // sum up all the values of vector and find the average
    long long average_k;
    long long sum=0;
    for(int i=0;i<hop_counts[0].size();i++)
    {
        sum += hop_counts[break_index][i];
    }
    if (!hop_counts[0].size())
    {
        cout << "the program didn't take any input and moved to the end of file" << endl;
        return 0;
    }
    else
    {
        average_k = sum/hop_counts[0].size();
    }
    return 0;
}
