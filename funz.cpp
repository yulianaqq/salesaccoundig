#include "funz.h"

vector<Employee> employees;
vector<Car> cars;
vector<Sale> sales;

void addEmployee() {
    Employee emp;
    cout << CYAN << "Enter employee's full name: " << RESET;
    getline(cin, emp.fullName);
    cout << CYAN << "Enter employee's position: " << RESET;
    getline(cin, emp.position);
    cout << CYAN << "Enter employee's phone number: " << RESET;
    getline(cin, emp.phoneNumber);
    cout << CYAN << "Enter employee's email: " << RESET;
    getline(cin, emp.email);
    employees.push_back(emp);
    cout << GREEN << "Employee added successfully!" << RESET << "\n";
}

void deleteEmployee() {
    string name;
    cout << CYAN << "Enter employee's full name to delete: " << RESET;
    getline(cin, name);
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->fullName == name) {
            employees.erase(it);
            cout << GREEN << "Employee deleted successfully!" << RESET << "\n";
            return;
        }
    }
    cout << RED << "Employee not found." << RESET << "\n";
}

void addCar() {
    Car car;
    cout << CYAN << "Enter car manufacturer: " << RESET;
    getline(cin, car.manufacturer);
    cout << CYAN << "Enter car year of manufacture: " << RESET;
    cin >> car.year;
    cin.ignore();
    cout << CYAN << "Enter car model: " << RESET;
    getline(cin, car.model);
    cout << CYAN << "Enter car cost price: " << RESET;
    cin >> car.costPrice;
    cout << CYAN << "Enter car sale price: " << RESET;
    cin >> car.salePrice;
    cin.ignore(); 
    cars.push_back(car); 
    cout << GREEN << "Car added successfully!" << RESET << "\n";
}


void deleteCar() {
    string model;
    cout << CYAN << "Enter car model to delete: " << RESET;
    getline(cin, model);
    
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->model == model) {
            cars.erase(it); // Remove car from the vector
            cout << GREEN << "Car deleted successfully!" << RESET << "\n";
            return;
        }
    }
    cout << RED << "Car not found." << RESET << "\n";
}

void addSale() {
    string employeeName, carModel;
    Sale sale;

    cout << CYAN << "Enter employee's full name: " << RESET;
    getline(cin, employeeName);

    bool employeeFound = false;
    for (const auto& emp : employees) {
        if (emp.fullName == employeeName) {
            sale.employee = emp;
            employeeFound = true;
            break;
        }
    }
    if (!employeeFound) {
        cout << RED << "Employee not found." << RESET << "\n";
        return;
    }

    cout << CYAN << "Enter car model: " << RESET;
    getline(cin, carModel);

    bool carFound = false;
    for (const auto& car : cars) {
        if (car.model == carModel) {
            sale.car = car;
            carFound = true;
            break;
        }
    }
    if (!carFound) {
        cout << RED << "Car not found." << RESET << "\n";
        return;
    }

    cout << CYAN << "Enter sale date: " << RESET;
    getline(cin, sale.saleDate);
    cout << CYAN << "Enter real sale price: " << RESET;
    cin >> sale.realSalePrice;
    cin.ignore();

    sales.push_back(sale);
    cout << GREEN << "Sale added successfully!" << RESET << "\n";
}

void deleteSale() {
    string carModel;
    cout << CYAN << "Enter car model of the sale to delete: " << RESET;
    getline(cin, carModel);

    for (auto it = sales.begin(); it != sales.end(); ++it) {
        if (it->car.model == carModel) {
            sales.erase(it);
            cout << GREEN << "Sale deleted successfully!" << RESET << "\n";
            return;
        }
    }
    cout << RED << "Sale not found." << RESET << "\n";
}

