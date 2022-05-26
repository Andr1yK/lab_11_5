#pragma once

#ifndef _FILEHELPER_
#define _FILEHELPER_

#include <fstream>

using namespace std;

class FileHelper {
public:
  template <class T>
  static void fWrite(ofstream& f, const int index, const T object) {
    f.seekp( index * (long)sizeof(T));
    f.write((char*)&object, sizeof(T));
  }

  template <class T>
  static void fWrite(fstream& f, const int index, const T object) {
    f.seekp( index * (long)sizeof(T));
    f.write((char*)&object, sizeof(T));
  }

  template <class T>
  static void fWrite(fstream& f, const T object) {
    f.write((char*)&object, sizeof(T));
  }

  template <class T>
  static T fRead(fstream& f, const int index)
  {
    T object;

    f.seekg( index * (long)sizeof(T));
    f.read ((char*)&object, sizeof(T));

    return object;
  }

  template <class T>
  static T fRead(ifstream& f, const int index)
  {
    T object;

    f.seekg( index * (long)sizeof(T));
    f.read ((char*)&object, sizeof(T));

    return object;
  }

  template <class T>
  static void fChange(fstream& f, const int indexFirst, const int indexSecond) {
    T firstObject = fRead<T>(f, indexFirst);
    T secondObject = fRead<T>(f, indexSecond);
    
    fWrite<T>(f, indexFirst, secondObject);
    fWrite<T>(f, indexSecond, firstObject);
  }

  template <class T>
  static int getSize(fstream& f) {
    const int pos = f.tellg();

    f.seekg(0, ios::end);
    int size = f.tellg() / sizeof(T);
    f.seekg(pos, ios::beg);

    return size;
  }

  template <class T>
  static int getSize(ifstream& f) {
    const int pos = f.tellg();

    f.seekg(0, ios::end);
    int size = f.tellg() / sizeof(T);
    f.seekg(pos, ios::beg);

    return size;
  }
};

#endif