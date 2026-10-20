#include "../../include/logic/Reduct.h"

void Reduct::reduce(ArrayBitSet& activeArguments, const AF& framework, uint32_t argument) {
    activeArguments.remove(argument);

    for (uint32_t victim : framework.victims[argument]) {
        activeArguments.remove(victim);
    }
}
