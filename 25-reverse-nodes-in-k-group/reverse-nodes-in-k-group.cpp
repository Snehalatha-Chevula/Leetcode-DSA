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
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* rl = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rl;
    }
    ListNode* findkNode(ListNode* head, int k){
        ListNode* temp = head;
        while(temp != NULL && --k)
            temp = temp->next;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while(temp){
            ListNode* knode = findkNode(temp,k);
            if(knode == NULL){
                prev->next = temp;
                break;
            }
            nxt = knode->next;
            knode->next = NULL;
            knode = reverseList(temp);
            if(temp == head)
                head = knode;
            else
                prev->next = knode;
            prev = temp;
            temp = nxt;
        }
        return head;
    }
};