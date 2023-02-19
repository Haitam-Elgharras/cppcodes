#include <iostream>
using namespace std;
class MaClasse
{

public:
    int var;

    int write() const
    {
        return var;
    }
    void read() const
    {
        cout << "read";
    }
};
int main(int argc, char const *argv[])
{
    MaClasse obj;
    obj.var = 10;
    obj.write();
    cout << obj.read();
}