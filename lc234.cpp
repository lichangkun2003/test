#include <stack>
#include <vector>
#include <deque>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * frontNode;
    bool recursivelyCheck( ListNode *currentNode ){
        if( currentNode ){
            if( !recursivelyCheck( currentNode->next ) )
                return false;
            if( currentNode->val != frontNode->val )
                return false;
            frontNode = frontNode->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontNode = head;
        return recursivelyCheck( head );
    }
};