void createTestData() {
 
    employees.push_back({"John Doe", "Sales Manager", "123-456-7890", "john.doe@example.com"});
    employees.push_back({"Jane Smith", "Sales Assistant", "987-654-3210", "jane.smith@example.com"});

   
    cars.push_back({"Toyota", 2020, "Camry", 20000.0, 25000.0});
    cars.push_back({"Honda", 2021, "Civic", 18000.0, 23000.0});
    cars.push_back({"Ford", 2019, "Mustang", 26000.0, 30000.0});

    sales.push_back({employees[0], cars[0], "2023-11-01", 24500.0});
    sales.push_back({employees[1], cars[1], "2023-11-03", 22500.0});

    cout << GREEN << "Test data created successfully!" << RESET << "\n";
}



void reportEmployeesInfo(bool toFile) {
    if (toFile) {
        ofstream outFile("employees_report.txt");
        for (const auto& emp : employees) {
            outFile << "Name: " << emp.fullName << ", Position: " << emp.position
                    << ", Phone: " << emp.phoneNumber << ", Email: " << emp.email << "\n";
        }
        outFile.close();
        cout << GREEN << "Employee report saved to employees_report.txt" << RESET << "\n";
    } else {
        for (const auto& emp : employees) {
            cout << CYAN << "Name: " << RESET << emp.fullName
                 << CYAN << ", Position: " << RESET << emp.position
                 << CYAN << ", Phone: " << RESET << emp.phoneNumber
                 << CYAN << ", Email: " << RESET << emp.email << "\n";
        }
    }
}

void reportCarsInfo(bool toFile) {
    if (toFile) {
        ofstream outFile("cars_report.txt");
        for (const auto& car : cars) {
            outFile << "Manufacturer: " << car.manufacturer << ", Year: " << car.year
                    << ", Model: " << car.model << ", Cost Price: $" << car.costPrice
                    << ", Sale Price: $" << car.salePrice << "\n";
        }
        outFile.close();
        cout << GREEN << "Car report saved to cars_report.txt" << RESET << "\n";
    } else {
        for (const auto& car : cars) {
            cout << BLUE << "Manufacturer: " << RESET << car.manufacturer
                 << BLUE << ", Year: " << RESET << car.year
                 << BLUE << ", Model: " << RESET << car.model
                 << BLUE << ", Cost Price: $" << RESET << car.costPrice
                 << BLUE << ", Sale Price: $" << RESET << car.salePrice << "\n";
        }
    }
}

void reportSalesInfo(bool toFile) {
    if (toFile) {
        ofstream outFile("sales_report.txt");
        for (const auto& sale : sales) {
            outFile << "Employee: " << sale.employee.fullName << ", Car: " << sale.car.model
                    << ", Date: " << sale.saleDate << ", Sale Price: $" << sale.realSalePrice << "\n";
        }
        outFile.close();
        cout << GREEN << "Sales report saved to sales_report.txt" << RESET << "\n";
    } else {
        for (const auto& sale : sales) {
            cout << YELLOW << "Employee: " << RESET << sale.employee.fullName
                 << YELLOW << ", Car: " << RESET << sale.car.model
                 << YELLOW << ", Date: " << RESET << sale.saleDate
                 << YELLOW << ", Sale Price: $" << RESET << sale.realSalePrice << "\n";
        }
    }
}

void reportSalesByDate(const string& date, bool toFile) {
    if (toFile) {
        ofstream outFile("sales_by_date_report.txt");
        for (const auto& sale : sales) {
            if (sale.saleDate == date) {
                outFile << "Employee: " << sale.employee.fullName << ", Car: " << sale.car.model
                        << ", Date: " << sale.saleDate << ", Sale Price: $" << sale.realSalePrice << "\n";
            }
        }
        outFile.close();
        cout << GREEN << "Sales report for " << date << " saved to sales_by_date_report.txt" << RESET << "\n";
    } else {
        bool reportFound = false;
        for (const auto& sale : sales) {
            if (sale.saleDate == date) {
                cout << CYAN << "Employee: " << RESET << sale.employee.fullName
                     << CYAN << ", Car: " << RESET << sale.car.model
                     << CYAN << ", Date: " << RESET << sale.saleDate
                     << CYAN << ", Sale Price: $" << RESET << sale.realSalePrice << "\n";
                reportFound = true;
            }
        }
        if (!reportFound) {
            cout << RED << "No sales found for the date: " << date << RESET << "\n";
        }
    }
}

