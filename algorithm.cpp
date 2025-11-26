#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class Car {
private:
    string id;
    string brand;
    string color;
    string countryOfManufacture;
    int yearOfManufacture;
    int numOfCarSold;
    double price;

    string generateRandomId(const string& brand, vector <Car> cars) {
        vector <string> carID;
        for(int i=0; i<cars.size(); i++){
            carID.push_back(cars.at(i).id);
        }
        bool check = true;
        // unique car id
        string id;
        string prefix = brand.substr(0, 3); // First three letters of the brand
        while(check){
            int randomNumber = rand() % 900000 + 100000; // Random 6-digit number
            id = prefix + to_string(randomNumber);
            check = false;
            for(int i=0; i<carID.size(); i++){
                if(id == carID.at(i))
                    check = true;
            }
        }
        return id;
    }

public:
    // Constructor
    Car() = default;

    Car(string BRAND, string COLOUR, string COUNTRYOFMANUFACTURE, int YEAR, int NUM, double PRICE) {
        brand = BRAND;
        color = COLOUR;
        countryOfManufacture = COUNTRYOFMANUFACTURE;
        yearOfManufacture = YEAR;
        numOfCarSold = NUM;
        price = PRICE;
    }

    void purchaseCar(){
        numOfCarSold++;
    }

    // Getters
    string getId() const {
        return id;
    }

    string getBrand() const {
        return brand;
    }

    string getColor() const {
        return color;
    }

    string getCountryOfManufacture() const {
        return countryOfManufacture;
    }

    int getYearOfManufacture() const {
        return yearOfManufacture;
    }

    int getNumOfCarSold() const {
        return numOfCarSold;
    }

    double getPrice() const {
        return price;
    }

    // Setters
    void setId(vector <Car> cars) {
        id = generateRandomId(brand, cars);
    }

    void setBrand(const string& brand, vector <Car> cars) {
        this->brand = brand;
        setId(cars); // Update ID when brand is changed
    }

    void setColor(string x) {
        color = x;
    }

    void setCountryOfManufacture(string x) {
        countryOfManufacture = x;
    }

    void setYearOfManufacture(int x) {
        yearOfManufacture = x;
    }

    void setPrice(double x) {
        price = x;
    }

    void setNumOfCarSold(int x) {
        numOfCarSold = x;
    }

    // Method to display car details
    void displayCarDetails() const {
        cout << "ID: " << id << endl;
        cout << "Brand: " << brand << endl;
        cout << "Color: " << color << endl;
        cout << "Country of Manufacture: " << countryOfManufacture << endl;
        cout << "Year of Manufacture: " << yearOfManufacture << endl;
        cout << "Number of car sold: " <<numOfCarSold<<endl;
        cout << "Price: " << price << endl;
    }
};

int welcome_page() {
    int choice;
    cout << endl;
    cout << "==================================" << endl;
    cout << " Welcome to Universal Transport! " << endl;
    cout << "==================================" << endl << endl;
    cout << "Discover the Best Way to Travel!" << endl;
    cout << "Welcome to Universal Transport, your ultimate destination for purchasing quality vehicles. Whether you're looking for a sleek sedan, a robust SUV for family adventures, or a powerful truck for work, we have the perfect vehicle to match your needs. Discover our diverse selection of cars, all meticulously inspected and ready to drive home today." << endl << endl;
    cout << "Enter your choice: " << endl;
    cout << " 1. User" << endl;
    cout << " 2. Admin" << endl;
    cout << " 3. Exit" << endl;
    cout << " > ";
    cin >> choice;

    return choice;
}

vector<Car> cars = {
    // Car(brand, colour, country, year, num of car sold, price)
    Car("Toyota", "Red", "Japan", 2020, 10, 25000),
    Car("Honda", "Blue", "Japan", 2019, 5, 30000),
    Car("Ford", "Silver", "USA", 2021, 8, 28000),
    Car("Chevrolet", "Black", "USA", 2022, 12, 32000),
    Car("BMW", "White", "Germany", 2018, 6, 40000),
    Car("Toyota", "Black", "Japan", 2018, 15, 27000),
    Car("Honda", "Green", "Japan", 2020, 7, 31000),
    Car("Ford", "Blue", "USA", 2019, 10, 29000),
    Car("Chevrolet", "Red", "USA", 2021, 9, 33000),
    Car("BMW", "Silver", "Germany", 2020, 4, 42000),
    Car("Toyota", "Yellow", "Japan", 2017, 13, 26000),
    Car("Honda", "Gray", "Japan", 2018, 8, 29000),
    Car("Ford", "Green", "USA", 2020, 11, 30000),
    Car("Chevrolet", "Blue", "USA", 2019, 14, 31000),
    Car("BMW", "Black", "Germany", 2021, 5, 44000),
    Car("Toyota", "Orange", "Japan", 2019, 12, 28000),
    Car("Honda", "White", "Japan", 2021, 6, 32000),
    Car("Ford", "Red", "USA", 2018, 9, 27000),
    Car("Chevrolet", "Silver", "USA", 2020, 10, 34000),
    Car("BMW", "Blue", "Germany", 2017, 7, 41000)
};

