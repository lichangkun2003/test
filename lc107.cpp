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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if( !root )
            return {};
        vector< vector<int> > ans;
        queue< TreeNode* > q;
        q.push( root );
        while( !q.empty() ){
            vector<int> tmp;
            int cnt = q.size();
            for( int i = 0 ; i < cnt ; i++ ){
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back( cur->val );
                if( cur->left )
                    q.push( cur->left );
                if( cur->right )
                    q.push( cur->right );
            }
            ans.push_back( move(tmp) );
        }
        reverse( ans.begin() , ans.end() );
        return ans;
    }
};

