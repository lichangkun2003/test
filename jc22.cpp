#include <stack>
#include <vector>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next( nullptr ) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n =0;
        ListNode *slow = head , *fast = head;
        while( fast ){
            if( n >= k )
                slow = slow->next;
            fast = fast->next;
            n++;
        }
        return slow;

    }
};