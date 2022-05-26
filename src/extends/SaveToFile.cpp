#pragma once

#ifndef _SAVE_TO_FILE_
#define _SAVE_TO_FILE_

#include <fstream>
#include <string>
#include "./FlightInfo.hpp"
#include "./FileHelper.cpp"

using namespace std;

void SaveToFile(const char* filename, FlightInfo* info, const int N)
{
  ofstream toFile(filename, ios::binary);

  for (int index = 0; index < N; index++) {
    FileHelper::fWrite(toFile, index, info[index]);
  };

  toFile.close();
}

#endif