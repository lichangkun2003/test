#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int m = pushed.size();
        int n = popped.size();
        if( m != n )
            return false;
        int j = 0;
        for( int i = 0 ; i < n ; ++i ){
            stk.push( pushed[i] );
            while(  (!stk.empty()) && popped[j] == stk.top() ){
                stk.pop();
                ++j;
            }
        }
        if( j != n  ||  !stk.empty()  )
            return false;
        return true;
    }
};