class Solution {
public:
    bool isAnagram(string s, string t) {
        int length_s = s.length();
        int length_t = t.length();

        if(length_s != length_t){
            return false;
        }

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

            if(s == t){
                return true;
            }
            
        return false;
    }
};
