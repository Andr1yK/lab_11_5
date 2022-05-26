#pragma once

#ifndef _GETCOUNTOFSEATSBYROUTEANDDAY_
#define _GETCOUNTOFSEATSBYROUTEANDDAY_

#include <fstream>

#include "./FlightInfo.hpp"
#include "./FileHelper.cpp"

int getCountOfSeatsByRouteAndDay(char* fname, string route, int day) {
  ifstream f(fname, ios::binary);

  FlightInfo tempRoute;
  int res = 0;

  int size = FileHelper::getSize<FlightInfo>(f);

  for (int i = 0; i < size; i++) {
    tempRoute = FileHelper::fRead<FlightInfo>(f, i);

    res += (tempRoute.direction.route == route
      && tempRoute.direction.schedule[day]) * tempRoute.plane.seatsCount;
  }

  return res;
}

#endif // !_GETCOUNTOFSEATSBYROUTEANDDAY_
