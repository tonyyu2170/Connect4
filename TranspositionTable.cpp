#include "TranspositionTable.h"

TranspositionTable::TranspositionTable(unsigned int size) : T(size) {}

unsigned int TranspositionTable::index(uint64_t key) const {
    return key%T.size();
}

void TranspositionTable::reset() {
    memset(&T[0], 0, sizeof(Entry) * T.size());
}

void TranspositionTable::put(uint64_t key, uint8_t val) {
    assert(key < (1LL << 56));
    T[index(key)].key = key;
    T[index(key)].val = val;
}

uint8_t TranspositionTable::get(uint64_t key) const {
    assert(key < (1LL << 56));
    return T[index(key)].key == key ? T[index(key)].val : 0;
}