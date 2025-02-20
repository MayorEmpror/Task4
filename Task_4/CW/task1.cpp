#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int rows, cols;
    double** data;

public:
  
    Matrix() : rows(0), cols(0), data(nullptr) {}

   
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols]();
        }
    }

  
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

   
    ~Matrix() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }


    int getRows() const { return rows; }
    int getCols() const { return cols; }

    
    double& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[r][c];
    }

  
    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    
    Matrix transpose() const {
        Matrix transposed(cols, rows); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }

   
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    
    Matrix mat(3, 2);
    mat.fill(5.0);  
    std::cout << "Original Matrix: " << std::endl;
    mat.print();

    
    Matrix transposed = mat.transpose();
    std::cout << "Transposed Matrix: " << std::endl;
    transposed.print();

    
    mat.at(1, 1) = 10.0;
    std::cout << "Modified Matrix: " << std::endl;
    mat.print();

   
    Matrix copiedMat = mat;
    std::cout << "Copied Matrix: " << std::endl;
    copiedMat.print();

    return 0;
}
