#pragma once

#ifndef _HELPERS_
#define _HELPERS_

#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
class Helpers
{
protected:
  inline static const string WHITESPACE = " \n\r\t\f\v";

public:
  static string ltrim(const string &s)
  {
      size_t start = s.find_first_not_of(WHITESPACE);
      return (start == string::npos) ? "" : s.substr(start);
  }
  
  static string rtrim(const string &s)
  {
      size_t end = s.find_last_not_of(WHITESPACE);
      return (end == string::npos) ? "" : s.substr(0, end + 1);
  }
  
  static const string trim(const string &s) {
      return rtrim(ltrim(s));
  }
};


#endif
