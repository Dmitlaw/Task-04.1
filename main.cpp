#include <fstream>
#include <iostream>

class Address {
private:
    std::string city;
    std::string street;
    int house_number;
    int flat;

public:
    Address() = delete;
    Address(std::string city, std::string street, int house_number, int flat) {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->flat = flat;
    }

    std::string getCity () {
        return this->city;
    }
    std::string  getStreet() {
        return this->street;
    }
    int getHouse() {
        return this->house_number;
    }
    int getFlat() {
        return this->flat;
    }

    static void get_output_address (std::string fout, Address** arr, int n) {
        std::ofstream fout1(fout);
        if (!fout1) {
            std::cerr << "Не удалось открыть файл out.txt";
        }
        else {
            for (int i = n - 1; i >= 0; --i) {
                fout1 << arr[i]->getCity() << " " << arr[i]->getStreet() << " " << arr[i]->getHouse() << " " << arr[i]->getFlat() << "\n";
            }
        }
        fout1.close();
    }

};

int main() {

    int n = 0;
    std::string fout = "out.txt";

    std::ifstream fin("in.txt");
    if (!fin) {
        std::cerr << "Не удалось открыть файл in.txt";
        return 1;
    }
    fin >> n;

    Address** arr = new Address*[n];
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Текст в файле in.txt: " << std::endl;

    for (int i = 0; i < n; ++i) {
        std::string city;
        std::string street;
        int house_number;
        int flat;

        fin >> city >> street >> house_number >> flat;
        arr[i] = new Address(city, street, house_number, flat);

        std::cout << arr[i]->getCity();
        std::cout << " ";
        std::cout << arr[i]->getStreet();
        std::cout << " ";
        std::cout << arr[i]->getHouse();
        std::cout << " ";
        std::cout << arr[i]->getFlat();
        std::cout << std::endl;
    }
    fin.close();

    Address::get_output_address(fout, arr, n);

    for (int i = 0; i < n; ++i) {
    delete arr[i];
    }
    delete[] arr;

    std::ifstream fin_out("out.txt");
    std::cout << std::endl;
    std::cout << "Текст в файле out.txt: " << std::endl;
    std::cout << fin_out.rdbuf();
    fin_out.close();

    return EXIT_SUCCESS;
}
