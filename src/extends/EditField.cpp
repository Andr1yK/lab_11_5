#pragma once

#ifndef _EDITFIELD_
#define _EDITFIELD_

#include <iostream>
#include <string>
#include <fstream>

#include "./FlightInfo.hpp"
#include "./FileHelper.cpp"
#include "./helpers.cpp"
#include "./print.cpp"
#include "./constants.cpp"
#include "./getFieldIndexById.cpp"

using namespace std;

void EditField(char* fname, int id) {
  fstream f(fname, ios::binary | ios::in | ios::out);

  int index = getFieldIndexById(f, id);

  if (index == -1) {
    cout << "Error: not valid ID" << endl;
    return;
  }

  FlightInfo initial = FileHelper::fRead<FlightInfo>(f, index);
  FlightInfo toEdit = FileHelper::fRead<FlightInfo>(f, index);

  char tempChar = '0';
  string tempStr;

  cin.get(); cin.sync();

  cout << "Edit field:" << endl;
  cout << " (if you don`t want edit, just press enter in current field)" << endl << endl;

  cout << " Plane name: "; getline(cin, tempStr);
  toEdit.plane.name = Helpers::trim(tempStr) != "" ? tempStr : initial.plane.name;
  cout << endl;

  cout << " Plane type: "; getline(cin, tempStr);
  toEdit.plane.type = Helpers::trim(tempStr) != "" ? tempStr : initial.plane.type;
  cout << endl;

  cout << " Seats count: "; getline(cin, tempStr);
  toEdit.plane.seatsCount = Helpers::trim(tempStr) != "" ? stoi(tempStr) : initial.plane.seatsCount;
  cout << endl;

  cout << " Price: "; getline(cin, tempStr);
  toEdit.plane.price = Helpers::trim(tempStr) != "" ? stoi(tempStr) : initial.plane.price;
  cout << endl;

  cout << " Route ID: "; getline(cin, tempStr);
  toEdit.direction.id = Helpers::trim(tempStr) != "" ? stoi(tempStr) : initial.direction.id;
  cout << endl;

  cout << " Route: "; getline(cin, tempStr);
  toEdit.direction.route = Helpers::trim(tempStr) != "" ? tempStr : initial.direction.route;
  cout << endl;

  cout << " Flight days (0 - no, 1 - yes, 2 - skip): " << endl;

  for(int i = 0; i < 7;) {
    cout << "  " << CONSTANTS::days[i] << ": "; cin >> tempChar;
    switch (tempChar)
    {
      case '0':
        toEdit.direction.schedule[i] = false;
        i++;
        break;

      case '1':
        toEdit.direction.schedule[i] = true;
        i++;
        break;

      case '2':
        toEdit.direction.schedule[i] = initial.direction.schedule[i];
        i++;
        break;
      
      default:
        cout << "Error: not valid input (valid: 0, 1 or enter)" << endl;
        break;
    }
  }

  cout << endl << "INITIAL: " << endl;
  Print(initial);

  cout << "EDITED: " << endl;
  Print(toEdit);

  cout << "Accept edited date (default = n)? y or n: "; cin >> tempChar;

  switch (tempChar)
  {
  case 'y':
    cout << "Edited" << endl;
    FileHelper::fWrite(f, index, toEdit);
    break;

  default:
    cout << "Reverted" << endl;
    break;
  }

  f.close();
}

#endif // !_EDITFIELD_
