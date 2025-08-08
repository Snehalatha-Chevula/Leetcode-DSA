class Solution {
public:
    char solve(string& word, int k, int len, int idx){
        if(word.length() >= k)
            return word[k-1];
        if(len == 0){
            len = word.length();
            idx = 0;
        }
        if(word[idx] == 'z')
            word += 'a';
        else
            word += word[idx]+1;
        return solve(word, k, len-1, idx+1);
    }
    char kthCharacter(int k) {
        string word = "a";
        return solve(word, k, 1, 0);
    }
};