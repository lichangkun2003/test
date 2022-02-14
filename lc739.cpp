#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans( n , 0 );
        stack<int> stk;
        for( int i = 0 ; i < n ; ++i ){
            while( !stk.empty() && temperatures[i] > temperatures[ stk.top() ] ){
                int previousIndex = stk.top();
                stk.pop();
                ans[previousIndex] = i - previousIndex;
            }
            stk.push(i);
        }
        return ans;
    }
};