#pragma once

#ifndef _CREATEFIELD_
#define _CREATEFIELD_

#include <iostream>
#include <string>
#include "./FlightInfo.hpp"
#include "./constants.cpp"

using namespace std;

FlightInfo CreateField() {
  FlightInfo info;

  info.id = ++FlightInfo::maxIndex;

  char temp = '0';

  cout << "New field:" << endl;

  cin.get(); cin.sync();

  cout << " Plane name: "; getline(cin, info.plane.name);
  cout << endl;
  cout << " Plane type: "; getline(cin, info.plane.type);
  cout << endl;
  cout << " Seats count: "; cin >> info.plane.seatsCount;
  cout << endl;
  cout << " Price: "; cin >> info.plane.price;
  cout << endl;

  cout << " Route ID: "; cin >> info.direction.id;
  cout << endl;
  cout << " Route: "; cin >> info.direction.route;
  cout << endl;

  cout << " Flight days: " << endl;

  for(int i = 0; i < 7;) {
    cout << "  " << CONSTANTS::days[i] << ": ";
    cin >> temp;
    switch (temp)
    {
      case '0':
        info.direction.schedule[i] = false;
        i++;
        break;

      case '1':
        info.direction.schedule[i] = true;
        i++;
        break;
      
      default:
        cout << "Error: not valid input" << endl;
        break;
    }
  }

  return info;
}

#endif // !_CREATEFIELD_
