#include <numeric>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool isOrderLeft = true;

        queue< TreeNode* > q;
        if( !root )
            return {};
        q.push( root );
        vector< vector<int> > ans;
        while( !q.empty() ){
            int cnt = q.size();
            deque< int > tmp;
            for( int i = 0 ; i < cnt ; i++ ){
                TreeNode* cur = q.front();
                q.pop();
                if( isOrderLeft )
                    tmp.push_back( cur->val );
                else   
                    tmp.push_front( cur->val );
                if( cur->left )
                    q.push( cur->left );
                if( cur->right )
                    q.push( cur->right );

            }
            isOrderLeft = !isOrderLeft;
            ans.push_back( vector <int> { tmp.begin() , tmp.end() } );
        }
        return ans;
    }
};