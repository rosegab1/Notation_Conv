#include "NotationConverterDeque.hpp"


int NotationConverter :: precedence(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

void NotationConverter :: invalid_char(string inStr){
	for (char x : inStr){
		if (isalpha(x)) continue;
		if (x == '(' || x == ')' || x == '+' || x== '-' || x== '*' || x == '/' || x == ' ') continue;
		else throw runtime_error("invalid");
	}
}

string NotationConverter::postfixToInfix(string inStr){
    invalid_char(inStr);
    clearDeque();
    for (char x : inStr){
        if (isspace(x)) continue;
        if (isalpha(x)){
                string s(1, x);
                insertFront(s);

        }
        else{
            if (empty()) throw runtime_error("Insufficient operands for operator");
            string right = front();
            removeFront();
            if (empty()) throw runtime_error("Insufficient operands for operator");
            string left = front();
            removeFront();
            string final = "(" + left + " " + x + " " + right +")";
            insertFront(final);            
            
        }
    }

    return front();


}
string NotationConverter::postfixToPrefix(string inStr){
    return infixToPrefix(postfixToInfix(inStr));

}

string NotationConverter::infixToPostfix(string inStr){
    invalid_char(inStr);
    clearDeque();
    string final;
    for (char x : inStr){
        if (isspace(x)) continue;
        else if(isalpha(x)){
            string s(1,x);
            final = final + " " + s;
        }
        else if(x == '(') {
            string s(1,x);
            insertFront(s);
            continue;
        }

        else if(x == ')'){
            while(!empty() && front() != "("){
                final = final + " " + front();
                removeFront();
            
     	    }
	        if (!empty()) removeFront();
            
        }
 
        else{
            string s(1,x);
	        while (!empty() && precedence(front())>=precedence(s)){
	    		final = final + front();
			    removeFront();
            }
            insertFront(s);
        }  
    }

	while (!empty()){
		final += front();
		removeFront();
	}
    return final;
}



string NotationConverter::infixToPrefix(string inStr){
    invalid_char(inStr);
    string final;
    reverse(inStr.begin(), inStr.end());
    int l =inStr.size();
    for (int i=0; i < l; i++){
        if (inStr[i] == '(') inStr[i] = ')';
        else if (inStr[i] == ')') inStr[i] = '(';
    }
    string prefix = infixToPostfix(inStr);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string NotationConverter::prefixToInfix(string inStr){
    invalid_char(inStr);
    reverse(inStr.begin(), inStr.end());
    string infix = postfixToInfix(inStr);
    int l = infix.size();
    for (int i=0; i < l; i++){
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    reverse(infix.begin(), infix.end());
    return infix;


}
string NotationConverter::prefixToPostfix(string inStr){
    invalid_char(inStr);
    clearDeque();
    string final;
    reverse(inStr.begin(), inStr.end());
    for (char x : inStr){
        if (isspace(x)) continue;
        else if(isalpha(x)){
            string s(1,x);
            insertFront(s);
        }
        
        else{
            string s(1,x);
	        string left = front();
            removeFront();
            if (empty()) throw runtime_error("Insufficient operands for operator");
            string right = front();
            removeFront();
            string final = left + " " + right + " " + s;
            insertFront(final);
         }  
    }


    return front();
}
