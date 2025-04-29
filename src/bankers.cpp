//bankers.cpp
//Thomas Bond
//April 28 2025
#include <iostream>
#include <fstream>
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

   //Collect the data from the CSV files


   //Collects the number of processes and resource types
   int processQuantity = 5; int  resourceQuantity = 3;
   
   int fileAvailable[resourceQuantity];
   int fileMax[processQuantity][resourceQuantity];
   int fileAllocation[processQuantity][resourceQuantity];


   //Stores the data from the file into the static arrays



   resourceTable* sharedTable; //Creates a table the size needed to store the data
   sharedTable = new resourceTable(processQuantity,resourceQuantity);

   //
   //Inputs the data into the shared table
   //
   //Available Array
   for (int m = 0; m < sharedTable->j; ++m) { sharedTable->available[m] = fileAvailable[m]; }

   //Max Array
   for (int n = 0; n < sharedTable->i; ++n) {
      for (int m = 0; m < sharedTable->j; ++m) {
         sharedTable->max[(n + sharedTable->i) * (m + sharedTable->j)] = *(fileMax[(n + sharedTable->i) * (m + sharedTable->j)]);
      }
   }

   //Allocation Array
   for (int n = 0; n < sharedTable->i; ++n) {
      for (int m = 0; m < sharedTable->j; ++m) {
         sharedTable->allocation[(n + sharedTable->i) * (m + sharedTable->j)] = *(fileAllocation[(n + sharedTable->i) * (m + sharedTable->j)]);
      }
   }

   //
   //Safety State Algorithm
   //

   //in a safe sequence?
   bool safe = false;

   //what is the safe sequence?
   char safeSequence[processQuantity];

   //outputs wheather it is safe or not
   if (safe != 0) { std::cout << "The system's safe sequence is: " << safeSequence << std::endl; }
   else { std::cout << "The system is not safe" << std::endl; }

   //Closes the files
   inFileResource.close();
   inFileProcess.close();
}
