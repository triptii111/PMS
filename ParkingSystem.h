#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class ParkingSystem {
private:
    int totalSlots;
    vector<Vehicle> parkingSlots;   // stores vehicle at each slot
    vector<bool> slotOccupied;      // true if slot is taken
    queue<Vehicle> waitingQueue;    // vehicles waiting for a free slot
    unordered_map<string, int> vehicleMap;  // reg number -> slot number (1-based)

    int findEmptySlot();
    void assignSlot(int slotIndex, Vehicle v);

public:
    ParkingSystem(int n);

    void parkVehicle();
    void removeVehicle();
    void searchVehicle();
    void displaySlots();
    void displayQueue();
    void displayStats();
};

#endif
