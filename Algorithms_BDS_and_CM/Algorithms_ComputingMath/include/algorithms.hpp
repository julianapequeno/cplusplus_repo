#ifndef ALGORITHMS_hpp
#define ALGORITHMS_hpp

#include <iostream>
#include <vector>

class algorithms{
    private:
        std::vector<int> primes;
    public:
        /*Eratosthenes_sieve*/
        void eratosthenes_sieve(int n);
        int get_eSieve_number(int i);
        int get_eSieve_size();

};

#endif