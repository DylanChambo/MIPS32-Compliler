#include <string>
#include <vector>

using namespace std;

enum TokenType
{
    IDENTIFIER,
    NUMBER,
    // Keywords
    INT,
    VOID,
    RETURN,
    IF,
    ELSE,
    WHILE,
    FOR,
    // Operators
    EQUALS,
    PLUS,
    MINUS,
    ASTERISK,
    FSLASH,
    // Punctioators
    SEMICOLON,
    COMMA,
    LPAREN,
    RPAREN,
    LCURLY,
    RCURLY,
    LSQUARE,
    RSQUARE
};

struct Token
{
    TokenType type;
    std::string value;
};

class Lexer
{
private:
    std::string m_code;
    int m_position = 0;

public:
    Lexer(const std::string &code);
    vector<Token> tokenize();

private:
    char peek(int offset = 0);
    char consume();
};
