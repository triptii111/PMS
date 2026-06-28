# Parking Management System

A console-based Parking Management System built in C++ as a Data Structures and Algorithms (DSA) mini project.

---

## Introduction

This project simulates a real-world parking lot management system. It allows parking attendants to park vehicles, remove vehicles, search for a specific vehicle, and view the current status of all parking slots. When the parking lot is full, vehicles are placed in a waiting queue and automatically assigned a slot when one becomes available.

The project demonstrates practical use of three core data structures: **vector**, **queue**, and **unordered_map**.

---

## Objectives

- Implement a functional parking system using fundamental data structures.
- Demonstrate how different data structures solve different problems efficiently.
- Write clean, readable, and modular C++ code.
- Understand time complexity trade-offs in real-world applications.

---

## Features

1. **Park Vehicle** — Assign a slot to a vehicle or add it to the waiting queue if full.
2. **Remove Vehicle** — Free a slot and automatically assign it to the next waiting vehicle.
3. **Search Vehicle** — Find a vehicle instantly using its registration number.
4. **Display Parking Slots** — View the status (occupied/empty) of every slot.
5. **Display Waiting Queue** — See all vehicles currently waiting for a slot.
6. **Display Statistics** — View occupancy percentage and slot counts at a glance.

---

## Data Structures Used

### 1. `vector<Vehicle>` — Parking Slots

```
Purpose  : Stores all parking slot data.
Why      : Allows direct index-based access to any slot in O(1) time.
Usage    : parkingSlots[i] gives the vehicle parked at slot i+1.
```

A parallel `vector<bool> slotOccupied` tracks whether each slot is free or taken.

### 2. `queue<Vehicle>` — Waiting Queue

```
Purpose  : Stores vehicles that arrive when all slots are full.
Why      : A queue follows FIFO (First In, First Out) order.
           The vehicle that waited longest gets the next available slot.
Usage    : waitingQueue.push(v) adds a vehicle.
           waitingQueue.front() peeks at the next vehicle to be served.
           waitingQueue.pop() removes it after assigning a slot.
```

### 3. `unordered_map<string, int>` — Vehicle Lookup

```
Purpose  : Maps a registration number to its slot number.
Why      : Provides O(1) average time for search and remove operations.
           Without this, we would need to scan all slots (O(n)) every time.
Usage    : vehicleMap["DL8CAF1234"] = 5 means that vehicle is in Slot 5.
```

---

## Algorithms

### Park Vehicle
1. Check if registration number already exists in the map.
2. Scan slots to find the first empty one (`findEmptySlot`).
3. If found, store the vehicle and update the map.
4. If not found (full), push the vehicle onto the waiting queue.

### Remove Vehicle
1. Use `unordered_map` to find the slot in O(1).
2. Clear the slot from the vector and erase from map.
3. If waiting queue is not empty, pop the front vehicle and assign it the freed slot.

### Search Vehicle
1. Use `unordered_map` to look up the slot number in O(1).
2. Display vehicle details from the slot.

---

## Folder Structure

```
Parking-Management-System/
│
├── main.cpp           → Entry point, menu loop
├── ParkingSystem.h    → ParkingSystem class declaration
├── ParkingSystem.cpp  → ParkingSystem class implementation
├── Vehicle.h          → Vehicle class declaration
├── Vehicle.cpp        → Vehicle class implementation
└── README.md          → Project documentation
```

---

## How to Compile and Run

Make sure `g++` is installed.

**Compile:**
```bash
g++ *.cpp -o ParkingManagement
```

**Run on Windows:**
```bash
ParkingManagement.exe
```

**Run on Linux/Mac:**
```bash
./ParkingManagement
```

---

## Time Complexity

| Operation              | Data Structure Used | Time Complexity       |
|------------------------|---------------------|-----------------------|
| Park Vehicle           | vector + queue      | O(n) for slot search  |
| Remove Vehicle         | unordered_map       | O(1) average          |
| Search Vehicle         | unordered_map       | O(1) average          |
| Display Parking Slots  | vector              | O(n)                  |
| Display Waiting Queue  | queue               | O(n)                  |
| Display Statistics     | vector              | O(n)                  |

> Note: `n` is the total number of parking slots.

---

## Sample Input / Output

```
====================================
     PARKING MANAGEMENT SYSTEM
====================================
Enter total number of parking slots : 3

====================================
     PARKING MANAGEMENT SYSTEM
====================================
1. Park Vehicle
2. Remove Vehicle
3. Search Vehicle
4. Display Parking Slots
5. Display Waiting Queue
6. Display Statistics
7. Exit
====================================
Enter your choice : 1

Enter Registration Number     : DL8CAF1234
Enter Owner Name              : Rahul Sharma
Enter Vehicle Type (Car/Bike) : Car

Vehicle Parked Successfully.
Assigned Slot  : 1

Enter your choice : 1

Enter Registration Number     : MH12AB5678
Enter Owner Name              : Priya Singh
Enter Vehicle Type (Car/Bike) : Bike

Vehicle Parked Successfully.
Assigned Slot  : 2

Enter your choice : 4

--- Parking Slots ---
Slot 1 : Occupied  [DL8CAF1234 | Rahul Sharma | Car]
Slot 2 : Occupied  [MH12AB5678 | Priya Singh | Bike]
Slot 3 : Empty

Enter your choice : 3

Enter Registration Number : DL8CAF1234

--- Vehicle Found ---
Slot Number  : 1
Reg Number   : DL8CAF1234
Owner Name   : Rahul Sharma
Vehicle Type : Car

Enter your choice : 6

--- Parking Statistics ---
Total Slots      : 3
Occupied Slots   : 2
Available Slots  : 1
Vehicles Waiting : 0
Occupancy        : 66.7%

Enter your choice : 2

Enter Registration Number : DL8CAF1234

Vehicle Removed Successfully.
Slot 1 is now free.

Enter your choice : 7

Thank you for using Parking Management System. Goodbye!
```

---

## Class Explanations

### `Vehicle` class (`Vehicle.h` / `Vehicle.cpp`)
Stores data for a single vehicle.
- `regNumber`   — Registration plate (e.g., DL8CAF1234)
- `ownerName`   — Name of the vehicle owner
- `vehicleType` — Type of vehicle (Car or Bike)

Has two constructors: a default one (used for empty slots) and a parameterized one.

### `ParkingSystem` class (`ParkingSystem.h` / `ParkingSystem.cpp`)
Contains all the parking logic.

**Private Members:**
- `totalSlots`   — Total capacity of the parking lot
- `parkingSlots` — `vector<Vehicle>` holding vehicle at each slot
- `slotOccupied` — `vector<bool>` to track empty/occupied state
- `waitingQueue` — `queue<Vehicle>` for overflow vehicles
- `vehicleMap`   — `unordered_map<string, int>` for fast lookup

**Private Methods:**
- `findEmptySlot()` — Scans vector for first empty slot
- `assignSlot(index, vehicle)` — Puts vehicle into slot and updates map

**Public Methods:**
- `parkVehicle()`, `removeVehicle()`, `searchVehicle()`
- `displaySlots()`, `displayQueue()`, `displayStats()`

---

## Future Enhancements

- Save and load parking data from a file (file handling).
- Add entry/exit timestamps and calculate parking fees.
- Support multiple vehicle types with different slot sizes.
- Add a reservation system for pre-booking slots.
- Generate a daily parking report with total vehicles served.

---

## Author

**Name   :** Aditya Thakur  
**Course :** B.Tech Computer Science  
**Subject:** Data Structures and Algorithms  
**Project:** Mini Project — Semester III  
