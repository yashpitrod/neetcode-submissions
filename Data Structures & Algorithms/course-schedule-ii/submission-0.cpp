class Solution {
public:
    bool dfs(int crs, vector<vector<int>>& adj, vector<int>& visited, vector<int>& vec){
        if(visited[crs] == 1){
            return false;
        }

        if(visited[crs] == 2){
            return true;
        }

        visited[crs] = 1;
        for(int pre: adj[crs]){
            if(!dfs(pre, adj, visited, vec))
                return false;
        }

        vec.push_back(crs);
        visited[crs] = 2;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(auto& pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> visited(numCourses, 0);

        vector<int> vec(numCourses);
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, adj, visited, vec)){
                return {};
            }
        }

        return vec;
    }
};
