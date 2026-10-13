# Vehicle Registry System in C++

## Project Overview

The **Vehicle Registry System** is a menu-driven C++ console application used to register, display, and search for vehicles by their unique Vehicle ID.

The project demonstrates object-oriented programming (OOP) concepts such as classes, inheritance, constructors, destructors, static data members, and member functions.

## Features

- Add a new vehicle to the registry.
- View all registered vehicles.
- Search for a vehicle using its Vehicle ID.
- Prevent duplicate Vehicle IDs.
- Store details for different vehicle types.
- Track the total number of `Vehicle` objects using a static member.
- Display vehicle-specific information such as fuel type, battery capacity, flight range, and top speed.
- Use a menu-driven interface with `if-else` statements.

## Supported Vehicle Types

1. Car
2. Electric Car
3. Aircraft
4. Flying Car
5. Sports Car
6. Sedan
7. SUV

## Vehicle Information

### Common Details

Each vehicle stores the following information:

- Vehicle ID
- Manufacturer
- Model
- Year

📂 Project Structure
cpp vehicle registry/
├── main.cpp
├── output.png
└── README.md

### Additional Details

Depending on the selected vehicle type, the program can also store:

- **Fuel Type:** For cars and other non-aircraft types in the program.
- **Battery Capacity:** For Electric Cars and Sports Cars.
- **Flight Range:** For Aircraft and Flying Cars.
- **Top Speed:** For Sports Cars.

## Object-Oriented Programming Concepts

### 1. Classes and Objects

The project uses classes to organize vehicle information and registry operations.

### 2. Encapsulation

The common vehicle data members are declared `private`. Public member functions provide access to and update these details.

### 3. Inheritance

The project uses inheritance to represent specialized vehicle types.

- `Car` inherits from `Vehicle`.
- `ElectricCar` inherits from `Car`.
- `Aircraft` inherits from `Vehicle`.
- `FlyingCar` inherits from `Car`.
- `SportsCar` inherits from `ElectricCar`.
- `Sedan` inherits from `Car`.
- `SUV` inherits from `Car`.

### 4. Constructors

The `Vehicle` class has a default constructor and a parameterized constructor. The derived classes use constructors to initialize their base classes and additional data members.

### 5. Destructor

The `Vehicle` destructor decreases the static vehicle counter when a `Vehicle` object is destroyed.

### 6. Static Data Member

`totalVehicles` is a static data member shared by all `Vehicle` objects. The `getTotalVehicles()` function returns its value.

### 7. Member Functions

Functions such as `setVehicleID()`, `setManufacturer()`, `setModel()`, `setYear()`, and `display()` are used to update and display vehicle details.

## Classes Used

| Class | Purpose |
|---|---|
| `Vehicle` | Stores common vehicle details and provides common methods. |
| `Car` | Adds fuel type information. |
| `ElectricCar` | Adds battery capacity information. |
| `Aircraft` | Adds flight range information. |
| `FlyingCar` | Adds flying range information. |
| `SportsCar` | Adds top speed information. |
| `Sedan` | Represents a sedan vehicle type. |
| `SUV` | Represents an SUV vehicle type. |
| `VehicleRegistry` | Adds, displays, and searches registered vehicles. |

## Menu Options

When the program runs, it displays the following menu:

```text
===== VEHICLE REGISTRY SYSTEM =====
1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Exit
Enter choice:
```

### Option 1: Add Vehicle

Choose a vehicle type and enter its details. The program checks whether the Vehicle ID already exists before adding the record.

### Option 2: View All Vehicles

Displays the details of all vehicles registered during the current program session.

### Option 3: Search Vehicle by ID

Enter a Vehicle ID to check whether the vehicle exists and display its stored details.

### Option 4: Exit

Displays a thank-you message and ends the program.

## Requirements

- A C++ compiler, such as GCC or MinGW.
- A code editor or IDE, such as Visual Studio Code, Code::Blocks, or Visual Studio.
- Basic knowledge of C++.

## How to Compile and Run

Save the source code in a file named `main.cpp`.

### Using GCC

Compile the program:

```bash
g++ main.cpp -o vehicle_registry
```

Run on Windows:

```bash
vehicle_registry.exe
```

Run on Linux or macOS:

```bash
./vehicle_registry
```

## Example Usage

```text
===== VEHICLE REGISTRY SYSTEM =====
1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Exit
Enter choice: 1

1. Car
2. Electric Car
3. Aircraft
4. Flying Car
5. Sports Car
6. Sedan
7. SUV
Enter vehicle type: 1
Enter Vehicle ID: 101
Enter Manufacturer: Toyota
Enter Model: Corolla
Enter Year: 2024
Enter Fuel Type: Petrol
Vehicle added successfully!
```

*This is an illustrative example. The actual output depends on the details entered by the user.*

## Data Storage

The registry stores records in fixed-size arrays and can hold up to 100 entries. The data remains available only while the program is running; it is not saved to a file or database.

## Limitations

- The registry has a maximum capacity of 100 entries.
- Records are not permanently saved.
- The program uses separate arrays for vehicle details and type-specific information.
- Input validation for fields such as year, battery capacity, range, and speed is limited.

## Future Improvements

- Add file handling to save and load vehicle records.
- Add update and delete options.
- Improve input validation.
- Display the total number of registered vehicles in the menu.
- Store vehicle-specific data more directly in the corresponding derived classes.

## Conclusion

The Vehicle Registry System is a beginner-friendly C++ project that demonstrates classes, inheritance, constructors, destructors, static members, encapsulation, and menu-driven programming. It provides basic functionality for adding, viewing, and searching vehicle records.

---

**Language:** C++  
**Project Type:** Console Application  
**Main Concepts:** Object-Oriented Programming (OOP)
