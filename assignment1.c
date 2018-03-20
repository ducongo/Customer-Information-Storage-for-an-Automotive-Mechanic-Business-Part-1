/******************************************************************************

                                Parfait Kingwaya
              


*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

/*
* Struct:  VehicleType
* --------------------
*  make: the make of a  car
*  model: the model of a car
*  colour: the colour of a car
*  year: the year of a car
*  mileage: the mileage of a car in KM
*/
typedef struct {

  char make[MAX_STR];
  char model[MAX_STR];
  char colour[MAX_STR];
  int year;
  int mileage;

} VehicleType;

/*
* Struct:  CustomerType
* --------------------
*  firstName: Customer's first name
*  lastName: Customer's last name
*  numCarRegistered: customer's number of cars owned
*  carsOwned: array of the collection o f all the cars owned by the customer
*/
typedef struct {

  char firstName[MAX_STR];
  char lastName[MAX_STR];
  int numCarRegistered;
  VehicleType carsOwned[MAX_VEHICLES];

} CustomerType;

void print_vehicle(VehicleType *v);
void print_customer(CustomerType *c);
int add_vehicle(CustomerType *customer, VehicleType *vehicle);
CustomerType create_customer(char* fname, char* lname);
VehicleType create_vehicle(char* make, char* model, char* colour, int year, int mileage);
/*
 * Function:  print_vehicle
 * --------------------
 * prints the passed vehicle's mode, make, colour, mileage and year
 *
 *  v: pointer of type VehicleType
 *
 *  returns: void function
 */
void print_vehicle(VehicleType *v) {
  printf("%d %s %s, %s, %dKM\n", v->year, v->make, v->model, v->colour, v-> mileage);
}

/*
 * Function:  print_customer
 * --------------------
 * prints the passed customer's name, number of vehicles owned and calls print_vehiclewhich
 * prints all the vehicles owned data
 *
 *  c: pointer of type CustomerType
 *
 *  returns: void function
 */
void print_customer(CustomerType *c) {

  printf("%s %s, %d vehicle(s)\n", c->firstName, c->lastName, c->numCarRegistered);

  for (int i = 0; i < c->numCarRegistered; i++) {
    print_vehicle(&(c->carsOwned[i]));
  }

}


/*
 * Function:  add_vehicle
 * --------------------
 * Attempts to add a vehicle to a customer's vehicles collection
 *
 *  customer: pointer of type CustomerType
 *  vehicle: pointer of type VehicleType
 *
 *  returns: 0 if a vehicle was succesfully added
 *           1 if the custopmer already has 4 vehicles and cant add a 5th one
 */
int add_vehicle(CustomerType *customer, VehicleType *vehicle) {

    if (customer->numCarRegistered >= MAX_VEHICLES){
        return 1;
    }

    customer->carsOwned[customer->numCarRegistered] = *vehicle;
    customer->numCarRegistered += 1;
    return 0;
}


/*
 * Function:  create_customer
 * --------------------
 * Creates a new customer
 *
 *
 *  fname: pointer of type char (the customers first name)
 *  lname: pointer of type char (the customers last name)
 *  newCustomer: type CustomerType (new customer object)
 *
 *  returns: newCustomer of type CustomerType
 */
CustomerType create_customer(char* fname, char* lname) {
  CustomerType newCustomer;

  strcpy(newCustomer.firstName,fname);
  strcpy(newCustomer.lastName,lname);

  return newCustomer;
}

/*
 * Function:  create_vehicle
 * --------------------
 * Creates a new vehicle
 *
 *
 *  make: the make of the new car
 *  model: the model of the new car
 *  colour: the colour of the new car
 *  year: the year of the new car
 *  mileage: the mileage of the new car in KM
 *  newVehicle: type VehicleType (new vehicle object)
 *
 *  returns: newVehicle of type CustomerType
 */
VehicleType create_vehicle(char* make, char* model, char* colour,
                            int year, int mileage) {
    VehicleType newVehicle;

    strcpy(newVehicle.make, make);
    strcpy(newVehicle.model, model);
    strcpy(newVehicle.colour, colour);

    newVehicle.year = year;
    newVehicle.mileage = mileage;

    return newVehicle;
}


