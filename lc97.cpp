#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size() , n = s2.size() , t = s3.size();
        if( n + m != t )
            return false;
        
        vector<vector<int>> f ( m + 1 , vector<int>  ( n + 1 , false ) );
        f[0][0] = true;
        for( int i = 0 ; i <= m ; ++i ){
            for( int j = 0 ; j <= n ; ++j ){
                int p = i + j - 1;
                if( i > 0)
                    f[i][j] |= ( f[i-1][j] && s1[ i - 1 ] == s3[p] );
                if( j > 0 )
                    f[i][j] |= ( f[i][j-1] && s2[ j - 1 ] == s3[p] );
            }
        }
        return f[m][n];
    }
};