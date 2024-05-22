#ifndef SHANNON_FANO_CODING_HPP
#define SHANNON_FANO_CODING_HPP

#include <string>
#include <vector>

namespace sfc
{
  class SFCoding
  {
    public:
    SFCoding();
    SFCoding(std::vector<std::string> files);
    SFCoding(const SFCoding& src) = delete;
    SFCoding(const SFCoding&& src) = delete;

    SFCoding& operator=(const SFCoding& src) = delete;
    SFCoding& operator=(const SFCoding&& src) = delete;

    private:
    std::vector<std::string> files;

  };
}

#endif
