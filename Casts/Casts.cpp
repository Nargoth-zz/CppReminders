#include <iostream>

//Eplicit casts from const int& to int& are necessary
void take_nonconst_int(int& nonconstint){
   std::cout << "This is not const: " << nonconstint << std::endl; 
}

//No problems because implicit casts to const int& can be performed
void take_const_int(const int& constint){
  std::cout << "This is const: " << constint << std::endl;
}
void print_adress_decimal(int &a){
   std::cout << "Adress: " << reinterpret_cast<long>(&a) << std::endl;
}

int main(){
  const int a = 42;
  take_nonconst_int(const_cast<int&>(a)); //Explicit cast necessary

  int b = 5;
  take_const_int(b); //No cast necessary
  
  const int& c = b; //No cast necessary, c is a reference which allows no modification, b does
 
  print_adress_decimal(b);
  print_adress_decimal(const_cast<int&>(c)); //As print_address_decimal needs non const reference
                                             //Explicit cast is necessary
}

