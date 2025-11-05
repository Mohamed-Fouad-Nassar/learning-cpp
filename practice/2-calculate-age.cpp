#include <iostream>
using namespace std;

int isLeap(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calcMaxDaysInMonth(int month, int year)
{
  int days;
  switch (month)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    days = 31;
    break;

  case 2:
    days = isLeap(year) ? 29 : 28;
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    days = 30;
    break;

  default:
    days = 0;
  }
  return days;
}

void calculatePrintAge(int _day, int _month, int _year)
{
  int ageDays, ageMonths, ageYears;
  int curDay = 20, curMonth = 10, curYear = 2025;

  ageYears = curYear - _year;

  if (curMonth < _month)
  {
    ageYears--;
    ageMonths = curMonth + (12 - _month);
  }
  else
    ageMonths = curMonth - _month;

  if (curDay < _day)
  {
    ageMonths--;
    ageDays = curDay + (calcMaxDaysInMonth(_month, _year) - _day);
  }
  else
    ageDays = curDay - _day;

  cout << "You are " << ageYears << " years, " << ageMonths << " Month, and " << ageDays << " days old." << endl;
}

int main()
{
  char cont;
  do
  {
    int day, month, year;
    cout << "Enter your birth date (DD MM YYYY): ";
    cin >> day >> month >> year;

    calculatePrintAge(day, month, year);

    cout << "Continue? (y/n): ";
    cin >> cont;
  } while (cont == 'y' || cont == 'Y');

  return 0;
}