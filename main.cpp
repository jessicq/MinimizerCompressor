#include <iostream>
#include "minimizer_compressor.h"

int main() {
  std::map<std::string,int> text;
  std::vector<std::string> non;
  std::string user;
    
  std::cout << "Please enter a string: " << std::endl;
  std::getline (std::cin, user);
  user += " ";
    
  init(text, non, user);
  text.clear();

  return 0;
}