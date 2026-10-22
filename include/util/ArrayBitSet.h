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
    explicit ArrayBitSet(uint32_t max_arguments)
        : _max_arguments(max_arguments),
          _array(max_arguments),
          _bitset(static_cast<std::size_t>(max_arguments) + 1, 0),
          _positions(static_cast<std::size_t>(max_arguments) + 1, 0) {
    }

    ArrayBitSet(const ArrayBitSet&) = default;

    ArrayBitSet& operator=(const ArrayBitSet&) = default;

    ArrayBitSet(ArrayBitSet&&) noexcept = default;

    ArrayBitSet& operator=(ArrayBitSet&&) noexcept = default;

    ~ArrayBitSet() = default;

    bool insert(uint32_t argument) {
        if (argument == 0
            || argument > _max_arguments
            || _bitset[argument] != 0
            || _size >= _max_arguments) {
            return false;
        }

        _bitset[argument] = 1;
        _positions[argument] = _size;
        _array[_size] = argument;
        ++_size;

        return true;
    }

    bool remove(uint32_t argument) {
        if (argument == 0
            || argument > _max_arguments
            || _bitset[argument] == 0) {
            return false;
        }

        _bitset[argument] = 0;

        const uint32_t position = _positions[argument];
        const uint32_t last_position = _size - 1;

        if (position != last_position) {
            const uint32_t last_argument = _array[last_position];
            _array[position] = last_argument;
            _positions[last_argument] = position;
        }

        --_size;
        return true;
    }

    [[nodiscard]] bool contains(uint32_t argument) const {
        return argument != 0
            && argument <= _max_arguments
            && _bitset[argument] != 0;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    /// <summary>
    /// Frees the space of this instance, but not of its elements.
    /// </summary>
    void clear() {
        std::fill(_bitset.begin(), _bitset.end(), 0);
        _size = 0;
    }

private:
    uint32_t _max_arguments{};

    uint32_t _size{};

    /// <summary>
    /// Array of fixed length, used for iterating through the contained elements.
    /// </summary>
    std::vector<uint32_t> _array{};

    /// <summary>
    /// Bitset of fixed length, used for existence checks of an element.
    /// </summary>
    std::vector<uint8_t> _bitset{};

    std::vector<uint32_t> _positions{};
};

#endif
