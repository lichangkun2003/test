#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 1, diff = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] && ++diff == 3) { 
                return nums[i];
            }
        }
        return nums[0];
    }
};

