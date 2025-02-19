class Solution {
public:
    void generate(int n, string cur, vector<string> &pos){
        if(cur.length()==n){
            pos.push_back(cur);
            return;
        }
        for(char i='a';i<='c';i++){
            if(cur.length()>0 && cur.back()==i)
                continue;
            generate(n,cur+i,pos);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> pos;
        generate(n,"",pos);
        if(pos.size() < k)
            return "";
        sort(pos.begin(),pos.end());
        return pos[k-1];
    }
};