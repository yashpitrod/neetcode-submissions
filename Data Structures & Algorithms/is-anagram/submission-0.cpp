class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        if(s.length() != t.length()){
            return false;
        }
        else{
            for(int i=0 ; i<s.length() ; i++){
                int y = s[i] - 'a';
                count[y]++;
            }
            for(int i=0 ; i<t.length() ; i++){
                int y = t[i] - 'a';
                count[y]--;
                if(count[y] < 0){
                    return false;
                }
            }
            return true;
        }
    }
};
