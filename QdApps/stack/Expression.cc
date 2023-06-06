#include "stack.h"
#include "Expression.h"
#include <iostream>
std::string Expression::nexttoken() const
{
  char digit[100] = {'\0'};
  int i = 0;
  static int pos = 0;
  if (pos == exp.size())
    return "";
  while (pos < exp.size())
  {
    if (exp[pos] == '(')
    {
      pos++;
      return "(";
    }
    if (exp[pos] == ')' || exp[pos] == '+' || exp[pos] == '-' || exp[pos] == '*' || exp[pos] == '/')
    {
      if (i > 0)
      {
        digit[i] = '\0';
        return std::string(digit);
      }
      else
      {
        return std::string(1, exp[pos++]);
      }
    }
    if (isdigit(exp[pos]) || exp[pos] == '.')
    {
      digit[i] = exp[pos];
      digit[i + 1] = '\0';
      pos++;
      i++;
    }
  }
  return "";
}

std::string Expression::gettokenType(std::string token) const
{
  if (token == "(")
    return "LPAR";
  if (token == ")")
    return "RPAR";
  if (token == "+" || token == "-" || token == "*" || token == "/")
    return "OP";
  return "VAL";
}

float Expression::evalOp(float val1, float val2, std::string op) const
{
  if (op == "+")
    return val1 + val2;
  if (op == "-")
    return val1 - val2;
  if (op == "*")
    return val1 * val2;
  else
    return val1 / val2;
}

float Expression::eval() const
{
  float result;
  ArrayStack operands, operators;
  int pos = 0;
  std::string token;
  while (!(token = nexttoken()).empty())
  {
    std::string tokenType = gettokenType(token);
    std::cout << "Token: " << token << " --> "
              << "Type: " << tokenType << std::endl;
    if (tokenType == "VAL")
    {
      operands.push(token);
      operands.print();
      operators.print();
      continue;
    }
    if (gettokenType(token) == "OP")
    {
      operators.push(token);
      operands.print();
      operators.print();
      continue;
    }
    if (tokenType == "RPAR")
    {
      float operande1, operande2, result;
      operande2 = std::stof(operands.pop());
      operande1 = std::stof(operands.pop());
      std::string op = operators.pop();
      result = evalOp(operande1, operande2, op);
      operands.push(std::to_string(result));
      operands.print();
      operators.print();
      continue;
    }
  }
  if (!operators.isEmpty())
    throw "Expression Error";
  result = std::stof(operands.pop());
  if (!operands.isEmpty())
    throw "Expression Error";
  operands.print();
  operators.print();
  return result;
}

Expression::Expression(std::string ex)
{
  exp = ex;
}