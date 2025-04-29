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


   resourceTable* sharedTable;
   sharedTable = new resourceTable(processQuantity,resourceQuantity);

   //inputs the data
   sharedTable->max[(0 + sharedTable->i) * (1 + sharedTable->j)] = 5;

   std::cout << "The value of p0 B is: " << sharedTable->max[0 * (1 + 3)] << std::endl;



   //Closes the files
   inFileResource.close();
   inFileProcess.close();

}
