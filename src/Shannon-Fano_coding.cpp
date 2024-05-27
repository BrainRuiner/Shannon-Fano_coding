#include "Shannon-Fano_coding.hpp"

void readCommands(std::istream& in, std::ostream& out);
std::ostream& decode(std::istream& in, std::ostream& out);
std::ostream& encode(std::istream& in, std::ostream& out);
char* decode(char* dest, char* src, const bTree& codes);
char* encode(char* dest, char* src, const bTree& codes);
bTree& generateCodes(bTree& dest, char* src);
