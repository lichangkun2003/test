#include <stack>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0 , j = 0 , k =0;
        vector<int> ans(m+n);
        while( j < n && i < m ){
            if( nums1[i] <= nums2[j] )
                ans[k++] = nums1[i++];
            else
                ans[k++] = nums2[j++];
        }
        while( j < n )
            ans[k++] = nums2[j++];
        while( i < m )
            ans[k++] = nums1[i++];
        nums1 = ans;
    }
};