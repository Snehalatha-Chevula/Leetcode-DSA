/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* sl = head;
        ListNode* fs = head;
        while(fs->next && fs->next->next){
            sl = sl->next;
            fs = fs->next->next;
            if(fs == sl)
                return true;
        }
        return false;
    }
};