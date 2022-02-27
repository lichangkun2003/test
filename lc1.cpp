#include <stack>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map< int , int > map;
        for( int i = 0 ; i < n ; ++i ){
            auto p = map.find( target - nums[i] );
            if( p != map.end() )
                return { i , p->second };
            map[ nums[i] ] = i;
        }
        return {};
    }
};