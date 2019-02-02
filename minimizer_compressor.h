#ifndef MINIMIZER_COMPRESSOR_H
#define MINIMIZER_COMPRESSOR_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

void check_emptyNon(std::vector<std::string> nonIdentifiers, std::vector<std::string> identifiers, std::string completeWord);
void init(std::map<std::string,int>& text, std::vector<std::string> nonIdentifiers, std::string str);

#endif