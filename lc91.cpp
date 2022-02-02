#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        //a = f[i-2] , b = f[i-1] , c = f[i]
        int a = 0 , b = 1 , c;
        for( int i = 1 ; i <= n ; ++i ){
            c = 0;
            if( s[ i - 1 ] != '0' )
                c += b;
            if( i > 1 && s[ i - 2 ] != '0' &&( s[ i - 2 ] - '0' ) * 10 + ( s[ i - 1 ] - '0' ) > 0 && ( s[ i - 2 ] - '0' ) * 10 + ( s[ i - 1 ] - '0' ) < 27 )
                c += a;
            a = b;
            b = c;
        }
        return c;
    }
};

// class Solution {
// private:
//     int ans;
// public:
//     void dfs( const string & s , int start ){
//         //如果start等于s的end，且最后一位在1~26内，说明符合条件
//         if( start == s.size() ){
//             ++ans;
//             return ;
//         }

//         //枚举start和start+1的位置，递归
//         //如果start的位置为0，不合意
//         int tmp;
//         if( s[start] == '0' )
//             return ;
        
//         dfs( s, start + 1 );
//         if( start + 1 < s.size() ){
//             tmp = ( s[start] - '0' ) * 10 + ( s[start + 1] - '0' );
//             if( tmp > 0 && tmp < 27 )
//                 dfs( s , start + 2 );
//         }
//     }
//     int numDecodings(string s) {
//         ans = 0;
//         dfs( s , 0 );
//         return ans;
//     }
// };

