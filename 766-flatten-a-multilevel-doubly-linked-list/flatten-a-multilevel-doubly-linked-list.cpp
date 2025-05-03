/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head || (!head->next && !head->child))
            return head;
        vector<Node*> broken;
        Node* temp = head;
        Node* prev = head;
        while(temp){
            //cout <<temp->val <<" ";
            if(temp->child){
                //cout <<temp->child->val <<" ";
                temp->child->prev = temp;
                //cout <<temp->child->prev->val <<" ";
                if(temp->next)
                    broken.push_back(temp->next);
                temp->next = temp->child;
                //cout <<temp->next->val <<" ";
            }
            prev = temp;
            temp = temp->next;
        }
        temp = prev;
        //cout <<temp->val <<endl;
        while(broken.size()){
            Node* temp1 = broken.back();
            temp1->prev = temp;
            temp->next = temp1;
            broken.pop_back();
            while(temp1){
                if(temp1->child){
                    temp1->child->prev = temp;
                    broken.push_back(temp1->next);
                    temp->next = temp1->child;
                }
                temp1 = temp1->next;
                temp = temp->next;
            }
        }
        Node* pt = head;
        while(pt){
            pt->child = NULL;
            pt = pt->next;
        }
        return head;
    }
};