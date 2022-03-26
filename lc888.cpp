#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = accumulate( aliceSizes.begin() , aliceSizes.end() , 0 );
        int sum2 = accumulate( bobSizes.begin() , bobSizes.end() , 0 );
        int diff = ( sum1 - sum2 ) / 2;
        unordered_set<int> cnt ( aliceSizes.begin() , aliceSizes.end() ); 
        vector<int> ans;
        for( int y : bobSizes ){
            int x = y + diff;
            if( cnt.count( x ) > 0 ){
                ans = vector<int> { x , y };
                break;
            }
        }
        return ans;
    }
};