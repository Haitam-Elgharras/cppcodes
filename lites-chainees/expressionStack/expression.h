#include <string>
using namespace std;
class expression
{
private:
    datatype nextToken() const;
    datatype getTokenType(datatype) const;
    float evalOp(float, float, datatype) const;

public:
    float eval() const;
    expression(datatype);
    datatype exp;
};
