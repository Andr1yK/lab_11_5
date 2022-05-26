#pragma once

#ifndef _CONSTANTS_
#define _CONSTANTS_

#include <string>

struct CONSTANTS {
  static std::string days[7];
};

std::string CONSTANTS::days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

#endif // !_CONSTANTS_
