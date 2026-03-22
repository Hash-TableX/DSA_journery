class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        string result="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(!st.empty()){
                    result = result + s[i];
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty()){
                    result = result + s[i];
                }
            }
        }
        return result;
    }
};