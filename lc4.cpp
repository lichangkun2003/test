#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int getKthElement( vector<int>& nums1 , vector<int>& nums2 , int k ){
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0 , index2 = 0;
        while( true ){
            if( index1 == m )
                return nums2[ index2 + k - 1 ];
            if( index2 == n )
                return nums1[ index1 + k - 1 ];
            if( k == 1 )
                return min( nums1[index1] , nums2[index2] );
            
            int newindex1 = min(index1 + k / 2 - 1 , m - 1);
            int newindex2 = min(index2 + k / 2 - 1 , n - 1);
            int pivot1 =nums1[newindex1];
            int pivot2 =nums2[newindex2];
            if( pivot1 <= pivot2 ){
                k -= newindex1 - index1 + 1;
                index1 = newindex1 + 1;
            }
            else if( pivot1 > pivot2 ){
                k -= newindex2 - index2 + 1;
                index2 = newindex2 + 1;
            }
            


        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totallength = nums1.size() + nums2.size();
        if( totallength % 2 == 1 )
            return getKthElement( nums1 , nums2 , ( totallength + 1 ) / 2 );
        else   
            return ( getKthElement( nums1 , nums2 , totallength / 2 ) + getKthElement( nums1 , nums2 , totallength / 2 + 1) ) / 2.0;
    }
};