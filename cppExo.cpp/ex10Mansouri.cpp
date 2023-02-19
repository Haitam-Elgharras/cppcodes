#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class COMPLEXE
{

    double coeffReel, CoeffImaginaire;

public:
    void Zmodule()
    {
        cout << "le module de Z est " << sqrt(pow(coeffReel, 2) + pow(CoeffImaginaire, 2)) << endl;
    }
    void Zargument()
    {

        if (coeffReel != 0)
            cout
                << "largument de Z est " << atan(CoeffImaginaire / coeffReel) << endl;
        else
            cout << "err";
    }
    COMPLEXE(float Coeffimaginaire, float coeffreel)
    {
        coeffReel = coeffreel;
        CoeffImaginaire = CoeffImaginaire;
    }
};
int main()
{
    COMPLEXE Z(0, 1);
    Z.Zmodule();
    Z.Zargument();
}