void sortCarsByBestSellingBrand() {
    map<string, int> BRAND;

    // Calculate total sales for each brand
    for (int i = 0; i < cars.size(); i++) {
        BRAND[cars[i].getBrand()] += cars[i].getNumOfCarSold();
    }

    cout << "Number of brands within the database: " << BRAND.size() << endl;
    cout << endl;

    // Bubble sort the cars by best-selling brand (total cars sold by the brand)
    int n = cars.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (BRAND[cars[j].getBrand()] < BRAND[cars[j + 1].getBrand()]) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }
    // Print the sorted list of cars by best-selling brand
    cout << "Sorted list of cars by best-selling brand:" << endl;
    for (int i = 0; i < cars.size(); ++i) {
        cars[i].displayCarDetails();
        cout << "----------------------------------------" << endl;
    }
}


void delay(int seconds){
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time);
}

struct Person
{
    string id;
    string password;
};

struct Bill
{
    string billNum;
    int year;
    int month;
    int day;
    string cusName;
    string cusID;
    string carID;
    string carBrand;
    string carColour;
    string carCountry;
    int carYear;
    double carPrice;
    double totalPrice;

    double getDiscount(){
        double discount = carPrice*0.05;
        return discount;
    }
    string getBillDate(){
        return (day < 10 ? "0" : "") + to_string(day) + "-" + (month < 10 ? "0" : "") + to_string(month) + "-" + to_string(year);
    }
};

