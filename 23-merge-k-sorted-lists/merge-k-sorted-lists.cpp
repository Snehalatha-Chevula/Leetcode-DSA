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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                pq.push({temp->val,temp});
                temp = temp->next;
            }
        }
        if(pq.empty())
            return NULL;
        ListNode* head = pq.top().second;
        ListNode* prev = head;
        pq.pop();
        while(!pq.empty()){
            prev->next = pq.top().second;
            prev = prev->next;
            pq.pop();
        }
        return head;
    }
};