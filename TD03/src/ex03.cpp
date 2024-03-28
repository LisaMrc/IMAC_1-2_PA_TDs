#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <cctype>
#include <stack>
#include <cmath>

enum class Operator {ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN, POW};
enum class TokenType {OPERATOR, OPERAND};

struct Token 
{
  TokenType type;
  float value;
  Operator op;
};

std::vector<std::string>split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s)
{
   for (int i = 0; i < s.size() ; i++)
   {
        if (!(std::isdigit(s[i]) || s[i] == '.'))
            return false;
   }
    return true;
}

size_t operator_precedence (Operator op)
{
    if (op == Operator::ADD)
    {
        return 1;
    }
    else if (op == Operator::SUB)
    {
        return 1;
    }
    else if (op == Operator::MUL)
    {
        return 2;
    }
    else if (op == Operator::DIV)
    {
        return 2;
    }
    else if (op == Operator::OPEN_PAREN)
    {
        return 4;
    }
    else if (op == Operator::CLOSE_PAREN)
    {
        return 4;
    }
    else 
    {
        return 3;
    }
}

Token make_token(float value)
{
    return {TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op)
{
    return {TokenType::OPERATOR, 0, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> tokenized_string{};

    for (int i = 0; i < words.size(); i++)
    {
        if (is_floating(words[i]))
        {
            tokenized_string.push_back(make_token(std::stof(words[i])));
        }
        else if (words[i] == "+")
        {
            tokenized_string.push_back(make_token(Operator::ADD));
        }
        else if (words[i] == "-")
        {
            tokenized_string.push_back(make_token(Operator::SUB));
        }
        else if (words[i] == "*")
        {
            tokenized_string.push_back(make_token(Operator::MUL));
        }
        else if (words[i] == "/")
        {
            tokenized_string.push_back(make_token(Operator::DIV));
        }
        else if (words[i] == "(")
        {
            tokenized_string.push_back(make_token(Operator::OPEN_PAREN));
        }
        else if (words[i] == ")")
        {
            tokenized_string.push_back(make_token(Operator::CLOSE_PAREN));
        }
        else if (words[i] == "^")
        {
            tokenized_string.push_back(make_token(Operator::POW));
        }
    }
    
    return tokenized_string;
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression)
{
    std::vector<std::string>splitted_infix_user_input = split_string(expression);
    std::vector<Token>tokenized_infix_user_input = tokenize(splitted_infix_user_input);

    std::vector<Token>output{};
    std::stack<Token>operator_stack{};

    for (Token token : tokenized_infix_user_input)
    {
        if (token.type == TokenType::OPERAND)
        {
            output.push_back(token);
        }
        else
        {
            if (operator_stack.empty() || token.op == Operator::OPEN_PAREN || operator_precedence(token.op) >= operator_precedence(operator_stack.top().op))
            {
                operator_stack.push(token);
            }
            else if (token.op == Operator::CLOSE_PAREN)
            {   
                while (operator_stack.top().op != Operator::OPEN_PAREN)
                {
                    output.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                operator_stack.pop();
            }
            else 
            {
                output.push_back(operator_stack.top());
                operator_stack.pop();
                operator_stack.push(token);
            }
        }
    }
    while (!(operator_stack.empty()))
    {
        output.push_back(operator_stack.top());
        operator_stack.pop();
    }
    return output;
}

float calculate_result (float leftOperand, Operator op, float rightOperand)
{
    if (op == Operator::ADD)
    {
        return leftOperand + rightOperand;
    }
    else if (op == Operator::SUB)
    {
        return leftOperand - rightOperand;
    }
    else if (op == Operator::MUL)
    {
        return leftOperand * rightOperand;
    }
    else if (op == Operator::DIV)
    {
        return leftOperand / rightOperand;
    }
    else 
    {
        return pow(leftOperand, rightOperand);
    }
}

float npi_evaluate(std::vector<Token> const& tokens)
{
    std::stack<float> stack;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].type == TokenType::OPERAND)
        {
            stack.push(tokens[i].value);
        }
        else
        {
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            float result = {calculate_result(leftOperand, tokens[i].op, rightOperand)};
            stack.push(result);
        }
    }
    return stack.top(); 
}

int main()
{
    std::string user_infix_input;
    std::cout << "Please enter infix expression :";
    std::getline(std::cin, user_infix_input);
    
    std::vector<Token>NPI_user_input = infix_to_npi_tokens(user_infix_input);
    std::cout << npi_evaluate(NPI_user_input);

    return 0;
}

// PROTOCOL :
// User is asked to enter an expression
// user enters a string
// string is "sliced" into string vectors
// those string vectors are analyzed, transformed into tokens and stocked into a vector of tokens
// Expression is rewritten as NPI into another vector of tokens
// initialisation of a stack, tokens are analyzed and stacked only if they are numbers
// result is calculated according to the operator
// result is printed