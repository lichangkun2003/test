#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// //方法1 动态规划
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int dp0 = 0 , dp1 = -prices[0];
//         for( int i = 1; i < n ; ++i ){
//             int newdp0 = max( dp0 , dp1 + prices[i] );
//             int newdp1 = max( dp1 , dp0 - prices[i] );
//             dp0 = newdp0;
//             dp1 = newdp1;
//         }
//         return dp0;
//     }
// };

//方法2 暴力解（贪心）
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for( int i = 1 ; i < n ; ++i ){
            if( prices[ i ] > prices[ i - 1 ] )
                ans += prices[ i ] - prices[ i - 1 ];
        }
        return ans;
    }
};