#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int l = 0 , r = n , mid;
        while( l <= r ){
            mid = (l + r ) / 2;
            long long tmp = (long long)( 1 + mid ) * mid / 2;
            if( tmp == n ){
                ans = mid ;
                break;
            }
            else if( tmp < n ){
                l = mid + 1;
                ans = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
