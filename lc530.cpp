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
    void dfs(TreeNode* root, int& pre, int& ans) {
        if (root == nullptr) 
            return;
        dfs(root->left, pre, ans);
        if (pre == -1) 
            pre = root->val;
        else{
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};


// class Solution {
// public:
//     int getMinimumDifference(TreeNode* root) {
//         if( !root )
//             return 0;
//         queue<TreeNode*> q;
//         q.push( root );
//         int ans1 = INTMAX_MAX;
//         int ans2 = INTMAX_MAX;
//         while( !q.empty() ){
//             int cnt = q.size();
//             for( int i = 0 ; i < cnt ; i++ ){
//                 TreeNode* cur = q.front();
//                 int tmp = cur->val;
//                 if( tmp < ans1 ){
//                     ans2 = ans1;
//                     ans1 = tmp;
//                 }
//                 else if( tmp < ans2 )
//                     ans2 = tmp;
//                 q.pop();
//                 if( cur->left )
//                     q.push( cur->left );
//                 if( cur->right )
//                     q.push( cur->right );
//             }
//         }
//         return abs( ans1 - ans2 );
//     }
// };