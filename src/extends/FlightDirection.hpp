#pragma once

#ifndef _FLIGHTDIRECTION_
#define _FLIGHTDIRECTION_

#include <string>

struct FlightDirection
{
  int id;
  std::string route;
  bool schedule[7];
  static int maxIndex;
};

int FlightDirection::maxIndex = 0;

#endif // !_FLIGHTDIRECTION_
