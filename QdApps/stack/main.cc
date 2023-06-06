#include "stack.h"
#include "Expression.h"
#include <iostream>

int main()
{
  Expression *exp;
  std::string ex;
  std::cout << "entrez l'expression : ";
  std::cin >> ex;
  exp = new Expression(ex);
  try
  {
    std::cout << "result = " << exp->eval() << std::endl;
  }
  catch (std::string ex)
  {
    std::cout << ex << std::endl;
  }
  std::cout << "\nAppuyez sur une touche pour continuez\n";
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');
  std::cin.get();
  Expression exp2(std::string("((((2.2578+314.478)-10.2547)*4.4)/3.7)"));
  try
  {
    std::cout << exp2.eval() << std::endl;
  }
  catch (std::string ex)
  {
    std::cout << ex << std::endl;
  }
  return 0;
}
