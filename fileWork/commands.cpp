#include "commands.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include "../codeWork/Dictionary.hpp"
#include "../utils/BinaryWriter.hpp"

namespace fileWork{
  void runCommandLoop(std::ostream& out, std::istream& in){
    std::string cmd = "";
    out << '>';
    while (in >> cmd){
      try{
        if (cmd == "rt"){
          std::string text = "";
          in >> text;
          readText(out, text);
        }
        else if (cmd == "rb"){
          std::string binary = "";
          in >> binary;
          readBinary(out, binary);
        }
        else if (cmd == "d"){
          std::string binary = "";
          std::string code = "";
          std::string text = "";
          in >> binary >> code >> text;
          decode(out, binary, code, text);
        }
        else if (cmd == "e"){
          std::string text = "";
          std::string binary = "";
          std::string code = "";
          in >> text >> binary >> code;
          encode(out, text, binary, code);
        }
        else if (cmd == "m"){
          std::string text = "";
          std::string code = "";
          makeCodes(out, text, code);
        }
        else{
          throw std::logic_error("FAIL: INVALID COMMAND");
        }
      }
      catch (const std::exception& e){
        std::cerr << e.what() << '\n';
      }
      out << ">";
    }
  }
  void readText(std::ostream& out, const std::string& text){
    try{
      std::ifstream fin(text, std::ios::in);
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
  void readBinary(std::ostream& out, const std::string& binary){
    try{
      std::ifstream fin(binary, std::ios::binary | std::ios::ate);
      auto size = fin.tellg();
      std::string str(size, '\0');
      fin.seekg(0);
      if (fin.read(&str[0], size)){
        out << str << '\n';
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
    codeWork::Dictionary dict(finCode, FROM_CODE_FILE);
    finCode.close();

    std::ifstream fin(binary, std::ios::binary);
    std::ofstream fout(text, std::ios::out);
    utils::BinaryWriter b;
    b.read(fout, fin, dict);
    fout.close();
    fin.close();
  }
  //В бинарные файлы нужно по особому записывать
  //Группируя по октавам. Не забудь переделать
  void encode(std::ostream& out, const std::string& text,
    const std::string& binary, const std::string& codes){
    try{
      std::ifstream fin(text, std::ios::in);
      codeWork::Dictionary dict;
      if (codes == ""){
        dict = codeWork::Dictionary(fin);
        fin.clear();
        fin.seekg(0);
      }
      else{
        std::ifstream finCode(codes, std::ios::in);
        dict = codeWork::Dictionary(finCode, FROM_CODE_FILE);
        finCode.close();
      }
      std::ofstream fout(binary, std::ios::binary);
      utils::BinaryWriter bw;
      bw.write(fout, fin, dict);
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
    codeWork::Dictionary dict(fin);
    fin.close();
    dict.print(out);
    std::ofstream fout(codes, std::ios::out);
    dict.print(fout);
    fout.close();
  }
}
