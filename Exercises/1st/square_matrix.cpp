#include "square_matrix.hpp"
//given an unsigned 'dim', build a matrix square that can perform some operations

square_matrix::square_matrix(unsigned int dim){
    items.resize(dim);

    /*
    first way for the constructor
    for(size_t i{0}; i < dim; ++i){
        for(size_t j{0}; j < dim; ++j){
            items.at(j).push_back(0);
        }
    }*/


    //second way: It builds an emppty cells composed square matrix
    for(size_t i{0}; i < dim; ++i){
        items.at(i).resize(dim);
    }
}

unsigned int square_matrix::size() const{
    return items.at(0).size();
}

int square_matrix::at(unsigned row, unsigned col) const{    
    return items.at(row).at(col);
}

square_matrix::square_matrix(const square_matrix& matrix){  
    unsigned matrix_size{matrix.size()};

    items.resize(matrix_size);

    for(size_t i{0}; i < matrix_size; ++i){
        for(size_t j{0}; j < matrix_size; ++j){
            items.at(i).at(j) = matrix.at(i,j);
        }
    }
}

//class method that establish whether all the items are prime or not
bool square_matrix::is_all_primes() const{
    bool check{false};

    for(size_t i{0}; i < size() and !check; ++i){
        for(size_t j{0}; j < size(); ++j){
            for(int x{2}; x < at(i,j); ++x){
                check |= (!(at(i,j) % x));
            }
        }
    }

    return check;
}