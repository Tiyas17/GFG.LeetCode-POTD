class Solution {
public:

    vector<int> prefixFunction(string &s) {
    vector<int> p(s.size());
    int j = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        while (j > 0 && s[j] != s[i])
            j = p[j-1];
    
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }   
    return p;
    }

    int minChar(string str){
        string s=str+'#';
        reverse(str.begin(),str.end());
        s+=str;
        vector<int> lps=prefixFunction(s);
        return (str.length()-lps.back());
    }
};