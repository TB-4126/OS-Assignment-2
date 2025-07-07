//resource.hpp
//Thomas Bond
//April 23 2025

#ifndef RESOURCE_HPP_
#define RESOURCE_HPP_

//build it for string arraies
template<typename T>
class matrixNode {
public:
   matrixNode() : columns_(0) {}
   matrixNode(T* value) : columns_(value) {}
   T operator[](int index) const { return columns_[index]; }
   T& operator[](int index) { return columns_[index]; }
   T* columns_;
};

template<typename T>
class matrix {
public:
   matrix() : rows_(nullptr), n_(0), m_(0) {}     //Default Constructor
   matrix(int, int, T);      //T Constructor
   matrix(const matrix<T>&); //Copy Constructor
   ~matrix();                //Destrcutor
   void swap(matrix<T>&);    //Constant Time Swap function
   matrix<T>& operator=(matrix<T> rhs) {
      this->swap(rhs); //Maybe there's some weirdness with the function call in relation to the return?
      std::cout << "Equals Operator called" << std::endl;
      return *this; //this line right here is the issue
   } //Equals Operator
   
   matrixNode<T> operator[](int) const;  //Subscript Accessor
   matrixNode<T>& operator[](int);       //Subscript Assignment operator

   //logical equals operator
   //logical less than operator

   //extraction/output operator
   //insertion/input operator
//private:
   matrixNode<T>* rows_;
   int n_, m_;
};

//
//Standard Class Functionality
//

//Matrix T Constructor
template<typename T>
matrix<T>::matrix(int i, int j, T value) : matrix() {
   //i = number of columns
   //j = number of rows
   n_ = i; m_ = j;

   //Allocates the needed space
   rows_ = new matrixNode<T>[m_];
   for (int m = 0; m < m_; ++m) {
      rows_[m] = new T[n_];
   }

   //Stores value in all entries
   for (int m = 0; m < m_; ++m) {
      for (int n = 0; n < n_; ++n) {
         rows_[m].columns_[n] = value;
      }
   }
}

//Matrix Copy Cosntructor
template<typename T>
matrix<T>::matrix(const matrix<T>& copy) : matrix() {
   n_ = copy.n_; m_ = copy.m_;
   
   //Allocates the needed size
   rows_ = new matrixNode<T>[m_];
   for (int m = 0; m < m_; ++m) {
      rows_[m] = new T[n_];
   }
   
   for (int m = 0; m < m_; ++m) {    //Row loop
      for (int n = 0; n < n_; ++n) { //Columns loop
         rows_[m][n] = copy.rows_[m][n];
      }
   }
}

//Matrix Destructor
template<typename T>
matrix<T>::~matrix() {
   //Loop to delete the column arrays in each row
   for (int m = 0; m < m_; ++m) { delete [] this->rows_[m].columns_; }
   delete [] this->rows_; //Deletes the row array
}

//Matrix Constant Time Swap function
template<typename T>
void matrix<T>::swap(matrix<T>& rhs) {
   matrixNode<T>* temp;
   temp = rhs.rows_;
   rhs.rows_ = this->rows_;
   this->rows_ = temp;
}

//
//Matrix Subscript Operations
//

//Subscript Access operator
template<typename T>
matrixNode<T> matrix<T>::operator[](int index) const { return rows_[index]; }

//Subscript Assignment operator
template<typename T>
matrixNode<T>& matrix<T>::operator[](int index) { return rows_[index]; }

//
//IO Operations
//



#endif
