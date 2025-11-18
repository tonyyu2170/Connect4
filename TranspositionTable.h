#ifndef TRANSPOSITIONTABLE_H
#define TRANSPOSITIONTABLE_H

#include <cstring>
#include <cassert>
#include <vector>

class TranspositionTable {
    public:
        struct Entry {
            uint64_t key: 56;
            uint8_t val;
        };
        std::vector<Entry> T;

        TranspositionTable(unsigned int size);
        unsigned int index(uint64_t key) const;
        void reset();
        void put(uint64_t key, uint8_t val);
        uint8_t get(uint64_t key) const;
        
};

#endif