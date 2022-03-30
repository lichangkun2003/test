#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1 , r = num , mid;
        while( l <= r ){
            mid = l + ( r - l ) / 2;
            long long tmp = (long long)mid * mid;
            if( tmp == num )
                return true;
            else if( tmp > num )
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};