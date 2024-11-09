#include "funz.h"

int main() {
    int choice;
    createTestData();

    do {
        cout << CYAN << "\n=== Car Sales Management System ===\n" << RESET;

        cout << YELLOW << "1. " << RESET << "Add Employee\n";
        cout << YELLOW << "2. " << RESET << "Delete Employee\n";
        cout << YELLOW << "3. " << RESET << "Add Car\n";
        cout << YELLOW << "4. " << RESET << "Delete Car\n";
        cout << YELLOW << "5. " << RESET << "Add Sale\n";
        cout << YELLOW << "6. " << RESET << "Delete Sale\n";
        cout << YELLOW << "7. " << RESET << "Save Data to File\n";
        cout << YELLOW << "8. " << RESET << "Load Data from File\n";
        cout << YELLOW << "9. " << RESET << "Show Reports Menu\n";
        cout << YELLOW << "10. " << RESET << "Exit\n";
        
        cout << CYAN << "Enter your choice: " << RESET;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                addCar();
                break;
            case 4:
                deleteCar();
                break;
            case 5:
                addSale();
                break;
            case 6:
                deleteSale();
                break;
            case 7: {
                string filename;
                cout << BLUE << "Enter filename to save data: " << RESET;
                getline(cin, filename);
                saveDataToFile(filename);
                break;
            }
            case 8: {
                string filename;
                cout << BLUE << "Enter filename to load data: " << RESET;
                getline(cin, filename);
                loadDataFromFile(filename);
                break;
            }
            case 9:
                showReportsMenu();
                break;
            case 10:
                cout << RED << "Exiting...\n" << RESET;
                break;
            default:
                cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }

    } while (choice != 10);

    return 0;
}