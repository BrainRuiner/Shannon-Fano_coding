#include "commands.hpp"
#include "../codeWork/CodeTree.hpp"
#include "../utils/BinaryWriter.hpp"

namespace fileWork{
  void runCommandLoop(std::ostream& out, std::istream& in){
    std::string cmd = "";
    std::string first = "";
    std::string second = "";
    std::string third = "";
    out << "> ";
    runArgReader(in, cmd, first, second, third);
    while (in){
      try{
        if (cmd == "r"){
          read(out, first);
        }
        else if (cmd == "d"){
          decode(out, first, second, third);
        }
        else if (cmd == "e"){
          encode(out, first, second, third);
        }
        else if (cmd == "m"){
          makeCodes(out, first, second);
        }
        else{
          throw std::logic_error("<FAIL: No such command>");
        }
      }
      catch (const std::exception& e){
        out << e.what() << '\n';
      }
      out << "> ";
      runArgReader(in, cmd, first, second, third);
    }
    out << '\n';
  }
  template <class First, class ...Other>
  void runArgReader(std::istream& in, First& first, Other& ...other){
    in >> first;
    if (in.peek() != '\n'){
      runArgReader(in, other...);
    }
  }
  void runArgReader(std::istream& in){
    return;
  }

  void read(std::ostream& out, const std::string& file){
    try{
      std::ifstream fin(file);
      char a = 0;
      fin >> std::noskipws;
      while (!fin.eof()){
        fin >> a;
        out << a;
      }
      fin.close();
    }
    catch (...){
      throw std::logic_error("<WRONG FILE NAME>");
    }
  }
  void decode(std::ostream& out, const std::string& binary,
    const std::string& codes, const std::string& text){

    std::ifstream finCode(codes, std::ios::in);
    codeWork::CodeTree codeTree(finCode, FROM_CODE_FILE);
    finCode.close();

    std::ifstream fin(binary, std::ios::binary);
    std::ofstream fout(text, std::ios::out);
    utils::BinaryWriter b;
    b.read(fout, fin, codeTree);
    fout.close();
    fin.close();
  }
  void encode(std::ostream& out, const std::string& text,
    const std::string& binary, const std::string& codes){
    try{
      std::ifstream fin(text, std::ios::in);
      codeWork::CodeTree codeTree;
      if (codes == ""){
        codeTree = codeWork::CodeTree(fin);
        fin.clear();
        fin.seekg(0);
      }
      else{
        std::ifstream finCode(codes, std::ios::in);
        codeTree = codeWork::CodeTree(finCode, FROM_CODE_FILE);
        finCode.close();
      }
      std::ofstream fout(binary, std::ios::binary);
      utils::BinaryWriter bw;
      bw.write(fout, fin, codeTree);
      fin.close();
      fout.close();
    }
    catch (...){
      throw;
    }
  }
  void makeCodes(std::ostream& out, const std::string& text,
    const std::string& codes){
    std::ifstream fin(text, std::ios::in);
    codeWork::CodeTree codeTree(fin);
    fin.close();
    //codeTree.print(out);
    std::ofstream fout(codes, std::ios::out);
    codeTree.print(fout);
    fout.close();
  }
}
