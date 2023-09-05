#include <string>
#include <vector>

using namespace std;
// Define token types
enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    NUMBER,
    PUNCTUATOR
};

// Define a token structure
struct Token
{
    TokenType type;
    std::string value;
};

const vector<string> KEYWORDS = {
    "auto",
    "int",
    "struct",
    "break",
    "else",
    "switch",
    "case",
    "enum",
    "register",
    "typedef",
    "char",
    "extern",
    "return",
    "const",
    "unsigned",
    "continue",
    "for",
    "signed",
    "void",
    "default",
    "if",
    "while",
    "do",
    "goto",
    "sizeof",
};

vector<Token> tokenize(const string &input);