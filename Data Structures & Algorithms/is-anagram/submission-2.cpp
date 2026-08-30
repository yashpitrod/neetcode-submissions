class Solution {
public:
    bool isAnagram(string s, string t) {
        int m[26] = {0};

        for (int i=0 ; i<s.length() ; i++){
            m[s[i] - 'a']++;
        }

        for (int i=0 ; i<t.length() ; i++){
            m[t[i] - 'a']--;
        }

        for(int i=0 ; i<26; i++){
            if(m[i] > 0 || m[i] < 0){
                return false;
            }
        }

        return true;
    }
};
