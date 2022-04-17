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
    bool dfs( TreeNode* cur , int targetSum , int sum ){
        bool l = false , r = false;
        if( !( cur->left ) && !(cur->right) ){
            return sum + cur->val == targetSum;
        }
        if( cur->left )
            l = dfs( cur->left , targetSum , sum + cur->val );
        if( cur->right )
            r = dfs( cur->right , targetSum , sum + cur->val );
        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if( !root )
            return false;
        return dfs( root , targetSum , 0 );
    }
};