// Last updated: 4/16/2025, 12:37:29 PM
class Solution {
public:
    bool isValid(string s) {
        		 
    if (s.length() % 2 != 0) {
		return false;			 
	}    
			 
	stack<char> st;
			 
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		if ( ch == '('){
            st.push(')');
        }
        else if (ch == '['){
            st.push(']');
        }
        else if (ch == '{'){
            st.push('}');
        }	
		else {
	    	if (st.empty() || ch != st.top()) {
	            return false;
	        }
        st.pop();
        }
    }
    return st.empty();
    }
};