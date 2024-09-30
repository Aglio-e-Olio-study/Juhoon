#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
    stack<char> s;
    int total = 0, temp = 1;
    bool isValid = true;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '(') {
            s.push(c);
            temp *= 2; 
        }         
        else if (c == '[') {
            s.push(c);
            temp *= 3; 
        }        
        else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                isValid = false;
                break;            
            }        
            if (str[i - 1] == '(') {
                total += temp;
            }            
            s.pop();  
            temp /= 2; 
        }
        else if (c == ']') {
            if (s.empty() || s.top() != '[') {
                isValid = false;
                break;
            }            
            if (str[i - 1] == '[') {
                total += temp;
            }
            s.pop();  
            temp /= 3; 
        }    
    }      
    if (!s.empty() || !isValid) {
        total = 0;    
    }    
    cout << total;   
    return 0;
}