vector <Bill> Bills = {
    {"B00001", 2020, 3, 5, "Ali", "USER001", "Toy100041", "Toyota", "Red", "Japan", 2020, 25000, 23750},
    {"B00002", 2018, 10, 8, "Ali", "USER001", "Hon118467", "Honda", "Blue", "Japan", 2019, 30000, 28500},
    {"B00003", 2017, 5, 18, "Abu", "USER002", "For106334", "Ford", "Silver", "USA", 2021, 28000, 26600},
    {"B00004", 2023, 4, 10, "Abu", "USER002", "Che126500", "Chevrolet", "Black", "USA", 2022, 32000, 30400},
    {"B00005", 2024, 7, 20, "Amoi", "USER003", "BMW119169", "BMW", "White", "Germany", 2018, 40000, 38000},
    {"B00006", 2024, 9, 23, "Amoi", "USER003", "Toy115724", "Toyota", "Black", "Japan", 2018, 27000, 25650},
    {"B00007", 2022, 6, 25, "Ben", "USER004", "Hon111478", "Honda", "Green", "Japan", 2020, 31000, 29450},
    {"B00008", 2016, 1, 19, "Ben", "USER004", "For129358", "Ford", "Blue", "USA", 2019, 29000, 27550},
    {"B00009", 2019, 11, 16, "Chick", "USER005", "Che126962", "Chevrolet", "Red", "USA", 2021, 33000, 31350},
    {"B00010", 2023, 2, 14, "Chick", "USER005", "BMW124464", "BMW", "Silver", "Germany", 2020, 42000, 39900},
    {"B00011", 2024, 6, 24, "Ali", "USER001", "Toy105705", "Toyota", "Yellow", "Japan", 2017, 26000, 24700},
    {"B00012", 2020, 4, 15, "Ali", "USER001", "Hon128145", "Honda", "Gray", "Japan", 2018, 29000, 27550},
    {"B00013", 2019, 5, 16, "Abu", "USER002", "For123281", "Ford", "Green", "USA", 2020, 30000, 28500},
    {"B00014", 2018, 7, 4, "Abu", "USER002", "Che116827", "Chevrolet", "Blue", "USA", 2019, 31000, 29450},
    {"B00015", 2017, 3, 17, "Amoi", "USER003", "BMW109961", "BMW", "Black", "Germany", 2021, 44000, 41800},
    {"B00016", 2016, 7, 30, "Amoi", "USER003", "Toy100491", "Toyota", "Orange", "Japan", 2019, 28000, 26600},
    {"B00017", 2020, 8, 31, "Ben", "USER004", "Hon102995", "Honda", "White", "Japan", 2021, 32000, 30400},
    {"B00018", 2021, 12, 25, "Ben", "USER004", "For111942", "Ford", "Red", "USA", 2018, 27000, 25650},
    {"B00019", 2023, 12, 5, "Chick", "USER005", "Che104827", "Chevrolet", "Silver", "USA", 2020, 34000, 32300},
    {"B00020", 2024, 11, 26, "Chick", "USER005", "BMW105436", "BMW", "Blue", "Germany", 2017, 41000, 38950},
    {"B00021", 2024, 4, 28, "Ali", "USER001", "Toy101041", "Toyota", "Red", "Japan", 2019, 26000, 24700},
    {"B00022", 2020, 3, 7, "Ali", "USER001", "Hon118447", "Honda", "Blue", "Japan", 2018, 30000, 28500},
    {"B00023", 2021, 5, 20, "Abu", "USER002", "For104334", "Ford", "Silver", "USA", 2020, 28000, 26600},
    {"B00024", 2022, 8, 15, "Abu", "USER002", "Che136500", "Chevrolet", "Black", "USA", 2021, 32000, 30400},
    {"B00025", 2019, 9, 19, "Amoi", "USER003", "BMW119979", "BMW", "White", "Germany", 2017, 40000, 38000},
    {"B00026", 2018, 10, 15, "Amoi", "USER003", "Toy114724", "Toyota", "Black", "Japan", 2019, 27000, 25650},
    {"B00027", 2017, 6, 30, "Ben", "USER004", "Hon116478", "Honda", "Green", "Japan", 2018, 31000, 29450},
    {"B00028", 2016, 7, 18, "Ben", "USER004", "For121358", "Ford", "Blue", "USA", 2020, 29000, 27550},
    {"B00029", 2024, 9, 10, "Chick", "USER005", "Che126962", "Chevrolet", "Red", "USA", 2021, 33000, 31350},
    {"B00030", 2023, 12, 15, "Chick", "USER005", "BMW124464", "BMW", "Silver", "Germany", 2020, 42000, 39900}
};

Bill createBill(vector <Bill> &oriBill, string name, Person user, Car cars)
{
    vector <string> BillNum;
    for(int i=0; i<oriBill.size(); i++){
        BillNum.push_back(oriBill.at(i).billNum);
    }
    Bill bill;
    bool check = true;
    // unique purchase order number
    string BILLNUM;
    while(check){
        BILLNUM = "B";
        for (int i=0; i<5; i++)
        {
            BILLNUM += to_string(rand()%5);
        }
        check = false;
        for(int i=0; i<BillNum.size(); i++){
            if(BILLNUM == BillNum.at(i))
                check = true;
        }
    }
    bill.billNum = BILLNUM;
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    bill.year = currentTime->tm_year+1900;
    bill.month = currentTime->tm_mon+1;
    bill.day = currentTime->tm_mday;
    bill.cusName = name;
    bill.cusID = user.id;
    bill.carID = cars.getId();
    bill.carBrand = cars.getBrand();
    bill.carColour = cars.getColor();
    bill.carCountry = cars.getCountryOfManufacture();
    bill.carYear = cars.getYearOfManufacture();
    bill.carPrice = cars.getPrice();
    double discount = bill.getDiscount();
    bill.totalPrice = bill.carPrice - discount; // minus discount 5%
    oriBill.push_back(bill);

    return bill;
}

