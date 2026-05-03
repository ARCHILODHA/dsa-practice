struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a,parent);
    b = find(b,parent);

    if(a!=b){
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
    }
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;

    int cost = 0;

    for(auto &e : edges){
        if(find(e.u,parent)!=find(e.v,parent)){
            unite(e.u,e.v,parent,rank);
            cost += e.w;
        }
    }
    return cost;
}
