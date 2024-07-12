// #include "commands.hpp"
// #include <fstream>
// #include <string>
// #include "../codeWork/DictionaryNode.hpp"

// namespace fileWork{
//   void runCommandLoop(std::ostream& out, std::istream& in){}
//   void readText(std::ostream& out, const std::string& text){
//     try{
//       std::ifstream fin(text, std::ios::in);
//       char a = 0;
//       fin >> std::noskipws;
//       while (!fin.eof()){
//         fin >> a;
//         out << a;
//       }
//       fin.close();
//     }
//     catch (...){
//       throw std::logic_error("<WRONG FILE NAME>");
//     }
//   }
//   void readBinary(std::ostream& out, const std::string& binary){
//     try{
//       std::ifstream fin(binary, std::ios::binary | std::ios::ate);
//       auto size = fin.tellg();
//       std::string str(size, '\0');
//       fin.seekg(0);
//       if (fin.read(&str[0], size)){
//         out << str << '\n';
//       }
//       fin.close();
//     }
//     catch (...){
//       throw std::logic_error("<WRONG FILE NAME>");
//     }
//   }
//   void decode(std::ostream& out, const std::string& binary,
//     const std::string& codes, const std::string& text){
//     codeWork::DictionaryNode* dict = nullptr;
//     size_t size = 0;

//     std::ifstream finCode(codes, std::ios::in);
//     dict = codeWork::readDictionary(finCode, size, dict);
//     finCode.close();

//     std::ifstream fin(binary, std::ios::in);
//     std::ofstream fout(text, std::ios::out);

//     char bit;
//     std::string trialCode = "";
//     char resKey;
//     while (fin >> bit){
//       trialCode += bit;
//       try{
//         resKey = codeWork::findKey(trialCode, dict, size);
//         out << resKey;
//         fout << resKey;
//         trialCode = "";
//       }
//       catch (const std::logic_error&){
//       }
//     }
//     if (trialCode.size() > 0){
//       fout.close();
//       fin.close();
//       delete[] dict;
//       throw std::logic_error("<NOT ENOUGH CODES>");
//     }
//     fout.close();
//     fin.close();
//   }
//   //В бинарные файлы нужно по особому записывать
//   //Группируя по октавам. Не забудь переделать
//   void encode(std::ostream& out, const std::string& text,
//     const std::string& binary, const std::string& codes){
//     codeWork::DictionaryNode* dict = nullptr;
//     try{
//       std::ifstream fin(text, std::ios::in);
//       size_t size = 0;
//       if (codes == ""){
//         dict = codeWork::makeDictionary(fin, size);
//       }
//       else{
//         std::ifstream finCode(codes, std::ios::in);
//         dict = codeWork::readDictionary(finCode, size, dict);
//         finCode.close();
//       }
//       std::ofstream fout(binary, std::ios::out);
//       char inputCh = 0;
//       std::string tmp = "";
//       fin.clear();
//       fin.seekg(0);
//       fin >> std::noskipws;
//       while (!fin.eof()){
//         fin >> inputCh;
//         tmp = codeWork::findCode(inputCh, dict, size);
//         out << tmp;
//         fout << tmp;
//       }
//       out << '\n';
//       fout.close();
//       fin.close();
//     }
//     catch (...){
//       delete[] dict;
//       throw;
//     }
//   }
//   void makeCodes(std::ostream& out, const std::string& text,
//     const std::string& codes){
//     std::ifstream fin(text, std::ios::in);
//     size_t size = 0;
//     codeWork::DictionaryNode* dict = codeWork::makeDictionary(fin, size);
//     fin.close();
//     codeWork::print(out, dict, size);
//     std::ofstream fout(codes, std::ios::out);
//     codeWork::print(fout, dict, size);
//     fout.close();
//   }
// }
