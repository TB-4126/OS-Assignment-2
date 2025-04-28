//bankers.hpp
//Thomas Bond
//April 23 2025


/*Need a shared memory space to store the;
   Max
   Allocation
   Need
Arrays
all of them are i X j matrices
storing information sent to them by the processes and resources

Resources:
   A, 10 instances
   B, 5 instances
   C, 7 instances
*/

//should the shared memory just store the data from the table
//then run the processes with them accessing the stored data
//from shared memory

class resourceTable {
public:
   resourceTable() : j(3), available(new int[j]) {} //Default Constructor

   int i,j;
   int* available;
   int* max;
   int* allocation;
};


