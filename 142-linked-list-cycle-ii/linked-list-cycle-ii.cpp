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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode* sl = head;
        ListNode* fs = head;
        while(fs->next && fs->next->next){
            sl = sl->next;
            fs = fs->next->next;
            if(sl == fs){
                break;
            }
        }
        if(fs == NULL || fs->next == NULL || fs->next->next == NULL)
            return NULL;
        fs = head;
        while(fs != sl){
            fs = fs->next;
            sl = sl->next;
        }
        return sl;
    }
};