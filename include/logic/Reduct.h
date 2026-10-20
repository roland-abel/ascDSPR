#ifndef REDUCT_H
#define REDUCT_H

#include <cstdint>

#include "AF.h"

#include "../util/ArrayBitSet.h"

using namespace std;

/// <summary>
/// This class is responsible for reducing the state of an abstract argumentation framework by a set of arguments.
/// </summary>
class Reduct {

public:
	/// <summary>
	/// Reduces the state of the specified framework by the specified argument in place.
	/// Removes the argument and all its victims from the specified set of active arguments.
	/// </summary>
	/// <param name="activeArguments">Set of active arguments in the current transition state; modified in place.</param>
	/// <param name="framework">The framework to reduce.</param>
	/// <param name="argument">The argument by which the framework will be reduced.</param>
	static void reduce(ArrayBitSet &activeArguments, const AF &framework, uint32_t argument);
};

#endif
