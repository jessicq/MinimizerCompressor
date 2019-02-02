#include "minimizer_compressor.h"
#include <algorithm>

// Purpose: If nonIdentifier is empty, the input of text was an identifier
void check_emptyNon(std::vector<std::string> nonIdentifiers, std::vector<std::string> identifiers, std::string completeWord) {
  if( (!completeWord.empty()) && (nonIdentifiers.empty()) ) {
    identifiers.emplace_back(completeWord);
    std::cout << completeWord;
  } 
  else completeWord.clear();
}

// Purpose: Fill in map with input 
void init(std::map<std::string,int>& text, std::vector<std::string> nonIdentifiers, std::string str) {
  std::string completeWord, incompleteWord;
  std::vector<std::string> identifiers;
  int num(0);

  for(std::string::size_type i = 0; i < str.length(); i++) {
    // Check to see if character is a non-identifier, else insert the word into the map
    if( ((str[i] > 64) && (str[i] < 91))  ||  ((str[i] > 96) && (str[i] < 123)) ) completeWord += str[i];
    else {
      text.emplace(completeWord, num);

      //Find and Replace duplicate words
      if(!completeWord.empty()) {
        ++num;
        if(std::find(identifiers.begin(), identifiers.end(), completeWord) != identifiers.end()) {
          auto itr = text.find(completeWord);
          if(itr != text.end()) {
            std::cout << "$" << itr->second;
          }
        }
        else {
          identifiers.emplace_back(completeWord);
          std::cout << completeWord;
        }
      } 
      completeWord.clear();
      std::cout << str[i];
    }
  }
  check_emptyNon(nonIdentifiers, identifiers, completeWord);
  std::cout << std::endl;
}