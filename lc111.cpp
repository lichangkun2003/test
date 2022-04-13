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
    int minDepth(TreeNode* root) {
        queue< TreeNode* > q;
        if( !root )
            return 0;
        q.push( root );
        int ans = 1;
        while( !q.empty() ){
            int cnt = q.size();
            for( int i = 0 ; i < cnt ; i++ ){
                TreeNode* cur = q.front();
                q.pop();
                if( cur->left == nullptr && cur->right == nullptr )
                    return ans;
                if( cur->left )
                    q.push( cur->left );
                if( cur->right )
                    q.push( cur->right );
            }
            ans++;
        }
        return ans;
    }
};