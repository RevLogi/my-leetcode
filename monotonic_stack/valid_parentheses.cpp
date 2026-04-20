#include <stack>
#include <string>

class Solution {
   public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char paren : s) {
            if (paren == '(' || paren == '[' || paren == '{') {
                st.push(paren);
            } else if (!st.empty()) {
                switch(st.top()){
                    case '(':
                        if (paren != ')') return false;
                        break;
                    case '[':
                        if (paren != ']') return false;
                        break;
                    case '{':
                        if (paren != '}') return false;
                        break;
                    default:
                        return false;
                        break;
                }
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
