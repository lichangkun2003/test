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
    ListNode* oddEvenList( ListNode* head ) {
        ListNode *oddcur = head , *cur = head , *pre = head ;
        int n = 1;
        while( cur ){
            if( n == 1 || n % 2 == 0 ){
                n++;
                pre = cur;
                cur = cur->next;
                continue;
            }
            ListNode *tmp = oddcur->next;
            pre->next = cur->next;
            oddcur->next = cur;
            cur->next = tmp;

            cur = pre->next;
            oddcur = oddcur->next;
            n++;
        }
        return head;
    }
};