void printBill(Bill bill) // generate and print bill
{
    //Bill bill;

    cout << "\n\n*********************************************************\n";
    cout << "                  Universal Transport!                   \n";
    cout << "   Level 3, Block B, Universal Road, Transport Garden,   \n";
    cout << "   Near the Big Red Tree, Opposite the Invisible Park,   \n";
    cout << "   Postcode 00000, Planet Universal, Milky Way Galaxy.   \n";
    cout << "                 Tel No. 0112358132134                   \n";
    cout << "*********************************************************\n";
    cout << "\n                        Bill                           \n";
    cout << left << bill.billNum << setw(40) << "" << bill.getBillDate() << endl;
    cout << "---------------------------------------------------------\n";

    cout << left << setw(29) << "Client Name: " << bill.cusName << endl;
    cout << left << setw(29) << "Client ID: " << bill.cusID << endl;

    cout << left << setw(30) << "\nCar ID: " << bill.carID << endl;
    cout << left << setw(29) << "Car Brand: " << bill.carBrand << endl;
    cout << left << setw(29) << "Car Colour: " << bill.carColour << endl;
    cout << left << setw(29) << "Country of Manufacture: " << bill.carCountry << endl;
    cout << left << setw(29) << "Year of Manufacture: " << bill.carYear << endl;

    cout << "---------------------------------------------------------\n";

    cout << left << setw(25) << "ITEM" << setw(12) << "Quantities" << setw(10) << "" << "PRICE" << endl;
    cout << "---------------------------------------------------------\n";
    cout << left << setw(25) << bill.carID << setw(12) << "1" << setw(10) << "" << "$ " << bill.carPrice << endl;
    cout << left << setw(25) << "Member discount (5%)" << setw(22) << "" << "$ " << bill.carPrice*0.05 << endl;

    cout << "---------------------------------------------------------\n";
    cout << left << setw(25) << "Total " << setw(22) << "" << "$ " << fixed << setprecision(2) << bill.totalPrice << endl;
    cout << "---------------------------------------------------------\n";

    cout << "\nThank you for your trust and support." << endl;
    cout << "We wish you a pleasant journey!" << endl;
    cout << "*********************************************************\n\n";
}

void custonMergeSort(vector<Car>& cars, int left, int right, bool (*compare)(const Car&, const Car&)) {
    if (left >= right) return;

    int middle = left + (right - left) / 2;

    custonMergeSort(cars, left, middle, compare);
    custonMergeSort(cars, middle + 1, right, compare);

    vector<Car> merged(right - left + 1);
    int leftIndex = left, rightIndex = middle + 1, mergeIndex = 0;

    while (leftIndex <= middle && rightIndex <= right) {
        if (compare(cars[leftIndex], cars[rightIndex])) {
            merged[mergeIndex++] = cars[leftIndex++];
        } else {
            merged[mergeIndex++] = cars[rightIndex++];
        }
    }

    while (leftIndex <= middle) {
        merged[mergeIndex++] = cars[leftIndex++];
    }

    while (rightIndex <= right) {
        merged[mergeIndex++] = cars[rightIndex++];
    }

    for (int i = left; i <= right; ++i) {
        cars[i] = merged[i - left];
    }
}

bool compareById(const Car& car1, const Car& car2) {
    return car1.getId() < car2.getId();
}

bool compareByBrand(const Car& car1, const Car& car2) {
    return car1.getBrand() < car2.getBrand();
}

bool compareByPrice(const Car& car1, const Car& car2) {
    return car1.getPrice() < car2.getPrice();
}

int quickSortPartitionByPrice(vector <Bill> &bills, int low, int high)
{
  //choose the pivot
  double pivot=bills[high].carPrice;
  int i=(low-1);

  for(int j=low;j<=high-1;j++)
  {
    if(bills[j].carPrice<pivot)
    {
      i++;
      swap(bills[i].carPrice,bills[j].carPrice);
    }
  }
  swap(bills[i+1].carPrice,bills[high].carPrice);
  return (i+1);
}

void quickSortByPrice(vector <Bill> &bills, int low, int high)
{
  if(low<high)
  {
    int pivot=quickSortPartitionByPrice(bills,low,high);

    quickSortByPrice(bills,low,pivot-1);
    quickSortByPrice(bills,pivot+1,high);
  }
}

int quickSortPartitionByYear(vector <Bill> &bills, int low, int high)
{
  //choose the pivot
  double pivot=bills[high].year;
  int i=(low-1);

  for(int j=low;j<=high-1;j++)
  {
    if(bills[j].year<pivot)
    {
      i++;
      swap(bills[i].year,bills[j].year);
    }
  }
  swap(bills[i+1].year,bills[high].year);
  return (i+1);
}

void quickSortByYear(vector <Bill> &bills, int low, int high)
{
  if(low<high)
  {
    int pivot=quickSortPartitionByYear(bills,low,high);

    quickSortByYear(bills,low,pivot-1);
    quickSortByYear(bills,pivot+1,high);
  }
}

