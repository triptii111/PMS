#include <iostream>
#include "ParkingSystem.h"

using namespace std;

void displayMenu() {
    cout << "\n====================================\n";
    cout << "     PARKING MANAGEMENT SYSTEM      \n";
    cout << "====================================\n";
    cout << "1. Park Vehicle\n";
    cout << "2. Remove Vehicle\n";
    cout << "3. Search Vehicle\n";
    cout << "4. Display Parking Slots\n";
    cout << "5. Display Waiting Queue\n";
    cout << "6. Display Statistics\n";
    cout << "7. Exit\n";
    cout << "====================================\n";
    cout << "Enter your choice : ";
}

int main() {
    int totalSlots;

    cout << "====================================\n";
    cout << "     PARKING MANAGEMENT SYSTEM      \n";
    cout << "====================================\n";
    cout << "Enter total number of parking slots : ";
    cin >> totalSlots;

    if (totalSlots <= 0) {
        cout << "Invalid number of slots. Exiting.\n";
        return 1;
    }

    ParkingSystem ps(totalSlots);

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                ps.parkVehicle();
                break;

            case 2:
                ps.removeVehicle();
                break;

            case 3:
                ps.searchVehicle();
                break;

            case 4:
                ps.displaySlots();
                break;

            case 5:
                ps.displayQueue();
                break;

            case 6:
                ps.displayStats();
                break;

            case 7:
                cout << "\nThank you for using Parking Management System. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 7.\n";
        }

    } while (choice != 7);

    return 0;
}
