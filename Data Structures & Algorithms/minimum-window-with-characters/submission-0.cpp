class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m > n) return "";

        map<char, int> mp;
        for(char c: t) {
            mp[c]++;
        }

        int count = mp.size();
        int i = 0;
        int start = 0;
        int mn = INT_MAX;

        for(int j = 0; j < n; j++) {
            mp[s[j]]--;
            if(mp[s[j]] == 0) count--;

            if(count == 0) {
                while(count == 0) {
                    if(j-i+1 < mn) {
                    start = i;
                    mn = min(mn, j-i+1);
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) count++;
                    i++;
                }
            }
        }
            return (mn < INT_MAX)? s.substr(start, mn): "";
    }
};