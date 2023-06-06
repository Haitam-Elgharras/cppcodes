#include <string>
class Expression
{
private:
  std::string nexttoken() const;
  std::string gettokenType(std::string) const;
  float evalOp(float, float, std::string) const;
  std::string exp;

public:
  float eval() const;
  Expression(std::string);
};