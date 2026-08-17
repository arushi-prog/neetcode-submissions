// APPROACH 1   
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(char c : s){
//             if(st.empty() || c == '(' || c == '{' || c == '['){
//                 st.push(c);
//                 continue;
//             }

//             if(c == ')'){
//                 if(st.top() == '('){
//                     st.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }

//             if(c == '}'){
//                 if(st.top() == '{'){
//                     st.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }

//             if(c == ']'){
//                 if(st.top() == '['){
//                     st.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }

//         }
//         return st.empty();
//     }
// };

// APPROACH 2
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '('){
                st.push(')');
            }
            else if(c == '{'){
                st.push('}');
            }
            else if(c == '['){
                st.push(']');
            }
            else if(st.empty() || st.top() != c){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    }
};
