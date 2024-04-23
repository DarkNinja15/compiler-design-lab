
#include <fstream>

#include<bits/stdc++.h>
using namespace std;
class Token {
public:
    string type;
    string value;
    int line;
    Token(string type, string value, int line) : type(type), value(value), line(line) {}
};

class LexicalAnalyzer {
    private:
    string input;
    char currentChar;
    int position;
    int lineNumber;
    unordered_set<string> keywords;
    unordered_set<char> operators;
    unordered_set<char> specialChars;
public:
    LexicalAnalyzer(string input) : input(input), currentChar(' '), position(0), lineNumber(1) {
        keywords = {"if", "else", "while", "for", "function", "var"};
       operators = {'+', '-', '*', '/', '=', '=', '!', '<', '>', '<', '>', '<', '=', '>'};
        specialChars = {'(', ')', '{', '}', '[', ']', ',', ';'};
    }

    void getNextChar() {
        if (position < input.length()) {
            currentChar = input[position++];
        } else {
            currentChar = '\0';
        }
    }

    bool isWhitespace(char c) {
        return isspace(static_cast<unsigned char>(c));
    }

    bool isLetter(char c) {
        return isalpha(static_cast<unsigned char>(c)) || c == '_';
    }

    bool isDigit(char c) {
        return isdigit(static_cast<unsigned char>(c));
    }

    bool isOperator(char c) {
        return operators.find(c) != operators.end();
    }

    bool isCommentStart(char c) {
        return c == '/' && input[position] == '/';
    }

    void consumeWhitespace() {
        while (currentChar && isWhitespace(currentChar)) {
            if (currentChar == '\n') {
                lineNumber++;
            }
            getNextChar();
        }
    }

    string scanIdentifier() {
        string identifier;
        while (currentChar && (isLetter(currentChar) || isDigit(currentChar))) {
            identifier += currentChar;
            getNextChar();
        }
        return identifier;
    }

    double scanNumber() {
        string num;
        while (currentChar && (isDigit(currentChar) || currentChar == '.')) {
            num += currentChar;
            getNextChar();
        }
        return stod(num);
    }

    string scanTextLiteral() {
        string text;
        getNextChar(); // Skip the opening quote
        while (currentChar && currentChar != '"') {
            text += currentChar;
            getNextChar();
        }
        getNextChar(); // Skip the closing quote
        return text;
    }

    void scanComment() {
        while (currentChar && currentChar != '\n') {
            getNextChar();
        }
    }

    vector<Token> analyze() {
        vector<Token> tokens;
        while (currentChar != '\0') {
            consumeWhitespace();

            if (isLetter(currentChar)) {
                string identifier = scanIdentifier();
                if (keywords.find(identifier) != keywords.end()) {
                    tokens.push_back(Token("Keyword", identifier, lineNumber));
                } else {
                    tokens.push_back(Token("Identifier", identifier, lineNumber));
                }
            } else if (isDigit(currentChar)) {
                double number = scanNumber();
                tokens.push_back(Token("Number", to_string(number), lineNumber));
            } else if (isOperator(currentChar)) {
                string op(1, currentChar);
                getNextChar();
                tokens.push_back(Token("Operator", op, lineNumber));
            } else if (isCommentStart(currentChar)) {
                scanComment();
            } else if (currentChar == '"') {
                string textLiteral = scanTextLiteral();
                tokens.push_back(Token("TextLiteral", textLiteral, lineNumber));
            } else if (currentChar == '\0') {
                getNextChar();
            } else if (specialChars.find(currentChar) != specialChars.end()) {
                string specialChar(1, currentChar);
                getNextChar();
                tokens.push_back(Token("SpecialChar", specialChar, lineNumber));
            } else {
                cerr << "Unrecognized character '" << currentChar << "' at line " << lineNumber << endl;
                getNextChar();
            }
        }
        return tokens;
    }


};

int main() {
    ifstream file("input.js");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    string inputCode;
   getline(file, inputCode, '\0');
cout<<inputCode<<endl;
    LexicalAnalyzer lexer(inputCode);
    vector<Token> tokens = lexer.analyze();

    cout << "Tokens: [" << endl;
    for (const auto& token : tokens) {
        cout << "Type: " << token.type << ", Value: '" << token.value << "', Line: " << token.line << endl;
    }
      cout << "]" << endl;

    return 0;
}
