#ifndef FILEWORK_HPP
#define FILEWORK_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "../codeWork/DictionaryNode.hpp"
#include "../sfc/SFC.hpp"

namespace fileWork
{
  class UI
  {
    public:
    void runCommandLoop(std::ostream& out, std::istream& in);
    private:
    std::string* codeNames;
    size_t size;
  };
}


#endif