bool isWithinPeriod(const string& saleDate, const string& startDate, const string& endDate) {
    return saleDate >= startDate && saleDate <= endDate;
}

void reportSalesByPeriod(const string& startDate, const string& endDate, bool toFile) {
    if (toFile) {
        ofstream outFile("sales_by_period_report.txt");
        for (const auto& sale : sales) {
            if (isWithinPeriod(sale.saleDate, startDate, endDate)) {
                outFile << "Employee: " << sale.employee.fullName << ", Car: " << sale.car.model
                        << ", Date: " << sale.saleDate << ", Sale Price: $" << sale.realSalePrice << "\n";
            }
        }
        outFile.close();
        cout << GREEN << "Sales report for period " << startDate << " to " << endDate
             << " saved to sales_by_period_report.txt" << RESET << "\n";
    } else {
        bool reportFound = false;
        for (const auto& sale : sales) {
            if (isWithinPeriod(sale.saleDate, startDate, endDate)) {
                cout << CYAN << "Employee: " << RESET << sale.employee.fullName
                     << CYAN << ", Car: " << RESET << sale.car.model
                     << CYAN << ", Date: " << RESET << sale.saleDate
                     << CYAN << ", Sale Price: $" << RESET << sale.realSalePrice << "\n";
                reportFound = true;
            }
        }
        if (!reportFound) {
            cout << RED << "No sales found for the period " << startDate << " to " << endDate << RESET << "\n";
        }
    }
}

void reportSalesByEmployee(const string& employeeName, bool toFile) {
    if (toFile) {
        ofstream outFile("sales_by_employee_report.txt");
        for (const auto& sale : sales) {
            if (sale.employee.fullName == employeeName) {
                outFile << "Car: " << sale.car.model << ", Date: " << sale.saleDate
                        << ", Sale Price: $" << sale.realSalePrice << "\n";
            }
        }
        outFile.close();
        cout << GREEN << "Sales report for employee " << employeeName
             << " saved to sales_by_employee_report.txt" << RESET << "\n";
    } else {
        bool reportFound = false;
        for (const auto& sale : sales) {
            if (sale.employee.fullName == employeeName) {
                cout << CYAN << "Car: " << RESET << sale.car.model
                     << CYAN << ", Date: " << RESET << sale.saleDate
                     << CYAN << ", Sale Price: $" << RESET << sale.realSalePrice << "\n";
                reportFound = true;
            }
        }
        if (!reportFound) {
            cout << RED << "No sales found for employee: " << employeeName << RESET << "\n";
        }
    }
}

void reportMostPopularCar(const string& startDate, const string& endDate, bool toFile) {
    unordered_map<string, int> carSalesCount;
    for (const auto& sale : sales) {
        if (isWithinPeriod(sale.saleDate, startDate, endDate)) {
            carSalesCount[sale.car.model]++;
        }
    }
    
    string mostPopularCar;
    int maxSales = 0;
    for (const auto& pair : carSalesCount) {
        if (pair.second > maxSales) {
            mostPopularCar = pair.first;
            maxSales = pair.second;
        }
    }
    
    if (toFile) {
        ofstream outFile("most_popular_car_report.txt");
        outFile << "Most Popular Car: " << mostPopularCar << " with " << maxSales << " sales\n";
        outFile.close();
        cout << GREEN << "Most popular car report saved to most_popular_car_report.txt" << RESET << "\n";
    } else {
        if (mostPopularCar.empty()) {
            cout << RED << "No sales found for the given period." << RESET << "\n";
        } else {
            cout << CYAN << "Most Popular Car: " << RESET << mostPopularCar 
                 << CYAN << " with " << RESET << maxSales << CYAN << " sales" << RESET << "\n";
        }
    }
}