vector <Bill> binarySearchByYear(vector <Bill> &bills, int low, int high, int year)
{
    vector <Bill> YearBill;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if (bills[mid].year == year) {
            YearBill.push_back(bills[mid]);

            // see if left have more match bill
            int left = mid - 1;
            while (left >= low && bills[left].year == year) {
                YearBill.push_back(bills[left]);
                left--;
                if(bills[left].year < year)
                    break;
            }

            // see if right have more match bill
            int right = mid + 1;
            while (right <= high && bills[right].year == year) {
                YearBill.push_back(bills[right]);
                right++;
                if(bills[left].year > year)
                    break;
            }

            break;
        }
        if(bills[mid].year < year){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return YearBill;
}

void generateAnnualReport(vector <Bill> &bills, int year)
{
    double totalPrice = 0.0;
    // sort the bill by price
    quickSortByPrice(bills, 0, bills.size()-1);
    cout << "\n\n**************************************************************************************************\n";
    cout << "                                       Universal Transport!                                       \n";
    cout << "                       Level 3, Block B, Universal Road, Transport Garden,                        \n";
    cout << "                       Near the Big Red Tree, Opposite the Invisible Park,                        \n";
    cout << "                       Postcode 00000, Planet Universal, Milky Way Galaxy.                        \n";
    cout << "                                       Tel No. 0112358132134                                      \n";
    cout << "**************************************************************************************************\n";
    cout << "\n                                        " << year << " Annual Report                            \n";
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << left << setw(5) << "No." << setw(12) << "DATE" << setw(10) << "CARID" << setw(12) << "BRAND" << setw(10) << "COLOUR" << setw(20)
         << "CUSTOMER NAME" << setw(10) << "PRICE" << setw(10) << "DISCOUNT" << setw(10) << "SUBTOTAL" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < bills.size(); i++) {
        cout << left << setw(5) << (i + 1) << setw(12) << bills[i].getBillDate() << setw(10) << bills[i].carID << setw(12) << bills[i].carBrand
             << setw(10) << bills[i].carColour << setw(20) << bills[i].cusName << setw(10) << fixed << setprecision(2) << bills[i].carPrice
             << setw(10) << fixed << setprecision(2) << bills[i].getDiscount() << setw(10) << fixed << setprecision(2) << bills[i].totalPrice
             << endl << endl << endl;
        totalPrice += bills[i].totalPrice;
    }
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << right << setw(89) << "Total Price: " << fixed << setprecision(2) << totalPrice << endl;

    cout << "**************************************************************************************************\n\n";
}


