#include <iostream>
int main()
{ // il faut bien conaitre que pour declaré string il faut ecrire std::string
  // add
  std::cout << "Hello World!\n";
  std::cout << "Hello haitam!\n";
  int score = 185;
  std::cout << score << "\ndo you understand ?";
  score = 0;
  // pour préciser le nombre apres la virgule
  // declare #include <iomanip>
  cout << fixed;
  cout << setprecision(2);
  cout << pow(pow(a, 2) + pow(b, 2), 0.5);
  // Output
  std::cout << "Player score:" << score << "\n";
  double tempf = 83.0;
  double tempc;
  tempc = (tempf - 32) / 1.8;
  std::cout << "The temp is" << tempc << "degrees Celsius.\n";
  /*C++ basic data types include:
int: integers
double: floating-point numbers
char: individual characters
string: sequence of characters
bool: true/false*/
  /*#include <iostream>
  using namespace std; //n'est pas repeter le std:: pour chaque cin et cout
  int main() {
    // Add your code below

  string lname ;
  string fname ;
  cout<<"please enter your name :\n";
  cin>>fname;
  cin>>lname;
  cout<<"your first name is :\n"<<fname<<"\n your last name is :\n"<<lname ;

  return 0 ;
  }*/
  // Create a number that's 0 or 1

  srand(time(NULL));
  int coin = rand() % 2;

  // If number is 0: Heads
  // If it is not 0: Tails

  if (coin == 0)
  {

    std::cout << "Heads\n";
  }
  else
  {

    std::cout << "Tails\n";
  }
  // CONDITIONALS &LOGIC

  return 0;
}