class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL; 
    }
};

class MyLinkedList {
public:
    Node *head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node* temp = head;
        int idx = 0;
        if(index < 0)
            return -1;
        while(temp != NULL){
            if(idx == index)
                return temp->data;
            idx++;
            temp = temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp && temp->next != NULL)
            temp = temp->next;
        if(temp)
            temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0)
            return;
        Node* newnode = new Node(val);
        Node* temp = head;
        int cnt=0;
        if(index == 0){
            addAtHead(val);
            return;
        }
        while(temp && temp->next != NULL && cnt < index-1){
            cnt++;
            temp = temp->next;
        }
        if(cnt == index-1){
            if(!temp)
                return;
            if(temp->next == NULL)
                temp->next = newnode;
            else{
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0)
            return;
        if(index == 0){
            if(head == NULL)
                return;
            head = head->next;
        }
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL && cnt < index-1){
            temp = temp->next;
            cnt++;
        }
        if(temp != NULL){
            if(temp->next)
                temp->next = temp->next->next;
            else
                temp->next = NULL;
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */