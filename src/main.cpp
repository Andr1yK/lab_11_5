#include <iostream>
#include <string>

#include "./extends/FlightInfo.hpp"
#include "./extends/SaveToFile.cpp"
#include "./extends/print.cpp"
#include "./extends/AppendToFile.cpp"
#include "./extends/EditField.cpp"
#include "./extends/DeleteField.cpp"
#include "./extends/FindIndexMinPrice.cpp"
#include "./extends/constants.cpp"
#include "./extends/getPlaneTypesByRouteAndDay.cpp"
#include "./extends/getCountOfSeatsByRouteAndDay.cpp"

using namespace std;

int main()
{
  const int N = 3;
  FlightInfo info[N] = {
    {1, {"Boris", "m", 36, 120}, {1, "UK - USA", {1, 0, 0, 0, 0, 1, 0}}},
    {2, {"Doris", "s", 12, 3400}, {2, "All world", {1, 1, 1, 1, 1, 1, 1}}},
    {3, {"Gloris", "l", 56, 140}, {1, "UK - USA", {1, 0, 1, 0, 0, 1, 0}}}
  };

  FlightInfo::maxIndex = N;

  char fname[100] = "test";
  // cout << " Введіть ім'я файлу: "; cin.getline(fname, 99);

  SaveToFile(fname, info, N);

  int id = 0;
  string route;
  int day = 0;

  int menuItem;
  do {
    cout << endl << endl;
    cout << "Виберіть дію:" << endl << endl;
    cout << " [1] - Вивід даних на екран" << endl;
    cout << " [2] - Додати дані в файл" << endl;
    cout << " [3] - Редагувати дані" << endl;
    cout << " [4] - Видалити дані" << endl;
    cout << endl;

    cout << " [6] - Пошук рейсу з мінімальною ціною" << endl;
    cout << " [7] - Вивести тип літаків та сумарну кількість місьць за напрямком та днем" << endl;
    cout << " [8] - Вилучити всі рейси, де кількість польотів на тиждень менше двох" << endl;
    cout << endl;

    cout << " [10] - змінити файл" << endl;

    cout << endl;

    cout << " [0] - вихід та завершення роботи програми" << endl << endl;
    cout << "Введіть значення: "; cin >> menuItem;

    cout << endl << endl << endl;

    switch (menuItem)
    {
    case 1:
      Print(fname);
      break;

    case 2:
      AppendToFile(fname);
      break;

    case 3:
      cout << " Введіть ID запису: "; cin >> id;
      EditField(fname, id);
      break;

    case 4:
      cout << " Введіть ID запису: "; cin >> id;
      DeleteField(fname, id);
      break;

    case 6:
      cin.get(); cin.sync();
      cout << " Route: "; getline(cin, route);
      Print(fname, FindIndexMinPrice(fname, route));
      break;

    case 7:
      cin.get(); cin.sync();
      cout << " Route: "; getline(cin, route);
      cout << " Day = code:" << endl;

      for (int i = 0; i < 7; i ++)
        cout << "  " << CONSTANTS::days[i] << " = " << i << endl;

      do {
        cout << " Select day: "; cin >> day;
      } while (day < 0 || day > 6);

      cout << "Type (-s): " << getPlaneTypesByRouteAndDay(fname, route, day) << endl;
      cout << "Count of seats (-s): " << getCountOfSeatsByRouteAndDay(fname, route, day) << endl;

      
      cout << endl;
      break;

    case 8:
      DeleteFieldsByDaysLessTwo(fname);
      break;

    case 10:
      cin.get();
      cin.sync();

      cout << " Введіть ім'я файлу: "; cin.getline(fname, 99);
      break;

    case 0:
      break;

    default:
      cout << "Ви ввели помилкове значення! "
        "Слід ввести число - номер вибраного пункту меню" << endl;
    }
  } while (menuItem != 0);

  return 0;
}