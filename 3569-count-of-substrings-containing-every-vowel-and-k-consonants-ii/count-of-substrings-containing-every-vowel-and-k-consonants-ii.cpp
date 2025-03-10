class Solution {
public:
    long long atLeastK(string word, int k){
        long valid = 0;
        int st = 0;
        int end = 0;
        unordered_map<char,int> vowelcnt;
        int conscnt = 0;
        while(end < word.length()){
            char newletter = word[end];
            if(isVowel(newletter))
                vowelcnt[newletter]++;
            else
                conscnt++;
            while(vowelcnt.size() == 5 && conscnt >= k){
                valid += word.length() - end;
                char stletter = word[st];
                if(isVowel(stletter)){
                    if(--vowelcnt[stletter] == 0)
                        vowelcnt.erase(stletter);
                }
                else
                    conscnt--;
                st++;
            }
            end++;
        }
        return valid;
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k) - atLeastK(word,k+1);
    }
};