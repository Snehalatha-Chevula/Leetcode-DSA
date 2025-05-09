class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                int a = op.top();
                op.pop();
                int b = op.top();
                op.pop();
                op.push(a+b);
            }
            else if(tokens[i] == "/"){
                int a = op.top();
                op.pop();
                int b = op.top();
                op.pop();
                op.push(b/a);
            }
            else if(tokens[i] == "-"){
                int a = op.top();
                op.pop();
                int b = op.top();
                op.pop();
                op.push(b-a);
            }
            else if(tokens[i] == "*"){
                int a = op.top();
                op.pop();
                int b = op.top();
                op.pop();
                op.push(a*b);
            }
            else{
                op.push(stoi(tokens[i]));
            }
        }
        return op.top();
    }
};