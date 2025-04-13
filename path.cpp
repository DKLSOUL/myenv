#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
int indegree[N];
typedef pair<int,int> ipair;
struct edge{
    int src,dest,weight;
};
class graph{
    int V,E;
    vector<vector<ipair>> g;
    vector<vector<int>> dist;
    vector<edge> edges;

public:
    graph(int ver,int e):V(ver),g(ver),dist(ver, vector<int>(ver, 0)),E(e){}


void addedge(int u,int v,int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
    dist[u][v]=w;
    dist[v][u]=w;
    edges.push_back({u,v,w});
}

bool bellmanford(int s){
    vector<int> dist1(V,INT_MAX);
    dist1[s]=0;
    for(int i=0;i<V-1;i++){
        for(auto e:edges){
            if(dist1[e.src]!=INT_MAX&&dist1[e.dest]>dist1[e.src]+e.weight){
                dist1[e.dest]=dist1[e.src]+e.weight;
            }
        }
    }
    for(auto e:edges){
        if(dist1[e.src]!=INT_MAX&&dist1[e.dest]>dist1[e.src]+e.weight){
            return false;
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist1[i]<<" ";
    }
    cout<<endl;
    return true;
}

void floydwarshall(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j) dist[i][j]=0;
            else if(dist[i][j]==0) dist[i][j]=INT_MAX;
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX) continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dijkstra(int s){
    vector<int> dist1(V,INT_MAX);
    dist1[s]=0;
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto v:g[u]){
            if(dist1[v.first]>dist1[u]+v.second){
                dist1[v.first]=dist1[u]+v.second;
                pq.push({dist1[v.first],v.first});
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist1[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    graph g(6,6);
    g.addedge(0,1,4);
    g.addedge(0,2,1);
    g.addedge(2,1,2);
    g.addedge(1,3,1);
    g.addedge(3,4,3);
    g.addedge(4,5,2);
    g.floydwarshall();
    cout<<endl;
    g.dijkstra(0);
    g.bellmanford(0);
    return 0;
}