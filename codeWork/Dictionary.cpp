// #include "Dictionary.hpp"
// #include "../sfc/SFC.hpp"
// #include "../utils/utils.hpp"
// #include "../utils/quickSort.hpp"
// #include "../utils/Delimiter.hpp"

// namespace codeWork{
//   Dictionary::Dictionary(): nodes(nullptr), size(0){}
//   Dictionary::Dictionary(std::istream& in, bool isCodeFile)
//     : nodes(nullptr), size(0){
//     (isCodeFile) ? readDictionary(in) : makeDictionary(in);
//   }
//   Dictionary::Dictionary(Dictionary&& src): nodes(src.nodes), size(src.size){
//     if (this != &src){
//       src.nodes = nullptr;
//       src.size = 0;
//     }
//   }
//   Dictionary::~Dictionary(){
//     delete[] nodes;
//   }
//   Dictionary& Dictionary::operator=(Dictionary&& src){
//     if (this != &src){
//       nodes = src.nodes;
//       size = src.size;
//       src.nodes = nullptr;
//       src.size = 0;
//     }
//     return *this;
//   }

//   void Dictionary::print(std::ostream& out){
//     out << size << '\n';
//     for (size_t i = 0; i < size; ++i){
//       out << nodes[i] << '\n';
//     }
//   }
//   std::string Dictionary::findCode(char key){
//     if (!key){
//       return "";
//     }
//     for (size_t i = 0; i < size; ++i){
//       if (nodes[i].key == key){
//         return nodes[i].code;
//       }
//     }
//     throw std::logic_error("<NOT ENOUGH KEYS IN DICTIONARY>");
//   }
//   char Dictionary::findKey(const std::string& code){
//     for (size_t i = 0; i < size; ++i){
//       if (nodes[i].code == code){
//         return nodes[i].key;
//       }
//     }
//     throw std::logic_error("<NO CODE FOUND>");
//   }
//   size_t Dictionary::getMaxCodeLength(){
//     size_t max = 0;
//     for (size_t i = 0; i < size; ++i){
//       if (max < nodes[i].code.size()){
//         max = nodes[i].code.size();
//       }
//     }
//     return max;
//   }
//   size_t Dictionary::getMinCodeLength(){
//     size_t min = 0;
//     for (size_t i = 0; i < size; ++i){
//       if (nodes[i].code.size() < min){
//         min = nodes[i].code.size();
//       }
//     }
//     return min;
//   }

//   void Dictionary::makeDictionary(std::istream& in){
//     if (!nodes){
//       size = 0;
//     }
//     char tmp = 0;
//     in >> std::noskipws;
//     DictionaryNode* newNodes = nullptr;
//     bool isFound = false;
//     while (!in.eof()){
//       isFound = false;
//       in >> tmp;
//       for (size_t i = 0; i < size; ++i){
//         if (nodes[i].key == tmp){
//           ++nodes[i].quantity;
//           isFound = true;
//         }
//       }
//       if (!isFound){
//         try{
//           newNodes = new DictionaryNode[++size];
//           utils::copyElements(newNodes, nodes, size - 1);
//           newNodes[size - 1].key = tmp;
//           newNodes[size - 1].quantity = 1;
//           delete[] nodes;
//           nodes = newNodes;
//         }
//         catch (const std::bad_alloc&){
//           throw std::logic_error("<COULD NOT CREATE DICTIONARY>");
//         }
//       }
//     }
//     utils::quickSort(nodes, size, [](DictionaryNode& a, DictionaryNode& b){
//       return a.quantity > b.quantity;
//       });
//     sfc::fillCodes(nodes, size);
//   }
//   void Dictionary::readDictionary(std::istream& in){
//     try{
//       in >> std::noskipws;
//       using del = utils::DelimiterI;
//       in >> size >> del{ '\n' };
//       nodes = new DictionaryNode[size];
//       for (size_t i = 0; i < size; ++i){
//         in >> nodes[i];
//       }
//     }
//     catch (...){
//       throw std::logic_error("<READING ATTEMPT: FAILED");
//     }
//   }
// }
