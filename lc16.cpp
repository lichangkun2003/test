#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort( nums.begin() , nums.end() );
        int cur = 1e7;
        for( int first = 0 ; first < n ; first++ ){
            if( first > 0 && nums[first] == nums[first - 1] )
                continue;
            int second = first + 1;
            int third = n - 1;
            while( second < third ){
                int sum = nums[first] + nums[second] + nums[third];
                if( sum == target )
                    return sum;

                if( abs( cur - target) > abs( sum - target ) )
                    cur = sum;
                
                if( sum < target ){
                    int secondtmp = second + 1;
                    while( secondtmp < third && nums[secondtmp] == nums[second] )
                        secondtmp++;
                    second = secondtmp;
                }
                else{
                    int thirdtmp = third - 1;
                    while( thirdtmp > second && nums[third] == nums[thirdtmp] )
                        thirdtmp--;
                    third = thirdtmp;
                }
            }
        }
        return cur;
    }
};