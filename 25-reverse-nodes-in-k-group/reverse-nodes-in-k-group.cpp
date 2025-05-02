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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* temp = head;
        vector<int> values;
        int n = 0;
        while(temp != NULL){
            values.push_back(temp->val);
            temp = temp->next;
            n++;
        }
        int i=1, total = n;
        temp = head;
        while(total/k){
            int cnt = k;
            int val = i*k-1;
            while(cnt){
                temp->val = values[val];
                val--;
                cnt--;
                total--;
                temp = temp->next;
            }
            i++;
        }
        for(int i=(n/k)*k;i<n;i++){
            temp->val = values[i];
            temp = temp->next;
        }
        return head;
    }
};