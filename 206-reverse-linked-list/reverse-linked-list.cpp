/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertAtHead(int val, ListNode* head){
        ListNode* nn = new ListNode(val);
        nn->next = head;
        head = nn;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* ans = new ListNode(head->val);
        ListNode* temp = head->next;
        while(temp != NULL){
            ans = insertAtHead(temp->val,ans);
            temp = temp->next;
        }
        return ans;
    }
};