void System() {
    int choice;
    string username;
    string password;
    bool login = false;
    map<string, Person> user;
    user["Ali"] = {"USER001", "ali123"};
    user["Abu"] = {"USER002", "abu123"};
    user["Amoi"] = {"USER003", "amoi123"};
    user["Ben"] = {"USER004", "ben123"};
    user["Chick"] = {"USER005", "chick123"};

    map<string, string> admin;
    admin["Siti"] = "siti123";
    admin["Fatimah"] = "fatimah123";
    admin["Dalia"] = "dalia123";

    choice = welcome_page();
    map<string, int> BRAND;

    // Calculate total sales for each brand
    for (int i = 0; i < cars.size(); i++) {
        BRAND[cars[i].getBrand()] += cars[i].getNumOfCarSold();
    }

    if (choice == 1) {
        while(!login){
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            auto it = user.find(username);
            if (it != user.end() && it->second.password == password) {
                cout << "Login successful!\n";
                login = true;
            } else {
                cout << "Invalid username or password. Please enter again\n\n";
            }
        }

        if (login) {
            while (true) {
                cout << endl
                     << "Main Menu" << endl
                     << " 1. Display all cars" << endl
                     << " 2. Sort cars by brand" << endl
                     << " 3. Sort cars by price" << endl
                     << " 4. Sort cars by ID" << endl
                     << " 5. Search car by ID" << endl
                     << " 6. Sort car by best-selling brand" << endl
                     << " 7. Best-selling brand's best selling car "<< endl
                     << " 8. Purchase car" << endl
                     << " 9. Exit" << endl
                     << " > ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        for (int i = 0; i < cars.size(); i++) {
                            cout << "----------------------------------------" << endl;
                            cars.at(i).displayCarDetails();
                            cout << "----------------------------------------" << endl;
                        }
                        break;
                    }
                    case 2: {
                        // Sort cars by brand
                        vector <Car> sortCarBrand = cars;
                        custonMergeSort(sortCarBrand, 0, cars.size() - 1, compareByBrand);
                        cout << "\nSort cars by brand:" << endl;
                        for (const auto& car : sortCarBrand) {
                            cout << "----------------------------------------" << endl;
                            car.displayCarDetails();
                            cout << "----------------------------------------" << endl;
                        }
                        break;
                    }
                    case 3: {
                        // Sort cars by price
                        vector <Car> sortCarPrice = cars;
                        custonMergeSort(sortCarPrice, 0, cars.size() - 1, compareByPrice);
                        cout << "\nSort cars by price:" << endl;
                        for (const auto& car : sortCarPrice) {
                            cout << "----------------------------------------" << endl;
                            car.displayCarDetails();
                            cout << "----------------------------------------" << endl;
                        }
                        break;
                    }
                    case 4: {
                        // Sort cars by id
                        vector <Car> sortCarID = cars;
                        custonMergeSort(sortCarID, 0, cars.size() - 1, compareById);
                        cout << "\nSort cars by ID:" << endl;
                        for (const auto& car : sortCarID) {
                            cout << "----------------------------------------" << endl;
                            car.displayCarDetails();
                            cout << "----------------------------------------" << endl;
                        }
                        break;
                    }
                    case 5: {
                        // Search car by ID
                        string carid;
                        bool flag = false;
                        cout << "Please enter the Car ID that you would like to search: ";
                        cin >> carid;
                        // linear search
                        for (int i = 0; i < cars.size(); i++) {
                            if (cars.at(i).getId() == carid) {
                                flag = true;
                                cout << "Your search is successful, below are the details:" << endl;
                                cars.at(i).displayCarDetails();
                                break;
                            }
                        }
                        if (!flag) {
                            cout << "Sorry, your search is unsuccessful. No car found with the given ID." << endl;
                        }
                        break;
                    }

                    case 6: {
                        sortCarsByBestSellingBrand();
                        break;
                    }

                    case 7: {
                        sortCarsByBestSellingBrand();
                        // Print the best-selling brand (the first brand after sorting)
                        cout << "Best-selling brand:" << endl;
                        string bestSellingBrand = cars[0].getBrand();
                        cout << "Brand: " << bestSellingBrand << ", Total Cars Sold: " << BRAND[bestSellingBrand] << endl;
                        cout << endl;

                        // Print the brands and their total cars sold
                        cout << "Brands and their total cars sold:" << endl;
                        for (auto it = BRAND.begin(); it != BRAND.end(); ++it) {
                            cout << "Brand: " << it->first << ", Car Sold: " << it->second << endl;
                        }
                        cout << endl;

                        // Find and print all cars from the best-selling brand
                        cout << "Best-selling cars from the top brand (" << bestSellingBrand << "):" << endl;
                        vector<Car> bestSellingBrandCars;
                        for (int i = 0; i < cars.size(); ++i) {
                            if (cars[i].getBrand() == bestSellingBrand) {
                                bestSellingBrandCars.push_back(cars[i]);
                            }
                        }

                        // Bubble sort the cars within the best-selling brand by the number of cars sold (ascending order)
                        int m = bestSellingBrandCars.size();
                        for (int i = 0; i < m - 1; ++i) {
                            for (int j = 0; j < m - i - 1; ++j) {
                                if (bestSellingBrandCars[j].getNumOfCarSold() > bestSellingBrandCars[j + 1].getNumOfCarSold()) {
                                    swap(bestSellingBrandCars[j], bestSellingBrandCars[j + 1]);
                                }
                            }
                        }

                        // Print the sorted list of cars within the best-selling brand
                        for (int i = 0; i < bestSellingBrandCars.size(); ++i) {
                            bestSellingBrandCars[i].displayCarDetails();
                            cout << "----------------------------------------" << endl;
                        }

                        // Perform binary search to find the best-selling car (largest number of cars sold)
                        int left = 0;
                        int right = bestSellingBrandCars.size() - 1;
                        int bestSellingCarIndex = -1;
                        int maxCarSold = bestSellingBrandCars[right].getNumOfCarSold(); // Max is at the rightmost after sorting
                        while (left <= right) {
                            int mid = left + (right - left) / 2;
                            if (bestSellingBrandCars[mid].getNumOfCarSold() == maxCarSold) {
                                bestSellingCarIndex = mid;
                                break;
                            } else if (bestSellingBrandCars[mid].getNumOfCarSold() < maxCarSold) {
                                left = mid + 1;
                            } else {
                                right = mid - 1;
                            }
                        }

                        // Print the best-selling car
                        if (bestSellingCarIndex != -1) {
                            cout << "Best-selling car from the top brand (" << bestSellingBrand << "):" << endl;
                            bestSellingBrandCars[bestSellingCarIndex].displayCarDetails();
                            cout << "----------------------------------------" << endl;
                        } else {
                            cout << "Best-selling car not found!" << endl;
                        }

                        break;
                    }

                    case 8:{
                        // purchase car
                        string carid;
                        bool flag = false;
                        while(!flag){
                            cout << "Please enter the car ID you want to purchase: ";
                            cin >> carid;
                            for (int i = 0; i < cars.size(); i++) {
                                if (cars.at(i).getId() == carid) {
                                    flag = true;
                                    cout << "Below are the details:" << endl;
                                    cars.at(i).displayCarDetails();
                                    cout << endl;
                                    cout << "=======================================" << endl;
                                    cout << "             Settlement               " << endl;
                                    cout << "\nCar price: $ " << cars.at(i).getPrice() << endl;
                                    cout << "Member discount (5%): $ " << cars.at(i).getPrice()*0.05 << endl;
                                    cout << "---------------------------------------" << endl;
                                    cout << "Total price: $ " << cars.at(i).getPrice()-cars.at(i).getPrice()*0.05 << endl;
                                    cout << "---------------------------------------" << endl;

                                    char confirmPayment;
                                    cout << "\nDo you confirm the payment? [Y/N]: ";
                                    cin >> confirmPayment;
                                    if (confirmPayment == 'Y' || confirmPayment == 'y') {
                                        cars.at(i).purchaseCar();
                                        delay(1);
                                        cout << "Payment successful. Car sold." << endl;
                                        delay(1);

                                        //create and print bill
                                        Bill bill;
                                        bill = createBill(Bills, username, user[username], cars.at(i));
                                        printBill(bill);
                                        delay(3);
                                    break;
                                    }
                                }
                            }
                            if(!flag){
                                cout << "Invalid car ID. Please enter again." << endl;
                            }
                        }
                        System();
                        break;
                    }

                    case 9: {
                        System(); // Exit to main menu
                        break;
                    }
                    default: {
                        cout << "Invalid choice, please try again." << endl;
                    }
                }
            }
        }
    } else if (choice == 2) {
        int option;

        while(!login){
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            auto it = admin.find(username);
            if (it != admin.end() && it->second == password) {
                cout << "Login successful!\n\n";
                login = true;
            } else {
                cout << "Invalid username or password. Please enter again\n\n";
            }
        }
        while (true) {
            cout << "Welcome Admin!" << endl;
            cout << " 1. Add New Car" << endl
                 << " 2. Modify Car Data" << endl
                 << " 3. Display All Cars" << endl
                 << " 4. Remove Car Record" << endl
                 << " 5. Search bill by customer ID" << endl
                 << " 6. Search bill by bill year" << endl
                 << " 7. Check Annual Report" << endl
                 << " 8. Exit\n > ";
            cin >> option;
            switch (option) {
                case 1: {
                    // Add New Car
                    string brand, color, countryOfManufacture;
                    int year, num;
                    double price;

                    cout << "Enter car brand: ";
                    cin >> brand;
                    cout << "Enter car color: ";
                    cin >> color;
                    cout << "Enter country of manufacture: ";
                    cin >> countryOfManufacture;
                    cout << "Enter year of manufacture: ";
                    cin >> year;
                    cout << "Enter number of cars sold: ";
                    cin >> num;
                    cout << "Enter price: ";
                    cin >> price;

                    Car newCar(brand, color, countryOfManufacture, year, num, price);
                    cars.push_back(newCar);

                    cout << "New car added successfully!" << endl;
                    break;
                }
                case 2: {
                    // Modify Car Data
                    string carid;
                    bool flag = false;
                    cout << "Please enter the Car ID that you would like to modify: ";
                    cin >> carid;

                    for (int i = 0; i < cars.size(); i++) {
                        if (cars.at(i).getId() == carid) {
                            flag = true;
                            cout << "Car found. Enter new details:" << endl;

                            string brand, color, countryOfManufacture;
                            int year, num;
                            double price;

                            cout << "Enter new car brand (current: " << cars.at(i).getBrand() << "): ";
                            cin >> brand;
                            cout << "Enter new car color (current: " << cars.at(i).getColor() << "): ";
                            cin >> color;
                            cout << "Enter new country of manufacture (current: " << cars.at(i).getCountryOfManufacture() << "): ";
                            cin >> countryOfManufacture;
                            cout << "Enter new year of manufacture (current: " << cars.at(i).getYearOfManufacture() << "): ";
                            cin >> year;
                            cout << "Enter new number of cars sold (current: " << cars.at(i).getNumOfCarSold() << "): ";
                            cin >> num;
                            cout << "Enter new price (current: $" << cars.at(i).getPrice() << "): ";
                            cin >> price;

                            cars.at(i).setBrand(brand, cars);
                            cars.at(i).setColor(color);
                            cars.at(i).setCountryOfManufacture(countryOfManufacture);
                            cars.at(i).setYearOfManufacture(year);
                            cars.at(i).setNumOfCarSold(num);
                            cars.at(i).setPrice(price);

                            cout << "Car details updated successfully!" << endl;
                            break;
                        }
                    }

                    if (!flag) {
                        cout << "Sorry, no car found with the given ID." << endl;
                    }
                    break;
                }
                case 3: {
                    // Display All Cars
                    for (int i = 0; i < cars.size(); i++) {
                        cout << "----------------------------------------" << endl;
                        cars.at(i).displayCarDetails();
                        cout << "----------------------------------------" << endl;
                    }
                    break;
                }

                case 4: {
                    // Remove Car Record
                    string carid;
                    bool flag = false;
                    cout << "Please enter the Car ID that you would like to remove: ";
                    cin >> carid;

                    for (int i = 0; i < cars.size(); ++i) {
                        if (cars[i].getId() == carid) {
                            cout << "Car found: " << endl;
                            cars[i].displayCarDetails();
                            char confirmation;
                            cout << "Are you sure you want to delete this car? (y/n): ";
                            cin >> confirmation;
                            if (confirmation == 'y' || confirmation == 'Y') {
                                cars.erase(cars.begin() + i);
                                cout << "Car removed successfully!" << endl;
                            } else {
                                cout << "Car removal canceled." << endl;
                            }
                            flag = true;
                            break;
                        }
                    }

                    if (!flag) {
                        cout << "Sorry, no car found with the given ID." << endl;
                    }
                    break;
                }

                case 5:{
                    // search bill by cusid using linear search
                    string searchByCusID;
                    cout << "Please enter the customer ID to search: ";
                    cin >> searchByCusID;
                    vector <Bill> cusIDbill; // temp store the bill that meets the search
                    for(int i=0; i < Bills.size(); i++){
                        if(searchByCusID == Bills.at(i).cusID){
                            cusIDbill.push_back(Bills.at(i));
                        }
                    }
                    if(cusIDbill.size()>0){
                        for(int i=0; i < cusIDbill.size(); i++){
                            printBill(cusIDbill.at(i));
                        }
                    } else {
                        cout << "There is no bill for the customer ID." << endl << endl;
                    }
                    break;
                }

                case 6:{
                    // search bill by bill year using linear search
                    int searchByYear;
                    cout << "Please enter the bill year to search: ";
                    cin >> searchByYear;
                    vector <Bill> Yearbill; // temp store the bill that meets the search
                    for(int i=0; i < Bills.size(); i++){
                        if(searchByYear == Bills.at(i).year){
                            Yearbill.push_back(Bills.at(i));
                        }
                    }
                    if(Yearbill.size()>0){
                        for(int i=0; i < Yearbill.size(); i++){
                            printBill(Yearbill.at(i));
                        }
                    } else {
                        cout << "There is no bill in this year." << endl << endl;
                    }
                    break;
                }

                case 7:{
                    // Annual report
                    int yearChoice;
                    cout << "Enter the year for annual report: ";
                    cin >> yearChoice;

                    vector <Bill> tempBill = Bills;
                    // sort the bills by year
                    quickSortByYear(tempBill, 0, tempBill.size()-1);
                    vector <Bill> annualBill;
                    annualBill = binarySearchByYear(tempBill, 0, tempBill.size()-1, yearChoice);
                    generateAnnualReport(annualBill, yearChoice);

                    break;
                }

                case 8: {
                    System(); // Exit to main menu
                    break;
                }
                default: {
                    cout << "Invalid choice, please try again." << endl;
                }
            }
        }
    } else if (choice == 3) {
        cout << "Exiting program.\n";
        exit(0);
    } else {
        cout << "Invalid choice. Please try again.\n";
    }
}

int main() {
    // generate unique id for all cars
    for (auto& car : cars) {
        car.setId(cars);
    }
    System();
    return 0;
}
