#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    Car(string brand, int year) {
        this->brand = brand;
        this->year = year;
    }
};

int main() {
    Car myCar("Toyota", 2022);
    cout << "Brand: " << myCar.brand << endl;
    cout << "Year: " << myCar.year << endl;
    return 0;
}








//object creation in java



// public class Car {
//     String brand;
//     int year;

//     public Car(String brand, int year) {
//         this.brand = brand;
//         this.year = year;
//     }

//     public static void main(String[] args) {
//         Car myCar = new Car("Toyota", 2022);
//         System.out.println("Brand: " + myCar.brand);
//         System.out.println("Year: " + myCar.year);
//     }
// }
