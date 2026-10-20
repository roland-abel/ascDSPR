#ifndef ARRAY_BITSET_H
#define ARRAY_BITSET_H

#include <vector>
#include <cstdint>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

/// <summary>
/// This class is realizes a combined data structure of an array and a bitset.
/// </summary>
class ArrayBitSet {

public:
    /// <summary>
    /// Array of fixed length, used for iterating through the contained elements.
    /// </summary>
    std::vector<uint32_t> _array;
    /// <summary>
    /// Bitset of fixed length, used for existance checks of an element.
    /// </summary>
    std::vector<uint8_t> _bitset;

    ArrayBitSet() {}

    ArrayBitSet(std::vector<uint32_t> new_array, std::vector<uint8_t> new_bitset) : _array{ new_array }, _bitset{ new_bitset } {}

    /// <summary>
    /// Frees the space of this instance, but not of its elements.
    /// </summary>
    void clear() {
        _bitset.clear();
        _array.clear();
    }
};

#endif