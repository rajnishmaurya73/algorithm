//Print all neighbour nodes within distance K
#include <bits/stdc++.h>
using namespace std;

struct arr {
    int from, to;
};

void dfs(int k, int node,
         int parent,
         const vector<vector<int> >& tree)
{

    if (k < 0)
        return;

    cout << node << ' ';

    for (int i : tree[node]) {

        if (i != parent) {

            dfs(k - 1, i, node, tree);
        }
    }
}

void print_under_dis_K(struct arr graph[],
                       int node, int k,
                       int v, int e)
{

    vector<vector<int> > tree(v + 1,
                              vector<int>());

    for (int i = 0; i < e; i++) {
        int from = graph[i].from;
        int to = graph[i].to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(k, node, -1, tree);
}

int main()
{

    int v = 7, e = 6;

    struct arr graph[v + 1] = {
        { 2, 1 },
        { 2, 5 },
        { 5, 4 },
        { 5, 7 },
        { 4, 3 },
        { 7, 6 }
    };

    int node = 4, k = 2;

    print_under_dis_K(graph, node, k, v, e);

    return 0;
}
