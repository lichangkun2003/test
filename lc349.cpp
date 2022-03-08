#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort( nums1.begin() , nums1.end() );
        sort( nums2.begin() , nums2.end() );
        int i = 0 , j = 0;
        int m = nums1.size() , n = nums2.size();
        vector<int> ans;
        while( i < m && j < n ){
            if( i > 0 && nums1[i] == nums1[ i - 1 ] ){
                i++;
                continue;
            } 
            if( j > 0 && nums2[j] == nums2 [j - 1 ] ){
                j++;
                continue;
            }

            if( nums1[i] == nums2[j] ){
                ans.push_back( nums1[i] );
                i++;
                j++;
            }
            else if( nums1[i] > nums2[j] )
                j++;
            else
                i++;
        }
        return ans;
    }
};