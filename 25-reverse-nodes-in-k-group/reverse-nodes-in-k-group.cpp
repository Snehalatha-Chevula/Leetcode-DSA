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
        ListNode* head1 = NULL;
        ListNode* prev = NULL;
        while(total/k){
            int cnt = k;
            int val = i*k-1;
            while(cnt){
                ListNode* nn = new ListNode(values[val]);
                val--;
                cnt--;
                total--;
                if(!head1){
                    head1 = nn;
                    prev = head1;
                }
                else{
                    prev->next = nn;
                    prev = nn;
                }
            }
            i++;
        }
        for(int i=(n/k)*k;i<n;i++){
            ListNode* nn = new ListNode(values[i]);
            prev->next = nn;
            prev = nn;
        }
        return head1;
    }
};