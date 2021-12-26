#include <bits/stdc++.h>
using namespace std;

int curr_reg_count(vector<vector<int>> grid, int a, int b, vector<vector<int>> visited) {
    if (a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size()) {
        return 0;
    }
    if (grid[a][b] == 0) {
        return 0;
    }
    if ((grid[a][b] && !visited[a][b])) {
    
    int count = 1;
    grid[a][b] = 0;
    count = count + curr_reg_count(grid, a+1, b, visited);
    count = count + curr_reg_count(grid, a-1, b, visited);
    count = count + curr_reg_count(grid, a, b+1, visited);
    count = count + curr_reg_count(grid, a, b-1, visited);
    count = count + curr_reg_count(grid, a+1, b+1, visited);
    count = count + curr_reg_count(grid, a-1, b-1, visited);
    count = count + curr_reg_count(grid, a-1, b+1, visited);
    count = count + curr_reg_count(grid, a+1, b-1, visited);

    return count;
    }
    else {
        return 0;
    }
}
int maxRegion(vector<vector<int>> grid) {
    int max_ar = 0;
    int reg_count = 0;
    vector<vector<int>> visited(grid.size());
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
    
        fill(visited.begin(), visited.end(), 0);

            if (!visited[i][j]){
            reg_count = curr_reg_count(grid, i, j, visited);
            if (reg_count > max_ar) {
                max_ar = reg_count;
            }
            }
    }  
    }
    return max_ar;
}

int main()
{
    int r, c;
    cin>>r>>c;
    vector<vector<int>> grid;
    for(int i = 0; i < r; i++) {
        vector<int> test;
        for (int j = 0; j < c; j++) {
            int ab;
            cin>>ab;
            test.push_back(ab);
            
        }
        grid.push_back(test);
    }
    cout<<maxRegion(grid);
    return 0;
}
