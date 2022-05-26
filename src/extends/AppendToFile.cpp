#pragma once

#ifndef _APPENDTOFILE_
#define _APPENDTOFILE_

#include <fstream>
#include "./FlightInfo.hpp"
#include "./FileHelper.cpp"
#include "./CreateField.cpp"

void AppendToFile(char* fname) {
  fstream toFile(fname, ios::binary | ios::app);

  FileHelper::fWrite(toFile, CreateField());

  toFile.close();
}

#endif // !_APPENDTOFILE_
