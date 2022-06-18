#include <iostream>
#include <vector>

class square_matrix{
    std::vector<std::vector<int>> items{};

    public:
        square_matrix(unsigned int dim);
        square_matrix(const square_matrix& matrix);

        unsigned int size() const;
        void print() const;
        int at(unsigned row,unsigned col) const;

        bool is_all_primes() const;
};

