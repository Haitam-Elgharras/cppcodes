#include <iostream>
#include <vector>

int main() {
   
  std::vector<double> subway_adult;
  
  // Declare another vector here:
  std::vector<double> subway_child; //you can declare a vector without a size indication
  //but to add elements its obligatory to use .push_back it start from the indice 0 
    std::vector<double> location(2);//to initialize the size 
/*si on fait l'initialisation et apres on utilise la fonction push_back 
la fonction ajoutes des nouvelles cases pour remplir car les cases sont deja remplir par 0 , pour bien compris 
#include <iostream>
#include <vector>

// Define first_three_multiples() here:
std::vector<int> first_three_multiples(int num){
std::vector<int> three(3);
three.push_back(num);
three.push_back(num*2);
three.push_back(num*3);
 std::cout<<three.size()<<"\n";
return three ;
}

int main() {
  
  for (int element : first_three_multiples(3)) {
    std::cout << element << "\n";
  }

  
}*/

    std::vector<std::string> last_jedi;
  // Add characters here:
  last_jedi.push_back("kylo");//to add an elements in the end of the vector
  std::vector<double> delivery_order;
  
  delivery_order.push_back(8.99);
  delivery_order.push_back(3.75);
  delivery_order.push_back(0.99);
  delivery_order.push_back(5.99);
  delivery_order.pop_back() ;//supprimer le dérnier element
  
  // Calculate the total using a for loop:
  
  double total = 0.0;
  for(int i=0;i<delivery_order.size();i++)
  {
total=total+delivery_order[i];
std::cout<<total ;
}}
/*tres important 
#include <iostream>

// Define is_palindrome() here:
bool is_palindrome(std::string text) {
  
  std::string reversed_text = "";
  
  for (int i = text.size() - 1; i >= 0; i--) {
    reversed_text += text[i];
  }
  
  if (reversed_text == text) {
    return true;
  }
  
  return false;
  
}

int main() {
  
  std::cout << is_palindrome("madam") << "\n";
  std::cout << is_palindrome("ada") << "\n";
  std::cout << is_palindrome("lovelace") << "\n";
  
}*/

diffrence between lentgth and size 
/*#include<iostream>
#include<vector>
using namespace std ; 
int main(){
vector<string>  strs={"haitam","tam24","elgharras"} ;
int size , lng0 ;
    size = strs.size(); 
     cout << size <<endl ;
     lng0 = strs[1].length() ; 
cout << lng0 <<endl ;
}*/