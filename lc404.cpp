#include <iostream>
#include <math.h>
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
    int sumOfLeftLeaves(TreeNode* root) {
        queue< TreeNode* > q;
        if( !root )
            return 0;
        q.push( root );
        int ans = 0;
        while( !q.empty() ){
            TreeNode* cur = q.front();
            q.pop();
            if( cur->left ){
                q.push( cur->left );
                if( !(cur->left->left) && !(cur->left->right) )
                    ans += cur->left->val;
            }
            if( cur->right )
                q.push( cur->right );
        }
        return ans;
    }
};