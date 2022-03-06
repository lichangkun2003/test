#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort( intervals.begin() , intervals.end() );
        vector< vector<int> > ans;
        int n = intervals.size() , i = 1;
        int left = intervals[0][0];
        int right = intervals[0][1];
        while( i < n ){
            if( intervals[i][0] <= right ){
                right = max( right , intervals[i][1] );
                i++;
            }
            else{
                ans.push_back( {left , right} );
                left = intervals[i][0];
                right = intervals[i][1];
                i++;
            }
        }
        ans.push_back( { left , right } );
        return ans;
    }
};