class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for(string s : strs){
            result = result + to_string(s.length()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i < s.length()){
            int j = i;

            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i,j-i));

            j++;

            result.push_back(s.substr(j,length));

            i = j + length;
        }

        return result;
    }
};
