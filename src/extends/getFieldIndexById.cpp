#pragma once

#ifndef _GETFIELDINDEXBYID_
#define _GETFIELDINDEXBYID_

#include <fstream>

int getFieldIndexById(fstream& f, int id) {
  int size = FileHelper::getSize<FlightInfo>(f);

  for(int i = 0; i < size; i++)
    if (FileHelper::fRead<FlightInfo>(f, i).id == id)
      return i;

  return -1;
}

#endif // !_GETFIELDINDEXBYID_
