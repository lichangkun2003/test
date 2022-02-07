#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp( n , vector<int>(n) );
        for( int i ; i < n ; ++i )
            dp[i][i] = true;
        
        int maxlen = 1 , begin = 0;
        for( int L = 2 ; L <= n ; ++L ){
            for( int i = 0 ; i < n ; ++i ){
                int j = i + L - 1;
                if( j >= n )
                    break;

                if( s[i] != s[j] )
                    dp[i][j] = false;
                else{
                    if( j - i < 3 )
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                
                if( dp[i][j] && L > maxlen ){
                    maxlen = L;
                    begin = i;
                }
            }
        }
        return s.substr( begin , maxlen );
    }
};