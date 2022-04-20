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
    bool dfs( TreeNode* left , TreeNode* right ){
        if( ( left && !right ) || ( right && !left ) )
            return false;
        if( !left && !right )
            return true;
        if( left->val != right->val )
            return false;
        else 
            return dfs( left->left , right->right ) && dfs( left->right , right->left );
    }
    bool isSymmetric(TreeNode* root) {
        if( !root )
            return true;
        return dfs( root->left , root->right );
    }
};