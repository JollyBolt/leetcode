class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int x=0; x<row; x++){
            for(int y=0; y<col; y++){
                if(grid[x][y]==2){
                    q.push({x,y});
                }
                else if(grid[x][y]==1) fresh++;
            }
        }
        
        if(fresh==0) return 0;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>0 and grid[x-1][y]==1){
                    fresh--;
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(x<row-1 and grid[x+1][y]==1){
                    fresh--;
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(y>0 and grid[x][y-1]==1){
                    fresh--;
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                if(y<col-1 and grid[x][y+1]==1){
                    fresh--;
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
                
            }
            count++;
        }
        if(fresh==0) return count-1;
        return -1;
    }
};