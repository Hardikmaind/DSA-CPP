#include <iostream>
using namespace std;

// In this example, Car* myCar = new Car("Toyota", 2022); dynamically allocates memory for a Car object and initializes it with the specified values. We use the -> operator to access member functions of the dynamically allocated object.


class Car {
public:
    string brand;
    int year;

    Car(string brand, int year) {
        this->brand = brand;
        this->year = year;
    }

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Car* myCar = new Car("Toyota", 2022);           //now when using the new keyword we get the return type as a pointer to the object
    myCar->displayInfo();  // Accessing member function using ->
    delete myCar;  // Don't forget to free the memory when done
    return 0;
}

// However, it's important to note that when you create an object dynamically using new, you are responsible for managing the memory allocated for that object. This includes explicitly deleting the object using delete when you no longer need it to avoid memory leaks.