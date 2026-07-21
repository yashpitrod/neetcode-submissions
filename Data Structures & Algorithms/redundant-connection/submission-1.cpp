class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node] == node){
            return node;
        }
        return find(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1);

        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int leader_u = find(u, parent);
            int leader_v = find(v, parent);
            
            if (leader_u == leader_v) {
                return {u, v};
            } 
            else {
                parent[leader_u] = leader_v;
            }
        }
        return {};
    }
};