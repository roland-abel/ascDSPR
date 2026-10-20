#include "../../include/logic/Reduct.h"

ArrayBitSet Reduct::get_reduct(ArrayBitSet& activeArguments, AF& framework, uint32_t argument) {
    // initialize variables
    vector<uint32_t> reduct_vector;
    vector<uint8_t> reduct_bitset;

    reduct_bitset.resize(static_cast<uint64_t>(framework.num_args) + 1);

    // iterate through all active arguments
    for (std::vector<unsigned int>::size_type i = 0; i < activeArguments._array.size(); i++) {
        // ignore the argument and the victims of the argument
        if (activeArguments._array[i] == argument || framework.exists_attack(argument, activeArguments._array[i])) {
            continue;
        }
        // add all argument not attacked by the argument to the set of still active arguments
        reduct_vector.push_back(activeArguments._array[i]);
        reduct_bitset[activeArguments._array[i]] = true;
    }

    return ArrayBitSet(reduct_vector, reduct_bitset);
}
