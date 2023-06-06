#include "queue.h"
#include "student.h"
int main()
{
  CircularQueue<Student> q(10); // queue can't exceed 4 items
  try
  {
    q.display();
    // cout<<q.dequeue()<<endl;
    q.enqueue(Student(1, "Mohammed", "Qbadou", "m.qbadou@exemple.com"));
    q.enqueue(Student(2, "Sarah", "Alaoui", "s.alaoui@exemple.com"));
    q.enqueue(Student(3, "Abderrahmane", "hamoudi", "ab.hmoudi@exemple.com"));
    q.enqueue(Student(1, "Ayoub", "Ibrahimi", "ay.ibrahimi@exemple.com"));
    q.display();
  }
  catch (string ex)
  {
    cout << ex << endl;
  }
  return 0;
}

// template practice
/*
#include <iostream>
using namespace std;

template <class T>
class Calculator {
   private:
    T num1, num2;

   public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResult() {
        cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
        cout << num1 << " / " << num2 << " = " << divide() << endl;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
};
template <class T>
T Calculator<T>::multiply() { return num1 * num2; };

template <class T>
T Calculator<T>::divide() { return num1 / num2; };


int main() {
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl
         << "Float results:" << endl;
    floatCalc.displayResult();

    return 0;
}
*/
