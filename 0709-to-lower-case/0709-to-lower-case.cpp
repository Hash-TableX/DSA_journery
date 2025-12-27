class Solution {
public:
    string toLowerCase(string s) {
        int i=0;
        while(s[i]!='\0'){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=tolower(s[i]);
            }
            i++;
        }
        return s;
    }
};