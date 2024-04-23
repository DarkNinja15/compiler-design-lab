//I.m writing this code in cpp
//NAME: SATVEER 
//ROLL NO. 2101094CS
#include <iostream>
#include <regex>
using namespace std;

bool validateForLoopSyntax(const string& str) {
    regex pattern("\\s*for\\s*\\(\\s*(int|double|float|char|auto)\\s+\\w+=\\d+;\\s*\\w+\\s*(<|>|<=|>=)\\d+;\\s*\\w+([\\+|\\-]{2})\\s*\\)\\s*[{}]*");
    return regex_match(str, pattern);
}

int main() {
    string s1 = " for(int i=0; i<10; i++)";
    string s2 = "for(int i=0; i<10i++)";

    cout << (validateForLoopSyntax(s1) ? "Valid" : "Invalid") << endl;
    // regex pattern("\\s*for\\s*\\(\\s*int\\s+\\w+\\s*=\\s*\\d+\\s*;\\s*\\w+\\s*(<|>|<=|>=)\\s*\\d+\\s*;\\s*\\w+\\s*([\\+\\-]{2})?\\s*\\)");
    cout << (validateForLoopSyntax(s2) ? "Valid" : "Invalid") << endl;

    return 0;
}
