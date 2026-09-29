class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++) {
            res = res + to_string(strs[i].length()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()) {
            string leng = "";
            while(s[i] != '#') {
                leng += s[i];
                i++;
            }
            i++;
            string temp = "";
            int l = stoi(leng);
            while(l != 0) {
                temp += s[i];
                i++;
                l--;
            }
            res.push_back(temp);
        }
        return res;
    }
};
