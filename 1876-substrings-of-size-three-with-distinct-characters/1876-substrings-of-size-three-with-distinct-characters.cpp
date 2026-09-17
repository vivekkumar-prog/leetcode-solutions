class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3) return 0;
        char a=s[0], b=s[1],c[2];
        int res=0;
        for(int i=0;i<=s.size()-3;i++) {
            char a=s[i];
            char b=s[i+1];
            char c=s[i+2];
            if(a!=b && b!=c && c!=a) {
                res++;
            }
        }
    return res;
    }
};