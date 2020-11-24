#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

enum class DEBUG_ENUM {
    WITHOUT_DEBUG,
    ALL_DEBUG
} DEBUG(DEBUG_ENUM::WITHOUT_DEBUG);


class Matrix {
public:
    Matrix(size_t _sz) : sz(_sz), elements(new long long*[sz]) {
        for (size_t row = 0; row < sz; ++row) {
            elements[row] = new long long[sz];
        }
    }
    ~Matrix() {
        while(sz--) {
            delete[] elements[sz];
        }
        delete[] elements;
    }

    size_t get_sz() const {
        return sz;
    }

    long long* operator[] (size_t pos) {
        return elements[pos];
    }

    void deb(DEBUG_ENUM MATRIX_DEBUG = DEBUG) {
        if (DEBUG == DEBUG_ENUM::ALL_DEBUG) {
            out();
        }
    }

private:
    size_t sz;
    long long** elements;

    void out() {
        std::cerr << " It's matrix with size " << sz << " :\n";
        for (size_t i = 0; i < sz; ++i) {
            for (size_t j = 0; j < sz; ++j) {
                std::cerr << elements[i][j] << " ";
            }
            std::cerr << std::endl;
        }
    }
};


#endif // MATRIX_H_INCLUDED
