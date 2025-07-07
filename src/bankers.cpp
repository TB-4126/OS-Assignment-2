//bankers.cpp
//Thomas Bond
//April 28 2025
#include <iostream>
#include <fstream>
#include <string>
#include "resource.hpp"

int main(int argc, char* argv[]) {
   //
   //Collects the data from the CSV files
   //
   std::ifstream inFileResource(argv[1]); //Opens the resource data file
   std::ifstream inFileProcess(argv[2]); //Opens the process data file

   if (!inFileResource.is_open()) { //Checks if file failed to open
      std::cerr << "ERROR; could not open file: " << argv[1] << std::endl;
      exit(1);
   }
   if (!inFileProcess.is_open()) { //Checks if file failed to open
      std::cerr << "ERROR; could not open file: " << argv[2] << std::endl;
      exit(1);
   }

   //
   //Stores the data into matrices
   //


   //Matrices storing raw file contents
   std::string resource[2][4];
   std::string process[4][16];

   
   // inFileResource >> ;
   // inFileProcess >> ;


   int processQuantity = 5; int  resourceQuantity = 3; //Collects the number of processes and resource types

   int fileAvailable[resourceQuantity];
   int fileMax[processQuantity][resourceQuantity];
   int fileAllocation[processQuantity][resourceQuantity];

   

   fileAvailable[0] = 3; //Resource type A
   fileAvailable[1] = 3; //Resource type B
   fileAvailable[2] = 2; //Resource type C

   //p0
   fileMax[0][0] = 7;         //p0 type A max
   fileAllocation[0][0] = 0;  //p0 type A Allocated
   fileMax[0][1] = 5;         //p0 type B max
   fileAllocation[0][1] = 1;
   fileMax[0][2] = 3;         //p0 type C max
   fileAllocation[0][2] = 0;
   
   //p1
   fileMax[1][0] = 3;         //p1 type A max
   fileAllocation[1][0] = 2;
   fileMax[1][1] = 2;         //p1 type B max
   fileAllocation[1][1] = 0;
   fileMax[1][2] = 2;
   fileAllocation[1][2] = 0;

   //p2
   fileMax[2][0] = 9;
   fileAllocation[2][0] = 3;
   fileMax[2][1] = 0;         //p2 type B max
   fileAllocation[2][1] = 0;
   fileMax[2][2] = 2;
   fileAllocation[2][2] = 2;
   
   //p3
   fileMax[3][0] = 2;         //p3 type A max
   fileAllocation[3][0] = 2;
   fileMax[3][1] = 2;
   fileAllocation[3][0] = 1;
   fileMax[3][2] = 2;         //p3 type C max
   fileAllocation[3][0] = 1;

   //p4
   fileMax[4][0] = 4;
   fileAllocation[4][0] = 0;
   fileMax[4][1] = 3;         //p4 type B max
   fileAllocation[4][0] = 0;
   fileMax[4][2] = 3;
   fileAllocation[4][0] = 2;


   //Available Array

   //Max Array

   //Allocation Array


   //Need Array
   int need[processQuantity][resourceQuantity];

   for (int n = 0; n < processQuantity; ++n) {
      for (int m = 0; m < resourceQuantity; ++m) {
         need[n][m] = fileMax[n][m] - fileAllocation[n][m];
      }
   }

   //
   //Safety Algorithm
   //
   bool safeState = true;        //Bool indicating if the system is in a safe state
   int work[resourceQuantity];   //Array work initilized to the resources that are available
   for (int m = 0; m < resourceQuantity; ++m) { work[m] = fileAvailable[m]; }
   bool finish[processQuantity]; //Array finish initialized to false
   for (int n = 0; n < processQuantity; ++n) { finish[n] = false; }


   for (int n = 0; n < processQuantity; ++n) {
      for (int m = 0; m < resourceQuantity; ++m) {
         if (finish[n] == false && need[n][m] <= fileMax[n][m]) { //If a process is not finished and resources are available
            work[m] = work[m] + fileAllocation[n][m];             //Adds the allocated instances to the work array
            finish[n] = true;                                     //Sets finish for the process to true
         }
      }
   }

   for (int n = 0; n < processQuantity; ++n) {      //The sate is assumed to already be safe, with the loop looking for a false entry
      if (!finish[n]) { safeState = false; break; } //If any are false it breaks the loop
   }

   //
   //Resource-Request Algorithm
   //

   int request[processQuantity][resourceQuantity]; //Declaring the request array

   //triggers when a request is made
   //step 1
   // if request[n][m] <= need[n][m] true go to step 2, otherwise raise an error

   //step 2
   // if request[n][m] <= available[m] true go to step 3, otherwise the Process_i

   //step 3
   //Pretend to allocate the requested resources by modifying the state
   //State becomes:
   //available[m] -= request[n][m]
   //allocation[n][m] += request[n][m]
   //need[n][m] -= request[n][m]

   //what is the safe sequence?
   char safeSequence[processQuantity];

   //outputs wheather the system is in a safe state and what the safe sequence is
   if (safeState != false) { std::cout << "The system's safe sequence is: " << safeSequence << std::endl; }
   else { std::cout << "The system is not safe" << std::endl; }

   //Closes the files
   inFileResource.close();
   inFileProcess.close();
}
