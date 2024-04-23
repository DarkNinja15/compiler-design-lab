#include <iostream>
#include <regex>
using namespace std;

bool validateForLoopSyntax(const string& str) {
    regex pattern("for\\s*\\([^;]*;[^;]*;[^)]*\\)");
    return regex_match(str, pattern);
}

int main() {
    string s1 = "for(int i=0; i<10; i++)";
    string s2 = "for(int i=0; i<10i++)";

    cout << (validateForLoopSyntax(s1) ? "Valid" : "Invalid") << endl;
    cout << (validateForLoopSyntax(s2) ? "Valid" : "Invalid") << endl;

    return 0;
}
