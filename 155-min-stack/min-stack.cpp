class MinStack {
public:
    stack<long long> st;
    long long mini=-1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val >= mini)
                st.push(val);
            else{
                long long flag = (2LL*val)-mini;
                mini = val;
                st.push(flag);
            }
        }
    }
    
    void pop() {
        if(st.top() < mini){
            long long flag = (2LL*mini)-st.top();
            mini = flag;
            st.pop();
        }
        else
            st.pop();
    }
    
    int top() {
        if(st.top() < mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */