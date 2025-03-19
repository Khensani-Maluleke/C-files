#include "myvector.h"
bool Thing::verbose = false;
size_t Thing::last_alloc = 0;

/**
 * @brief MyVector::MyVector Construct a vector with size 0
 *
 * Remember that the data pointer should point to nothing, and
 * counter variables should be initialised.
 */
MyVector::MyVector()
{
data=nullptr;
n_allocated=0;
n_items=0;
}

/**
 * @brief MyVector::~MyVector Free any memory that you have allocated do this last
 */
MyVector::~MyVector()
{
    // Do this last - if you have an error in your destructor it can crash your program
    delete[] data;
}

/**
 * @brief MyVector::size
 * @return The number of items in the vector
 */
size_t MyVector::size() const
{
return n_items;
}

/**
 * @brief MyVector::allocated_length
 * @return The length of the allocated data buffer
 */
size_t MyVector::allocated_length() const
{
return n_allocated;
}

/**
 * @brief MyVector::reallocate
 * @param new_size
 * Reallocate the memory buffer to be "new_size" length, using new Thing[new_size]
 * Copy all items from the old buffer into the new one.
 * Delete the old buffer using delete[]
 */
void MyVector::reallocate(size_t new_size)
{
    Thing* ptemp =new Thing[new_size];
    for(int i = 0; i < n_items; ++i){
     ptemp[i] = data[i];
    }
    delete [] data;
    data = ptemp;
    n_allocated = new_size;
}

/**
 * @brief MyVector::push_back
 * @param t The thing to add
 *
 * Add a thing to the back of the vector.
 * Remember to check if there is enough space to insert it first.
 * If there is not enough space, then you should reallocate the buffer
 * and copy each thing accross. When expanding the buffer, double the
 * allocated size.
 */
void MyVector::push_back(const Thing &t)
{   if(n_allocated == 0){
        n_allocated =1;
        reallocate(n_allocated);
    }

   if(n_allocated==n_items){
       reallocate(n_allocated*2);

   }
       data[n_items]=t;
       n_items++;

}

/**
 * @brief MyVector::pop_back
 * Remove the last item from the back.
 * Reallocate with half the space if less than a quarter of the vector is used.
 */
void MyVector::pop_back()
{   n_items--;
    if(n_items<((0.25)*n_allocated)){
        reallocate((0.5)*n_allocated);
    }

}
/*/**
 * @brief MyVector::push_front
 * Add an item to the front of the vector.
 * Reallocate with twice the space if the vector is full.
 */
/*void MyVector::push_front(const Thing &t)
{
    if (n_allocated == 0) {
        n_allocated = 1;
        reallocate(n_allocated);
    }

    if (n_allocated == n_items) {
        reallocate(n_allocated * 2);
    }

    // Shift all existing elements to the right
    for (int i = n_items; i > 0; --i) {
        data[i] = data[i - 1];
    }

    // Insert the new element at the front
    data[0] = t;
    n_items++;
}

/**
 * @brief MyVector::pop_front
 * Remove the first item from the vector.
 * Reallocate with half the space if less than a quarter of the vector is used.
 */
/*void MyVector::pop_front()
{
    if (n_items == 0) {
        // No elements to remove
        return;
    }

    // Shift all elements to the left
    for (size_t i = 0; i < n_items - 1; ++i) {
        data[i] = data[i + 1];
    }

    n_items--;

    if (n_items < static_cast<size_t>(0.25 * n_allocated)) {
        reallocate(n_allocated / 2);
    }
}

/**
 * @brief MyVector::front
 * @return A reference to the first item in the array.
 * I will never call this on an empty list.
 */
Thing &MyVector::front()
{
    return data[0];
}

/**
 * @brief MyVector::back
 * @return A reference to the last item in the array.
 *
 * Note that this might not be the back of the data buffer.
 * I will never call this on an empty list.
 */
Thing &MyVector::back()
{
return data[n_items-1];
}

/**
 * @brief MyVector::begin
 * @return A pointer to the first thing.
 */
Thing *MyVector::begin()
{
return data+0;
}

/**
 * @brief MyVector::end
 * @return A pointer to the memory address following the last thing.
 */
Thing *MyVector::end()
{
return data+ (n_items);
}


/**s
 * @brief MyVector::operator []
 * @param i
 * @return A reference to the ith item in the list.
 */
Thing &MyVector::operator[](size_t i)
{
return data[i];
}

/**
 * @brief MyVector::at
 * @param i
 * @return A reference to the ith item in the list after checking
 * that the index is not out of bounds.
 */
Thing &MyVector::at(size_t i)
{ if (n_allocated-1>i){
        return data[i];

    }
    throw std::out_of_range("Requested index out of bounds.");
}



///**
// * The iterator should reference the next item in the collection
// * @brief Iterator::operator ++
// * @return a reference to the current iterator (*this)
// */
//Iterator &Iterator::operator++()
//{
//    ptr++;
//    return *this;
//}

///**
// * @brief Iterator::operator *
// * @return the Thing objet that this iterator references
// */
//Thing &Iterator::operator*()
//{
//    return *ptr;
//}

//
//GENERAL C++
/*// Question 1: C++ and General Coding [20 Marks]
// 1. Sum of Vector Elements
int sumVector(const std::vector<int>& vec) {
    int sum = 0;
    for(int num : vec) {
        sum =sum+  num;
    }
    return sum;
}

// 2. Minimum Value in Vector
int minVector(const std::vector<int>& vec) {
    if(vec.empty()){
         return -1;

    } // Or handle the case as required.
    int minValue = vec[0];
    for(int num : vec) {
        if(num < minValue) {
            minValue = num;
        }
    }
    return minValue;
}

// 3. Number of Items in Vector
int vectorSize(const std::vector<int>* vecPtr) {
    return vecPtr->size();
}

// 4. Address of Last Item in Vector
int* lastItemAddress(std::vector<int>* vecPtr) {
    if(vecPtr->empty()){
        return nullptr;
    }  // Handle the empty vector case.
    return &vecPtr->back();
}*/



