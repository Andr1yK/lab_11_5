#pragma once

#ifndef _DELETEFIELD_
#define _DELETEFIELD_

#include <iostream>
#include <fstream>

#include "./getFieldIndexById.cpp"
#include "./FileHelper.cpp"
#include "./FlightInfo.hpp"

using namespace std;

void DeleteField(char* fname, int id) {
  fstream f(fname, ios::binary | ios::in | ios::out);
  fstream fTemp("__temp.tempData", ios::binary | ios::app);

  int size = FileHelper::getSize<FlightInfo>(f);
  FlightInfo tmp;

  for (int i = 0; i < size; i++) {
    tmp = FileHelper::fRead<FlightInfo>(f, i);

    if(tmp.id != id)
      FileHelper::fWrite(fTemp, tmp);
  }

  remove(fname);
  rename("__temp.tempData", fname);
}

void DeleteFieldsByDaysLessTwo(char* fname) {
  fstream f(fname, ios::binary | ios::in | ios::out);
  fstream fTemp("__temp.tempData", ios::binary | ios::app);

  int size = FileHelper::getSize<FlightInfo>(f);
  FlightInfo tmp;

  int activeDays = 0;

  for (int i = 0; i < size; i++) {
    tmp = FileHelper::fRead<FlightInfo>(f, i);

    for(int i = 0; i < 7; i++) {
      activeDays += tmp.direction.schedule[i];
      cout << tmp.direction.schedule[i] << endl;
    }

    if(activeDays > 1)
      FileHelper::fWrite(fTemp, tmp);

    activeDays = 0;
  }

  remove(fname);
  rename("__temp.tempData", fname);
}

#endif // !_DELETEFIELD_
