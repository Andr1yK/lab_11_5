#pragma once

#ifndef _PRINT_
#define _PRINT_

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

#include "./FlightInfo.hpp"
#include "./constants.cpp"
#include "./FileHelper.cpp"

using namespace std;

struct ColumnsWidth
{
  int id = 3;
  int name = 12;
  int type = 10;
  int seats = 11;
  int price = 8;
  int routeId = 10;
  int route = 15;
  int schedule = 35;

  const int length() const {
    return id + name + type + seats + price + routeId + route + schedule;
  }
};

string getTextSchedule(bool* schedule) {
  string result = "";

  int activeDays = 0;

  for(int i = 0; i < 7; i++) {
    activeDays += schedule[i];
  }

  int current = 0;

  for(int i = 0; i < 7; i++) {
    current += schedule[i];
    
    result += schedule[i]
      ? CONSTANTS::days[i] + (current < activeDays
        ? ", "
        : ""
      ) : "";
  }

  return result;
}

void PrintHeader() {
  const ColumnsWidth cw;

  cout << std::string(cw.length() + 25, '=') << endl;

  cout << setfill(' ') << right << "| " << setw(cw.id + 2) << "№" << " | "
  << setw(cw.name) << left << "Plane name" << " | "
    << setw(cw.type) << left << "Plane type" << " | "
    << setw(cw.seats) << "Seats count" << " | "
    << setw(cw.price) << "Price" << " | "
    << setw(cw.routeId) << "Route. id" << " | "
    << setw(cw.route) << "Route" << " | "
    << setw(cw.schedule) << "Schedule" << " |"
    << endl;

    cout << std::string(cw.length() + 25, '-') << endl;
}

void PrintRow(FlightInfo singleInfo) {
  const ColumnsWidth cw;

  cout << setfill(' ') << right << "| " << setw(cw.id) << singleInfo.id << " | "
    << setw(cw.name) << left << singleInfo.plane.name << " | "
    << setw(cw.type) << left << singleInfo.plane.type << " | "
    << setw(cw.seats) << singleInfo.plane.seatsCount << " | "
    << setw(cw.price) << singleInfo.plane.price << " | "
    << setw(cw.routeId) << singleInfo.direction.id << " | "
    << setw(cw.route) << singleInfo.direction.route << " | "
    << setw(cw.schedule) << getTextSchedule(singleInfo.direction.schedule) << " |"
    << endl;
}

void Print(char* fname)
{
  const ColumnsWidth cw;

  PrintHeader();

  ifstream f(fname, ios::binary);

  int size = FileHelper::getSize<FlightInfo>(f);

  for (int i = 0; i < size; i++)
  {
    PrintRow(FileHelper::fRead<FlightInfo>(f, i));

    if (i < size - 1)
      cout << std::string(cw.length() + 25, '-') << endl;
  }

  f.close();

  cout << std::string(cw.length() + 25, '=') << endl << endl;
}

void Print(char* fname, int index)
{
  const ColumnsWidth cw;

  PrintHeader();

  ifstream f(fname, ios::binary);
  
  PrintRow(FileHelper::fRead<FlightInfo>(f, index));

  f.close();

  cout << std::string(cw.length() + 25, '=') << endl;
  cout << endl;
}

void Print(FlightInfo info)
{
  const ColumnsWidth cw;

  PrintHeader();

  PrintRow(info);

  cout << std::string(cw.length() + 25, '=') << endl;
  cout << endl;
}

#endif