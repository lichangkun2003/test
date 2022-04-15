#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    constexpr static int dx[4] = { 1 , 0 , -1 , 0 };
    constexpr static int dy[4] = { 0 , 1 , 0 , -1 };
    int dfs( vector< vector<int> >& grid , int row , int col , int x , int y ){
        int res = 0;
        if( x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0 )
            return 1;
        if( grid[x][y] == 2 )
            return 0;
        grid[x][y] = 2;
        for( int i = 0 ; i < 4 ; ++i ){
            int newx = x + dx[i];
            int newy = y + dy[i];
            res += dfs( grid , row , col , newx , newy );
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size() , col = grid[0].size();
        int ans = 0;
        for( int i = 0 ; i < row ; i++ )
            for( int j = 0 ; j < col ; j++ ){
                if( grid[i][j] == 1 )
                    ans += dfs( grid , row , col , i , j );
            }
        return ans;
    }
};