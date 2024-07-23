#include "DictionaryNode.hpp"
#include "../utils/utils.hpp"
#include "../utils/Delimiter.hpp"
#include "../sfc/SFC.hpp"

namespace codeWork{
  DictionaryNode::DictionaryNode(char k, size_t q, const std::string& c)
    : key(k), quantity(q), code(c){}

  std::ostream& operator<<(std::ostream& out, const DictionaryNode& node){
    return out << node.key << ':' << node.code;
  }
  std::istream& operator>>(std::istream& in, DictionaryNode& node){
    std::istream::sentry guard(in);
    if (!guard){
      return in;
    }
    in >> std::noskipws;
    using del = utils::DelimiterI;
    in >> node.key >> del{ ':' } >> node.code >> del{ '\n' };
    return in;
  }
}
