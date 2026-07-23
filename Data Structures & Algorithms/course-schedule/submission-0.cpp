class Solution {
public:
    bool dfs(int crs, vector<vector<int>>& adj, vector<int> &visited){
        // if course is in visiting state then their will be cycle detected
        if(visited[crs] == 1){
            return false;
        }

        // already safe
        if(visited[crs] == 2){
            return true;
        }

        visited[crs] = 1;

        for(int pre: adj[crs]){
            if(!dfs(pre,adj,visited)){
                return false;
            }
        }

        visited[crs] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<int> visited(numCourses, 0);

        for(int i=0 ; i<numCourses; i++){
            if(!dfs(i, adj, visited)){
                return false;
            }
        }

        return true;
    }
};
