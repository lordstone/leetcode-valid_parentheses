class Solution {
public:

    char matchChar(char mychr){
        if(mychr == '}') return '{';
        if(mychr == ')') return '(';
        if(mychr == ']') return '[';
    }

    bool isValid(string s) {
        if(s.length() == 0) return true;
        stack<char> mystk;
        int ptr = 0;
        while(ptr < s.length()){
            if(s[ptr] == '{' || s[ptr] == '[' || s[ptr] == '(' ){
                mystk.push(s[ptr]);
            }else if(s[ptr] == '}' || s[ptr] == ']' || s[ptr] == ')'){
                if(mystk.size() == 0) return false;
                if(mystk.top() == matchChar(s[ptr])){
                    mystk.pop();
                }else{
                    return false;
                }
            }else{
                return false; //not valid char
            }
            ptr++;
        }
        return mystk.size() == 0 ? true:false;
    }
};
