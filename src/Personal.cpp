// Copyright 2021 Egor Buzanov

#include "Personal.h"

unsigned int Personal::calcBase() { return worktime * salary; }

void Personal::printInfo() {
  std::cout << id << " " << name << " " << position << " " << worktime << " "
            << payment << " " << salary << std::endl;
}

unsigned int Driver::calcBonus() {
  if (worktime > 40) {
    return 5000;
  }
}

void Driver::calc() { payment = calcBase() + calcBonus(); }

void Cleaner::calc() { payment = calcBase() + calcBonus(); }

Driver::Driver(int _id, std::string _name, int _salary) {
  id = _id;
  name = _name;
  salary = _salary;
  worktime = 0;
  payment = 0;
  position = DRIVER;
}

Cleaner::Cleaner(int _id, std::string _name, int _salary) {
  id = _id;
  name = _name;
  salary = _salary;
  worktime = 0;
  payment = 0;
  position = CLEANER;
}

unsigned int Cleaner::calcBonus() {
  if (worktime > 20) {
    return 5000;
  }
}
