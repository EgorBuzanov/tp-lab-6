// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <iostream>
#include <random>
#include <string>

#include "Employee.h"
#include "Interfaces.h"
#include "Personal.h"

class Personal;
class Project;
class ProjectBudget;
class Heading;
class WorkBaseTime;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project *project;
  double part;

 public:
  Engineer();
  Engineer(int _id, std::string _name, int _salary, Project *_project,
           double _part);
  unsigned int calcBonus() override;
  unsigned int calcProAdditions() override;
  unsigned int calcBudgetPart(double part, unsigned int budget) override;
  void calc() override;
  void printInfo() override;
};

class Programmer : public Engineer {
 public:
  Programmer();
  Programmer(int _id, std::string _name, int _salary, Project *_project,
             double _part);
  unsigned int calcProAdditions() override;
  void calc() override;
};

class Tester : public Engineer {
 public:
  Tester(int _id, std::string _name, int _salary, Project *_project,
         double _part);
  unsigned int calcProAdditions() override;
  void calc() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int _id, std::string _name, int _salary, Project *_project,
             double _part);
  unsigned int calcHeads() override;
  void calc() override;
};

#endif  // INCLUDE_ENGINEER_H_
