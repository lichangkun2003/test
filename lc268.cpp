#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n * ( n + 1 ) / 2 , sum = 0;  
        for( int i = 0 ; i < n ; i++ )
            sum += nums[i];
        return ans - sum;
    }
};

