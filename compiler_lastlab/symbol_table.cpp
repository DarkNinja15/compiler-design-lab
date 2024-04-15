
#include <bits/stdc++.h>
using namespace std;
bool isValidForLoopSyntax(const string &code)
{
    size_t forPosition = code.find("for");
    if (forPosition == string::npos)
    {
        return false;
    }
    size_t openParenthesisPosition = code.find("(", forPosition);
    if (openParenthesisPosition == string::npos)
    {
        return false;
    }
    size_t closeParenthesisPosition = code.find(")", openParenthesisPosition);

    if (closeParenthesisPosition == string::npos)
    {
        return false;
    }

    string forLoopHeader = code.substr(openParenthesisPosition + 1, closeParenthesisPosition - openParenthesisPosition - 1);

    size_t semicolonCount = count(forLoopHeader.begin(), forLoopHeader.end(), ';');

    if (semicolonCount != 2)
    {
        return false;
    }

    size_t firstSemicolon = forLoopHeader.find(";");
    size_t secondSemicolon = forLoopHeader.rfind(";");

    string initialization = forLoopHeader.substr(0, firstSemicolon);
    string condition = forLoopHeader.substr(firstSemicolon + 1, secondSemicolon - firstSemicolon - 1);
    string increment = forLoopHeader.substr(secondSemicolon + 1);

    return (!initialization.empty() && !condition.empty() && !increment.empty() && increment.find("++") != string::npos);
}

int main()
{
    string code1 = "for(int i=0; i<10; i++) { printf(\"hiiii\"); }";
    string code2 = "for(int i=0; i<10i++) { printf(\"hello\"); }";

    cout<<"Example 1: " << (isValidForLoopSyntax(code1) ? "Valid" : "Invalid") << endl;
    cout<< "Example 2: " << (isValidForLoopSyntax(code2) ? "Valid" : "Invalid") << endl;

    return 0;
}
