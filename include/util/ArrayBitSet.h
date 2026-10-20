#ifndef ARRAY_BITSET_H
#define ARRAY_BITSET_H

#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/// <summary>
/// This class realizes a combined data structure of an array and a bitset.
/// </summary>
class ArrayBitSet {
public:
    /// <summary>
    /// Array of fixed length, used for iterating through the contained elements.
    /// </summary>
    std::vector<uint32_t> _array;

    /// <summary>
    /// Bitset of fixed length, used for existence checks of an element.
    /// </summary>
    std::vector<uint8_t> _bitset;

    ArrayBitSet(const ArrayBitSet&) = default;

    ArrayBitSet& operator=(const ArrayBitSet&) = default;

    ArrayBitSet(ArrayBitSet&&) noexcept = default;

    ArrayBitSet& operator=(ArrayBitSet&&) noexcept = default;

    ~ArrayBitSet() = default;

    ArrayBitSet(std::vector<uint32_t> new_array, std::vector<uint8_t> new_bitset)
        : _array(std::move(new_array)), _bitset(std::move(new_bitset)) {
    }

    [[nodiscard]] bool empty() const {
        return _array.empty();
    }

    [[nodiscard]] bool contains(uint32_t index) const {
        return _bitset[index];
    }

    /// <summary>
    /// Frees the space of this instance, but not of its elements.
    /// </summary>
    void clear() noexcept {
        _bitset.clear();
        _array.clear();
    }
};

#endif
