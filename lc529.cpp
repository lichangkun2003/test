#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
    int dy[8] = { 1,0,-1,0,1,-1,1,-1 };

    void dfs( vector< vector<char> >& board , int x , int y ){
        int cnt = 0;
        for( int i = 0 ; i < 8 ; i++ ){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if( newx < 0 || newx >= board.size() || newy < 0 || newy >= board[0].size() )
                continue;
            cnt += board[newx][newy] == 'M';
        }

        if( cnt > 0 )
            board[x][y] = '0' + cnt;
        else{
            board[x][y] = 'B';
            for( int i = 0 ; i < 8 ; i++ ){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if( newx < 0 || newx >= board.size() || newy < 0 || newy >= board[0].size() || board[newx][newy] != 'E')
                    continue;
                dfs( board , newx , newy );
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0] , y = click[1];
        if( board[x][y] == 'M' ){
            board[x][y] = 'X';
        }
        else
            dfs( board , x , y );
        return board;
    }
};