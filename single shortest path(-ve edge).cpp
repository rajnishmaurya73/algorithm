#include <iostream>
using namespace std;
  
struct Edge { 
    int u;
	int v;
	int w; 
}; 
  
 
struct Graph { 
    int V, E; 
    struct Edge* edge; 
}; 
  
struct Graph* create(int V, int E) 
{ 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
  
void print(int dist[], int n) 
{ 
	char a[6]={'S','T','X','Y','Z'};
    cout<<"Vertex \t\t Distance from Source\n"; 
    for (int i = 0; i < n; i++) 
        cout<<a[i]<<" \t\t "<<dist[i]<<endl;
} 

void BellmanFord(struct Graph* graph, int u) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
   
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[u] = 0; 

    for (int i = 1; i <= V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->edge[j].u; 
            int v = graph->edge[j].v; 
            int w = graph->edge[j].w; 
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
                dist[v] = dist[u] + w; 
        } 
    } 
  
    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].u; 
        int v = graph->edge[i].v; 
        int w = graph->edge[i].w; 
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) { 
            cout<<"Graph contains negative w cycle"; 
            return;
        } 
    } 
  
    print(dist, V); 
  
    return; 
} 
 
int main() 
{ 

    int V = 5;
    int E = 10;
    struct Graph* graph = create(V, E); 
   
    graph->edge[0].u = 0; 
    graph->edge[0].v = 1; 
    graph->edge[0].w = 6; 

    graph->edge[1].u = 1; 
    graph->edge[1].v = 2; 
    graph->edge[1].w = 5; 
  
    graph->edge[2].u = 2; 
    graph->edge[2].v = 1; 
    graph->edge[2].w = -2; 
  
    graph->edge[3].u = 0; 
    graph->edge[3].v = 4; 
    graph->edge[3].w = 7; 

    graph->edge[4].u = 1; 
    graph->edge[4].v = 4; 
    graph->edge[4].w = 8; 
   
    graph->edge[5].u = 1; 
    graph->edge[5].v = 3; 
    graph->edge[5].w = -4; 
  
    graph->edge[6].u = 4; 
    graph->edge[6].v = 2; 
    graph->edge[6].w = -3; 
  
    graph->edge[7].u = 3; 
    graph->edge[7].v = 0; 
    graph->edge[7].w = 2; 
    
    graph->edge[8].u = 3; 
    graph->edge[8].v = 2; 
    graph->edge[8].w = 7; 
    
    graph->edge[9].u = 4; 
    graph->edge[9].v = 3; 
    graph->edge[9].w = 9; 
  
    BellmanFord(graph, 0); 
  
    return 0; 
}
