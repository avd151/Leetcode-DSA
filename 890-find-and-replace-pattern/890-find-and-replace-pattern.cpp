class Solution {
    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
    bool match(string word, string pat){
        unordered_map<char, char>mp1, mp2;
        if(word.length() != pat.length())
            return false;
        int n = word.length();
        for(int i = 0; i < n; i++){
            char w = word[i];
            char p = pat[i];
            if(mp1.find(w) == mp1.end()) mp1[w] = p;
            if(mp2.find(p) == mp2.end()) mp2[p] = w;
            if(mp1[w] != p || mp2[p] != w)
                return false;
        }
        return true;
    }
public:
 vector<string> findAndReplacePattern(vector<string> words, string p) {
        vector<string> res;
        // for (string w : words) if (F(w) == F(p)) res.push_back(w);
        for(string word: words){
            if(match(word, p))
                res.push_back(word);
        }
        return res;
    }

    
};