#ifndef FUNZ_H
#define FUNZ_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"

using namespace std;

struct Employee {
    string fullName;
    string position;
    string phoneNumber;
    string email;
};

struct Car {
    string manufacturer;
    int year;
    string model;
    double costPrice;
    double salePrice;
};

struct Sale {
    Employee employee;
    Car car;
    string saleDate;
    double realSalePrice;
};

extern vector<Employee> employees;
extern vector<Car> cars;
extern vector<Sale> sales;

void addEmployee();
void deleteEmployee();
void addCar();
void deleteCar();
void addSale();
void deleteSale();
void createTestData();
void showReportsMenu();



void reportEmployeesInfo(bool toFile = false);
void reportCarsInfo(bool toFile = false);
void reportSalesInfo(bool toFile = false);
void reportSalesByDate(const string& date, bool toFile = false);
void reportSalesByPeriod(const string& startDate, const string& endDate, bool toFile = false);
void reportSalesByEmployee(const string& employeeName, bool toFile = false);
void reportMostPopularCar(const string& startDate, const string& endDate, bool toFile = false);
void reportTopEmployee(const string& startDate, const string& endDate, bool toFile = false);
void  reportTotalProfit(const string& startDate, const string& endDate, bool toFile = false);


void saveDataToFile(const string& filename);
void loadDataFromFile(const string& filename);

#endif