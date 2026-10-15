class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                string ope = tokens[i];

                if(ope == "*") {
                    int temp = a * b;
                    st.push(temp);
                }
                else if (ope == "/") {
                    int temp = a / b;
                    st.push(temp);
                }
                else if (ope == "+") {
                    int temp = a + b;
                    st.push(temp);
                }
                else if (ope == "-") {
                    int temp = a - b;
                    st.push(temp);
                }   
            }
            else {
                st.push(stoi(s));
            }
            
        }



    return st.top();
    }
};