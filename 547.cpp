
class Solution {
public:
    bool visited[201][201];
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(); 
        
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
                visited[i][j] = false;
           }
        }
        int fc = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i][i]) {
                // start from unvisited node
                DFS(i, n, M);
                fc++;
            }
        }
        
       
        return fc;
    }
    void DFS(int p, int n, vector<vector<int>>& M) { 
        visited[p][p] = true; // visited node
        for (int j = 0; j < n; j++) { // for each possible child
            if (M[p][j] && visited[p][j] == false) {
                visited[p][j] = visited[j][p] = true;  // mark edge
                DFS(j, n, M); // node jump
            }
        }
    }
    
    
};