int main() {
    printf("\n******************************************************\n");
    //creating instances of cutstomers and adding it to the array ofcustomers
    CustomerType customers[MAX_CUSTOMERS];
    customers[0] = create_customer("Maurice","Mooney");
    customers[1] = create_customer("Abigail","Atwood");
    customers[2] = create_customer("Brook","Banding");
    customers[3] = create_customer("Ethan","Esser");
    customers[4] = create_customer("Eve","Engram");
    customers[5] = create_customer("Victor","Vanvalkenburg,");

    //creating instances of vehicles and adding it to the array of vehicles
    VehicleType vehicles[13];
    vehicles[0] = create_vehicle("Ford", "Fiesta", "Red", 2007, 100000);
    vehicles[1] = create_vehicle("Subaru", "Forester", "Green", 2016, 40000);
    vehicles[2] = create_vehicle("Honda", "Accord", "White", 20182018, 5000);
    vehicles[3] = create_vehicle("Volkswagen", "Beetle", "White", 1972, 5000);
    vehicles[4] = create_vehicle("Toyota", "Camry", "Black", 2010, 50000);
    vehicles[5] = create_vehicle("Toyota", "Corolla", "Green", 2013, 80000);
    vehicles[6] = create_vehicle("Toyota", "Rav4", "Gold", 2015, 20000);
    vehicles[7] = create_vehicle("Toyota", "Prius", "Blue", 2017, 0000);
    vehicles[8] = create_vehicle("GM,", "Envoy", "Purple", 2012, 60000);
    vehicles[9] = create_vehicle("GM,", "Escalade", "Black", 2016, 40000);
    vehicles[10] = create_vehicle("GM,", "Malibu", "Red", 2015, 20000);
    vehicles[11] = create_vehicle("GM", "Trailblazer", "Orange", 2012, 90000);
    vehicles[12] = create_vehicle("Testla", "Model S", "Black", 2015, 2000);

    //adding vehicles to customers collection assuming all have 4 or less vehicles that wont exceed the limit
    add_vehicle(&customers[0], &vehicles[0]);
    add_vehicle(&customers[1], &vehicles[1]);
    add_vehicle(&customers[2], &vehicles[3]);
    add_vehicle(&customers[2], &vehicles[3]);
    add_vehicle(&customers[3], &vehicles[4]);
    add_vehicle(&customers[4], &vehicles[5]);
    add_vehicle(&customers[4], &vehicles[6]);
    add_vehicle(&customers[4], &vehicles[7]);
    add_vehicle(&customers[5], &vehicles[8]);
    add_vehicle(&customers[5], &vehicles[9]);
    add_vehicle(&customers[5], &vehicles[10]);
    add_vehicle(&customers[5], &vehicles[11]);

    //Printing all the customers using the print_customer function
    for (int i = 0; i < MAX_CUSTOMERS; i++ ){
        print_customer(&customers[i]);
        printf("\n");
    }

    printf("\nGOING TO ATTMPT TO ADD VEHICLES TO THE CUSTOMER WITH 4 VEHICLES ALREADY\n");

    //Attempting to add a vehicle to a customer who already has 4 vehicles in his collection
    if (add_vehicle(&customers[5], &vehicles[12]) == 0){
        printf("SUCCESFULLY ADDED THE NEW VEHICLE!\n");
        print_customer(&customers[5]);

    }else{
        printf("\nCANNOT ADD ANOTHER VEHICLES!\n");
    }

    printf("GOING TO ATTMPT TO ADD VEHICLES TO THE CUSTOMER WITH LESS THAN 4 VEHICLES\n");

    //Attempting to add a vehicle to a customer who already has 4 vehicles in his collection
    if (add_vehicle(&customers[1], &vehicles[12]) == 0){
        printf("SUCCESFULLY ADDED THE NEW VEHICLE!\n\n");

        print_customer(&customers[1]);

    }else{
        printf("CANNOT ADD ANOTHER VEHICLES!\n");
    }

    printf("******************************************************\n");
    return 0;
}
