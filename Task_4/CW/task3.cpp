#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* array;
    int currentSize;

public:
    
    DynamicArray() : array(nullptr), currentSize(0) {}

   
    DynamicArray(int n) : currentSize(n) {
        if (n > 0) {
            array = new int[n];  
            for (int i = 0; i < n; ++i) {
                array[i] = 0;
            }
        } else {
            array = nullptr;
        }
    }


    DynamicArray(const DynamicArray& other) : currentSize(other.currentSize) {
        if (currentSize > 0) {
            array = new int[currentSize];
            for (int i = 0; i < currentSize; ++i) {
                array[i] = other.array[i];
            }
        } else {
            array = nullptr;
        }
    }

    
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this; 
        }

       
        delete[] array;

        currentSize = other.currentSize;
        if (currentSize > 0) {
            array = new int[currentSize];
            for (int i = 0; i < currentSize; ++i) {
                array[i] = other.array[i];
            }
        } else {
            array = nullptr;
        }

        return *this;
    }

  
    ~DynamicArray() {
        delete[] array;
    }

  
    int size() const {
        return currentSize;
    }

   
    int& at(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds.");
        }
        return array[index];
    }

   
    const int& at(int index) const {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds.");
        }
        return array[index];
    }

   
    void resize(int newSize) {
        if (newSize == currentSize) {
            return; 
        }

        int* newArray = new int[newSize]; 

      
        for (int i = 0; i < newSize; ++i) {
            newArray[i] = 0;
        }

       
        int elementsToCopy = (newSize < currentSize) ? newSize : currentSize;
        for (int i = 0; i < elementsToCopy; ++i) {
            newArray[i] = array[i];
        }

       
        delete[] array;
        array = newArray;
        currentSize = newSize;
    }
};

int main() {
    try {

        DynamicArray arr1;

       
        DynamicArray arr2(5);  
        for (int i = 0; i < arr2.size(); ++i) {
            arr2.at(i) = i + 1;  
        }

       
        DynamicArray arr3(arr2);

      
        DynamicArray arr5 = arr3; 

       
        arr3.resize(8); 
        for (int i = 5; i < arr3.size(); ++i) {
            arr3.at(i) = i + 1; 
        }

       
        std::cout << "arr3 contents: ";
        for (int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3.at(i) << " ";
        }
        std::cout << std::endl;

      
        std::cout << arr3.at(10) << std::endl;  

    } catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
