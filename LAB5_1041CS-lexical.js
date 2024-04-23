class Token {
    constructor(type, value, line) {
      this.type = type;
      this.value = value;
      this.line = line;
    }
  }
  
  class LexicalAnalyzer {
    constructor() {
      this.input = '';
      this.currentChar = '';
      this.position = 0;
      this.lineNumber = 1;
      this.keywords = ['if', 'else', 'while', 'for', 'function', 'var'];
      this.operators = ['+', '-', '*', '/', '=', '==', '!=', '<', '>', '<=', '>='];
    }

    setInput(input) {
      this.input = input;
      this.position = 0;
      this.lineNumber = 1;
      this.currentChar = this.input[0];
    }
  
    getNextChar() {
      if (this.position < this.input.length) {
        this.currentChar = this.input[this.position++];
      } else {
        this.currentChar = null;
      }
    }
  
    isWhitespace(char) {
      return /\s/.test(char);
    }
  
    isLetter(char) {
      return /[a-zA-Z_]/.test(char);
    }
  
    isDigit(char) {
      return /\d/.test(char);
    }
  
    isOperator(char) {
      return this.operators.includes(char);
    }
  
    isCommentStart(char) {
      return char === '/' && this.input[this.position] === '/';
    }
  
    consumeWhitespace() {
      while (this.currentChar && this.isWhitespace(this.currentChar)) {
        if (this.currentChar === '\n') {
          this.lineNumber++;
        }
        this.getNextChar();
      }
    }
  
    scanIdentifier() {
      let identifier = '';
      while (this.currentChar && (this.isLetter(this.currentChar) || this.isDigit(this.currentChar))) {
        identifier += this.currentChar;
        this.getNextChar();
      }
      return identifier;
    }
  
    scanNumber() {
      let num = '';
      while (this.currentChar && (this.isDigit(this.currentChar) || this.currentChar === '.')) {
        num += this.currentChar;
        this.getNextChar();
      }
      return parseFloat(num);
    }
  
    scanTextLiteral() {
      let text = '';
      this.getNextChar(); // Skip the opening quote
      while (this.currentChar && this.currentChar !== '"') {
        text += this.currentChar;
        this.getNextChar();
      }
      this.getNextChar(); // Skip the closing quote
      return text;
    }
  
    scanComment() {
      while (this.currentChar && this.currentChar !== '\n') {
        this.getNextChar();
      }
    }
  
    analyze(input) {
      this.setInput(input);
      const tokens = [];
      while (this.currentChar !== null) {
        this.consumeWhitespace();
  
        if (this.isLetter(this.currentChar)) {
          const identifier = this.scanIdentifier();
          if (this.keywords.includes(identifier)) {
            tokens.push(new Token('Keyword', identifier, this.lineNumber));
          } else {
            tokens.push(new Token('Identifier', identifier, this.lineNumber));
          }
        } else if (this.isDigit(this.currentChar)) {
          const number = this.scanNumber();
          tokens.push(new Token('Number', number, this.lineNumber));
        } else if (this.isOperator(this.currentChar)) {
          const operator = this.currentChar;
          this.getNextChar();
          tokens.push(new Token('Operator', operator, this.lineNumber));
        } else if (this.isCommentStart(this.currentChar)) {
          this.scanComment();
        } else if (this.currentChar === '"') {
          const textLiteral = this.scanTextLiteral();
          tokens.push(new Token('TextLiteral', textLiteral, this.lineNumber));
        } else {
          // Error handling for unrecognized characters
          console.error(`Unrecognized character '${this.currentChar}' at line ${this.lineNumber}`);
          this.getNextChar();
        }
      }
      return tokens;
    }
  }
  
  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question('Enter your JavaScript code:\n', (code) => {
    const lexer = new LexicalAnalyzer();
    const tokens = lexer.analyze(code);
  
    console.log("Tokens:");
    console.log(tokens);

    rl.close();
  });
