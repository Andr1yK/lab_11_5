#pragma once

#ifndef _GETPLANETYPESBYROUTEANDDAY_
#define _GETPLANETYPESBYROUTEANDDAY_

#include <string>
#include <fstream>

#include "./FlightInfo.hpp"
#include "./FileHelper.cpp"

using namespace std;

string getPlaneTypesByRouteAndDay(char* fname, string route, int day) {
  ifstream f(fname, ios::binary);

  string res = "";
  FlightInfo tempRoute;

  int size = FileHelper::getSize<FlightInfo>(f);
  
  for (int i = 0; i < size; i++) {
    tempRoute = FileHelper::fRead<FlightInfo>(f, i);

    res += tempRoute.direction.route == route && tempRoute.direction.schedule[day]
      ? tempRoute.plane.type + (i < size - 1 ? ", " : "") : "";

    res += "";
  }

  return res;
}

#endif // !_GETPLANETYPESBYROUTEANDDAY_
