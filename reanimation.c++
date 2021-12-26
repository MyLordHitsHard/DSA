#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
bool visited[1001][1001];

bool isSafe(int row, int col)
{
    if ( row < 0 || col < 0 || row >= n || col >= m) {
        return false;
    }
    if (visited[row][col] == 1 || arr[row][col] == 0) {
        return false;
    }
    return true;
}
 

int DFS(int row, int col, int count)
{
    
    
 
    int ans = 0;
    if (visited[row][col] == 0 && arr[row][col] == 1) {
        ans = 1;
    }
    visited[row][col] = 1;
    
    
    
        if (isSafe(row-1, col))
        {
            ans += DFS(row-1 ,col, 0);
        }
        if (isSafe(row+1, col))
        {
            ans += DFS(row+1 ,col, 0);
        }
        if (isSafe(row, col-1))
        {
            ans += DFS(row ,col-1, 0);
        }
        if (isSafe(row, col+1))
        {
            ans += DFS(row ,col+1, 0);
        }
        if (isSafe(row-1, col-1))
        {
            ans += DFS(row-1 ,col-1, 0);
        }
        if (isSafe(row+1, col+1))
        {
            ans += DFS(row+1 ,col+1, 0);
        }
        if (isSafe(row-1, col+1))
        {
            ans += DFS(row-1 ,col+1, 0);
        }
        if (isSafe(row+1, col-1))
        {
            ans += DFS(row+1 ,col-1, 0);
        }
    
    return ans;
}
 


 

int main()
{
    
    cin>>n>>m;
    
    for(int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
            
        }
        
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && arr[i][j] == 1) {
                int temp = DFS(i, j, 0);
                if (temp > ans) {
                    ans = temp;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}