void reportTopEmployee(const string& startDate, const string& endDate, bool toFile) {
    unordered_map<string, int> employeeSalesCount;
    for (const auto& sale : sales) {
        if (isWithinPeriod(sale.saleDate, startDate, endDate)) {
            employeeSalesCount[sale.employee.fullName]++;
        }
    }

    string bestEmployee;
    int maxSales = 0;
    for (const auto& pair : employeeSalesCount) {
        if (pair.second > maxSales) {
            bestEmployee = pair.first;
            maxSales = pair.second;
        }
    }

    if (toFile) {
        ofstream outFile("best_employee_report.txt");
        outFile << "Best Employee: " << bestEmployee << " with " << maxSales << " sales\n";
        outFile.close();
        cout << GREEN << "Best employee report saved to best_employee_report.txt" << RESET << "\n";
    } else {
        if (bestEmployee.empty()) {
            cout << RED << "No sales found for the given period." << RESET << "\n";
        } else {
            cout << CYAN << "Best Employee: " << RESET << bestEmployee 
                 << CYAN << " with " << RESET << maxSales << CYAN << " sales" << RESET << "\n";
        }
    }
}
void reportTotalProfit(const string& startDate, const string& endDate, bool toFile) {
    double totalProfit = 0;
    for (const auto& sale : sales) {
        if (isWithinPeriod(sale.saleDate, startDate, endDate)) {
            totalProfit += sale.realSalePrice - sale.car.costPrice;
        }
    }

    if (toFile) {
        ofstream outFile("total_profit_report.txt");
        outFile << "Total Profit for period " << startDate << " to " << endDate << ": $" << totalProfit << "\n";
        outFile.close();
        cout << GREEN << "Total profit report saved to total_profit_report.txt" << RESET << "\n";
    } else {
        cout << CYAN << "Total Profit for period " << startDate << " to " << endDate << ": $" << totalProfit << RESET << "\n";
    }
}


void saveDataToFile(const string& filename) {
    ofstream outFile(filename);
   
    outFile << employees.size() << "\n";
    for (const auto& emp : employees) {
        outFile << emp.fullName << "\n" << emp.position << "\n" << emp.phoneNumber << "\n" << emp.email << "\n";
    }

    outFile << cars.size() << "\n";
    for (const auto& car : cars) {
        outFile << car.manufacturer << "\n" << car.year << "\n" << car.model << "\n" << car.costPrice << "\n" << car.salePrice << "\n";
    }

    outFile << sales.size() << "\n";
    for (const auto& sale : sales) {
        outFile << sale.employee.fullName << "\n" << sale.car.model << "\n" << sale.saleDate << "\n" << sale.realSalePrice << "\n";
    }
    outFile.close();
    cout << GREEN << "Data saved to " << filename << " successfully." << RESET << "\n";
}

void loadDataFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << RED << "Error opening file " << filename << RESET << "\n";
        return;
    }
   
    size_t empSize;
    inFile >> empSize;
    inFile.ignore();
    employees.clear();
    for (size_t i = 0; i < empSize; ++i) {
        Employee emp;
        getline(inFile, emp.fullName);
        getline(inFile, emp.position);
        getline(inFile, emp.phoneNumber);
        getline(inFile, emp.email);
        employees.push_back(emp);
    }
    
    size_t carSize;
    inFile >> carSize;
    inFile.ignore();
    cars.clear();
    for (size_t i = 0; i < carSize; ++i) {
        Car car;
        getline(inFile, car.manufacturer);
        inFile >> car.year;
        inFile.ignore();
        getline(inFile, car.model);
        inFile >> car.costPrice >> car.salePrice;
        inFile.ignore();
        cars.push_back(car);
    }
   
    size_t saleSize;
    inFile >> saleSize;
    inFile.ignore();
    sales.clear();
    for (size_t i = 0; i < saleSize; ++i) {
        Sale sale;
        string employeeName, carModel;
        getline(inFile, employeeName);
        getline(inFile, carModel);
        getline(inFile, sale.saleDate);
        inFile >> sale.realSalePrice;
        inFile.ignore();

    
        for (const auto& emp : employees) {
            if (emp.fullName == employeeName) {
                sale.employee = emp;
                break;
            }
        }

        for (const auto& car : cars) {
            if (car.model == carModel) {
                sale.car = car;
                break;
            }
        }
        sales.push_back(sale);
    }
    inFile.close();
    cout << GREEN << "Data loaded from " << filename << " successfully." << RESET << "\n";
}
void showReportsMenu() {
    int choice;
    bool toFile;

    cout << GREEN << "\nReports Menu\n" << RESET;
    cout << "1. Full information about employees\n";
    cout << "2. Full information about cars\n";
    cout << "3. Full information about sales\n";
    cout << "4. Sales for a specific date\n";
    cout << "5. Sales for a specific period\n";
    cout << "6. Sales by specific employee\n";
    cout << "7. Most popular car in a specific period\n";
    cout << "8. Top employee in a specific period\n";
    cout << "9. Total profit in a specific period\n";
    cout << "10. Back to main menu\n";
    cout << CYAN << "Enter your choice: " << RESET;
    cin >> choice;
    cin.ignore();

    if (choice >= 1 && choice <= 9) {
        cout << CYAN << "Do you want to output to file? (1 for Yes, 0 for No): " << RESET;
        cin >> toFile;
        cin.ignore();
    }

    string date, startDate, endDate, employeeName;

    switch (choice) {
        case 1: 
            reportEmployeesInfo(toFile); 
            break;
        case 2: 
            reportCarsInfo(toFile); 
            break;
        case 3: 
            reportSalesInfo(toFile); 
            break;
        case 4: 
            cout << CYAN << "Enter date (YYYY-MM-DD): " << RESET;
            getline(cin, date);
            reportSalesByDate(date, toFile); 
            break;
        case 5: 
            cout << CYAN << "Enter start date (YYYY-MM-DD): " << RESET;
            getline(cin, startDate);
            cout << CYAN << "Enter end date (YYYY-MM-DD): " << RESET;
            getline(cin, endDate);
            reportSalesByPeriod(startDate, endDate, toFile); 
            break;
        case 6: 
            cout << CYAN << "Enter employee's full name: " << RESET;
            getline(cin, employeeName);
            reportSalesByEmployee(employeeName, toFile); 
            break;
        case 7: 
            cout << CYAN << "Enter start date (YYYY-MM-DD): " << RESET;
            getline(cin, startDate);
            cout << CYAN << "Enter end date (YYYY-MM-DD): " << RESET;
            getline(cin, endDate);
            reportMostPopularCar(startDate, endDate, toFile); 
            break;
        case 8: 
            cout << CYAN << "Enter start date (YYYY-MM-DD): " << RESET;
            getline(cin, startDate);
            cout << CYAN << "Enter end date (YYYY-MM-DD): " << RESET;
            getline(cin, endDate);
            reportTopEmployee(startDate, endDate, toFile); 
            break;
        case 9: 
            cout << CYAN << "Enter start date (YYYY-MM-DD): " << RESET;
            getline(cin, startDate);
            cout << CYAN << "Enter end date (YYYY-MM-DD): " << RESET;
            getline(cin, endDate);
            reportTotalProfit(startDate, endDate, toFile); 
            break;
        case 10: 
            cout << GREEN << "Returning to main menu...\n" << RESET; 
            break;
        default: 
            cout << RED << "Invalid choice. Try again.\n" << RESET;
    }
}