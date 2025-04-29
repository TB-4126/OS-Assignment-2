//resource.cpp
//Thomas Bond
//April 28 2025
#include "resource.hpp"

void resourceTable::resize(int process, int resource) {
   i = process;
   j = resource;

   delete [] available;
   delete [] max;
   delete [] allocation;
   
   available = new int[j];
   max = new int[i * j];
   allocation = new int[i * j];
}

