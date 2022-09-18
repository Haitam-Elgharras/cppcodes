#include <iostream>

// Define name_x_times() below:
void name_x_times(std::string name, int x) {
  
  while (x > 0) {
    
    std::cout << name;
    x--;
    
  }
  
}

int main() {
  
  std::string my_name = "Haitam!";
  int some_number = 5; // Change this if you like!
  // Call name_x_times() below with my_name and some_number
  name_x_times(my_name, some_number);
  
}
/* an exercice 
#include <iostream>

// Define needs_water() here:
 std::string needs_water(int days ,bool is_succulent){
   if(is_succulent==0 &&days>3)
   return "Time to water the plant." ;
   else if(is_succulent==1 &&days<=12)
   return "Don't water the plant!" ;
   else if(is_succulent==1 &&days>=13)
   return "Go ahead and give the plant a little water." ; 
   else 
   return "Don't water the plant!";
 }

int main() {
  
  std::cout << needs_water(10, false) << "\n";
  
}*/
std::cout<<"overloading is here ";
/*void print_cat_ears(char let) {
  std::cout << " " << let << "   " << let << " " << "\n";
  std::cout << let << let << let << " " << let << let << let << "\n";
}
 
void print_cat_ears(int num) {
  std::cout << " " << num << "   " << num << " " << "\n";
  std::cout << num << num << num << " " << num << num << num << "\n";
}*/
/*overloading fonctions : In a process known as function overloading, you can give multiple C++ functions the same name. Just make sure at least one of these conditions is true:

Each has different type parameters.
Each has a different number of parameters.
Overloading enables you to change the way a function behaves depending on what is passed in as an argument*/