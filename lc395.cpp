#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs( const string & s , int l , int r , int k ){
        //统计此段中各字符数量
        vector<int> cnt( 26 , 0 );
        for( int i = l ; i <= r ; ++i )
            cnt[ s[i] - 'a' ]++;

        //寻找分割点
        char split = 0;
        for( int i = 0 ; i < 26 ; ++i ){
            if( cnt[i] > 0 && cnt[i] < k ){
                split = i + 'a';
                break;
            }
        }
        if( split == 0 )
            return r - l + 1;
        
        //分治
        int i = l , ret = 0;
        while( i <= r ){
            while( i <= r && s[i] == split )
                ++i;
            if( i > r )
                break;
            int start = i ;
            while( i <= r && s[i] != split )
                ++i;
            int length = dfs( s , start , i - 1 , k );
            ret = max( ret , length );
        }
        return ret;
    }
    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs( s , 0 , n - 1 , k );
    }
};