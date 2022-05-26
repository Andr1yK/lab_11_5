#pragma once

#ifndef _FLIGHTINFO_
#define _FLIGHTINFO_

#include "./Plane.hpp"
#include "./FlightDirection.hpp"

struct FlightInfo
{
  int id;
  Plane plane; // TODO: Add name
  FlightDirection direction; // TODO: Add direction name
  static int maxIndex;
};

int FlightInfo::maxIndex = 0;

#endif // !_FLIGHTINFO_
