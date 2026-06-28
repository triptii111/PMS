#include "ParkingSystem.h"
#include <iomanip>

ParkingSystem::ParkingSystem(int n) {
    totalSlots = n;
    parkingSlots.resize(n);
    slotOccupied.resize(n, false);
}

// Scan all slots and return index of first empty one, -1 if full
int ParkingSystem::findEmptySlot() {
    for (int i = 0; i < totalSlots; i++) {
        if (!slotOccupied[i]) {
            return i;
        }
    }
    return -1;
}

// Place a vehicle into a specific slot and update the map
void ParkingSystem::assignSlot(int slotIndex, Vehicle v) {
    parkingSlots[slotIndex] = v;
    slotOccupied[slotIndex] = true;
    vehicleMap[v.regNumber] = slotIndex + 1;  // store as 1-based slot number
}

void ParkingSystem::parkVehicle() {
    string reg, owner, type;

    cout << "\nEnter Registration Number : ";
    cin >> reg;

    // Check if vehicle is already parked
    if (vehicleMap.find(reg) != vehicleMap.end()) {
        cout << "This vehicle is already parked in Slot " << vehicleMap[reg] << ".\n";
        return;
    }

    // Also check waiting queue is not fooled
    cout << "Enter Owner Name          : ";
    cin.ignore();
    getline(cin, owner);

    cout << "Enter Vehicle Type (Car/Bike) : ";
    cin >> type;

    Vehicle v(reg, owner, type);

    int slot = findEmptySlot();

    if (slot == -1) {
        // Parking is full, add vehicle to waiting queue
        waitingQueue.push(v);
        cout << "\nParking is full. Vehicle added to waiting queue.\n";
        cout << "Queue Position : " << waitingQueue.size() << "\n";
    } else {
        // Assign first available slot to the vehicle
        assignSlot(slot, v);
        cout << "\nVehicle Parked Successfully.\n";
        cout << "Assigned Slot  : " << (slot + 1) << "\n";
    }
}

void ParkingSystem::removeVehicle() {
    string reg;
    cout << "\nEnter Registration Number : ";
    cin >> reg;

    // Search using hash map for O(1) lookup
    if (vehicleMap.find(reg) == vehicleMap.end()) {
        cout << "Vehicle not found in parking.\n";
        return;
    }

    int slot = vehicleMap[reg] - 1;  // convert to 0-based index

    cout << "\nVehicle Removed Successfully.\n";
    cout << "Slot " << (slot + 1) << " is now free.\n";

    // Clear the slot
    slotOccupied[slot] = false;
    parkingSlots[slot] = Vehicle();
    vehicleMap.erase(reg);

    // If a vehicle is waiting, move it into the freed slot
    if (!waitingQueue.empty()) {
        Vehicle nextVehicle = waitingQueue.front();
        waitingQueue.pop();

        assignSlot(slot, nextVehicle);

        cout << "\nWaiting vehicle moved to Slot " << (slot + 1) << " automatically.\n";
        cout << "Registration   : " << nextVehicle.regNumber << "\n";
        cout << "Owner          : " << nextVehicle.ownerName << "\n";
    }
}

void ParkingSystem::searchVehicle() {
    string reg;
    cout << "\nEnter Registration Number : ";
    cin >> reg;

    // O(1) average time lookup using unordered_map
    if (vehicleMap.find(reg) == vehicleMap.end()) {
        cout << "Vehicle not found.\n";
        return;
    }

    int slot = vehicleMap[reg] - 1;
    Vehicle v = parkingSlots[slot];

    cout << "\n--- Vehicle Found ---\n";
    cout << "Slot Number  : " << (slot + 1) << "\n";
    cout << "Reg Number   : " << v.regNumber << "\n";
    cout << "Owner Name   : " << v.ownerName << "\n";
    cout << "Vehicle Type : " << v.vehicleType << "\n";
}

void ParkingSystem::displaySlots() {
    cout << "\n--- Parking Slots ---\n";
    for (int i = 0; i < totalSlots; i++) {
        cout << "Slot " << (i + 1) << " : ";
        if (slotOccupied[i]) {
            cout << "Occupied  [" << parkingSlots[i].regNumber
                 << " | " << parkingSlots[i].ownerName
                 << " | " << parkingSlots[i].vehicleType << "]\n";
        } else {
            cout << "Empty\n";
        }
    }
}

void ParkingSystem::displayQueue() {
    if (waitingQueue.empty()) {
        cout << "\nNo vehicles waiting.\n";
        return;
    }

    cout << "\n--- Waiting Queue ---\n";

    // Copy queue so original is not modified
    queue<Vehicle> temp = waitingQueue;
    int position = 1;

    while (!temp.empty()) {
        Vehicle v = temp.front();
        temp.pop();
        cout << "Position " << position << " : "
             << v.regNumber << " - "
             << v.ownerName << " ("
             << v.vehicleType << ")\n";
        position++;
    }
}

void ParkingSystem::displayStats() {
    int occupied = 0;
    for (int i = 0; i < totalSlots; i++) {
        if (slotOccupied[i]) {
            occupied++;
        }
    }

    int available = totalSlots - occupied;
    int waiting   = (int)waitingQueue.size();
    double occupancyPercent = ((double)occupied / totalSlots) * 100.0;

    cout << "\n--- Parking Statistics ---\n";
    cout << "Total Slots      : " << totalSlots << "\n";
    cout << "Occupied Slots   : " << occupied << "\n";
    cout << "Available Slots  : " << available << "\n";
    cout << "Vehicles Waiting : " << waiting << "\n";
    cout << fixed << setprecision(1);
    cout << "Occupancy        : " << occupancyPercent << "%\n";
}
