#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    int count;
public:
    void dfs( vector<vector<int>> & grid , int x , int y , int sum ){
        if( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 ){
            count = max( count , sum );
            return ;
        }
        int tmp = grid[x][y];

        grid[x][y] = 0;
        dfs( grid , x + 1 , y , sum + tmp );
        dfs( grid , x - 1 , y , sum + tmp );
        dfs( grid , x , y + 1 , sum + tmp );
        dfs( grid , x , y - 1 , sum + tmp );
        grid[x][y] = tmp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        count = 0 ;
        for( int i = 0 ; i < grid.size() ; ++i ){
            for( int j = 0 ; j < grid[0].size() ; ++j ){
                if( grid[i][j] != 0 )
                    dfs( grid , i , j , 0 );
            }
        }
        return count;
    }
};