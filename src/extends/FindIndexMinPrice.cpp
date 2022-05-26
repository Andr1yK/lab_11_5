#pragma once

#ifndef _FINDINDEXMINPRICE_
#define _FINDINDEXMINPRICE_

#include <fstream>
#include <string>

#include "./FlightInfo.hpp"
#include "./FileHelper.cpp"

int FindIndexMinPrice(char* fname, string route) {
  fstream f(fname, ios::binary | ios::in);

  int size = FileHelper::getSize<FlightInfo>(f);
  int current;
  int min;
  int resIndex = -1;
  int index = 0;

  if (size > 0) {
    min = current = FileHelper::fRead<FlightInfo>(f, index).plane.price;
    resIndex = index;
  }

  for (; index < size; index++) {
    current = FileHelper::fRead<FlightInfo>(f, index).plane.price;

    if (current < min) {
      min = current;
      resIndex = index;
    }
  };

  f.close();

  return resIndex;
}

#endif // !_FINDINDEXMINPRICE_
