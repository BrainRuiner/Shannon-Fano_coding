#include "commands.hpp"
#include "../codeWork/CodeTree.hpp"
#include "../binaryWork/BinaryWriter.hpp"

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
          throw std::logic_error("FAIL: <No such command>");
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
      if (!fin){
        throw;
      }
      char a = 0;
      fin >> std::noskipws;
      while (!fin.eof()){
        fin >> a;
        out << a;
      }
      fin.close();
      out << "\n";
      out << "Read....COMPLETE\n";
    }
    catch (...){
      out << "Read....FAIL: ";
      throw std::logic_error("<WRONG FILE NAME>");
    }
  }
  void decode(std::ostream& out, const std::string& binary, const std::string& codes,
    const std::string& text){
    try{
      out << "Decode....";
      std::ifstream finCode(codes, std::ios::in);
      if (!finCode){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      codeWork::CodeTree codeTree(finCode, FROM_CODE_FILE);
      finCode.close();
      std::ifstream fin(binary, std::ios::binary);
      if (!fin){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      std::ofstream fout;
      if (text.length() == 0){
        fout.open("text" + binary);
      }
      else{
        fout.open(text);
      }
      if (!fout){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      binaryWork::BinaryWriter b;
      b.read(fout, fin, codeTree);
      fout.close();
      fin.close();
      out << "COMPLETE\n";
    }
    catch (...){
      out << "FAIL: ";
      throw;
    }
  }
  void encode(std::ostream& out, const std::string& text, const std::string& binary,
    const std::string& codes){
    try{
      out << "Encode....";
      std::ifstream fin(text);
      if (!fin){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      codeWork::CodeTree codeTree;
      std::ifstream finCodes(codes);
      if (finCodes){
        codeTree = codeWork::CodeTree(finCodes, FROM_CODE_FILE);
        finCodes.close();
      }
      else{
        codeTree = codeWork::CodeTree(fin);
        fin.clear();
        fin.seekg(0);
        if (codes.length() == 0){
          std::ofstream foutCodes("codes" + text);
          codeTree.print(foutCodes);
          foutCodes.close();
        }
      }
      std::ofstream fout;
      if (binary.length() == 0){
        fout.open("binary" + text);
      }
      else{
        fout.open(binary);
      }
      if (!fout){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      binaryWork::BinaryWriter bw;
      bw.write(fout, fin, codeTree);
      fin.close();
      fout.close();
      out << "COMPLETE\n";
    }
    catch (...){
      out << "FAIL: ";
      throw;
    }
  }
  void makeCodes(std::ostream& out, const std::string& text, const std::string& codes){
    try{
      out << "MakeCodes....";
      std::ifstream fin(text);
      if (!fin){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      codeWork::CodeTree codeTree(fin);
      fin.close();
      std::ofstream fout;
      if (codes.length() == 0){
        fout.open(text);
      }
      else{
        fout.open(codes);
      }
      if (!fout){
        throw std::logic_error("<WRONG FILE NAME>");
      }
      codeTree.print(fout);
      fout.close();
      out << "COMPLETE\n";
    }
    catch (...){
      out << "FAIL: ";
      throw;
    }
  }
}
