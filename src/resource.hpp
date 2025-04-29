//resource.hpp
//Thomas Bond
//April 23 2025

class resourceTable {
public:
   resourceTable() : i(0), j(0), available(new int[j]), max(new int[i * j]), allocation(new int[i* j]) {} //Default Constructor
   resourceTable(int process, int resource) : i(process), j(resource), available(new int[j]), max(new int[i * j]), allocation(new int[i * j]) {} //Integer Constructor
   
   void resize(int, int); //Resizes the arrays

   int i,j; //i = number of processes, j = number of resource types
   int* available;
   int* max;
   int* allocation;
};
