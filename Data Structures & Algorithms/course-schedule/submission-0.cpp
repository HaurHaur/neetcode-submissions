class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &mp, int cur_node, vector<bool> &visited, unordered_set<int> &path){
        visited[cur_node] = true;
        if(!mp.count(cur_node))
            return true;
        else{
            for(int i = 0; i < mp[cur_node].size(); i++){
                if(!visited[mp[cur_node][i]]){
                    path.insert(mp[cur_node][i]);
                    if(!dfs(mp,mp[cur_node][i], visited, path))
                        return false;
                    path.erase(mp[cur_node][i]);
                }
                else{
                    if(path.count(mp[cur_node][i]))
                        return false;
                }
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(numCourses, 0);
        unordered_set<int> path;
        for(int i = 0; i < prerequisites.size(); i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(visited[i])
                break;
            path.insert(i);
            if(!dfs(mp,i, visited, path))
                return false;
            path.erase(i);
        }
        return true;
    }
};
