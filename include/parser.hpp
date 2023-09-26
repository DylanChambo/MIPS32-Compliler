#pragma once

#include "lexer.hpp"
#include <vector>

using namespace std;

class Parser
{
private:
    vector<Token> tokens;

public:
    Parser(vector<Token> tokens);
};