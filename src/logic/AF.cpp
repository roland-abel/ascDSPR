#include "../../include/logic/AF.h"
using namespace std;

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

bool AF::add_attack(uint32_t attacker, uint32_t victim)
{
	//check that input is valid
	if (attacker == 0 || victim == 0) return false;

	const uint64_t attack = pack_attack(attacker, victim);

	//check if attack is already contained
	if (_attacks.contains(attack)) {
		return false;
	}

	_attacks.insert(attack);
	return true;

}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

void AF::clear() {
	_attacks.clear();
	_attackers.clear();
	_victims.clear();
	_self_attack.clear();

	_num_args = 0;
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

ArrayBitSet AF::create_active_arguments() const {
	ArrayBitSet active_arguments(_num_args);

	//iterate through the arguments to append them to the argument set
	for (uint32_t i = 0; i < _num_args; ++i) {
		active_arguments.insert(i + 1);
	}

	return active_arguments;
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

bool AF::delete_attack(uint32_t attacker, uint32_t victim) {
	//check that input is valid
	if (attacker == 0 || victim == 0) return false;

	return _attacks.erase(pack_attack(attacker, victim)) == 1;
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

bool AF::exists_attack(uint32_t attacker, uint32_t victim) const {
	return _attacks.contains(pack_attack(attacker, victim));
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

bool AF::exists_attack(std::uint32_t argument, std::list<std::uint32_t> &set_arguments) const {
	//iterate through arguments of the set
	for (auto mIter = set_arguments.begin(); mIter != set_arguments.end(); ++mIter) {
		//check if query argument is victim of the set
		if (exists_attack(*mIter, argument)) {
			return true;
		}
	}

	return false;
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

void AF::initialize(uint32_t number_args) {
	_num_args = number_args;
	_attackers.resize(static_cast<uint64_t>(_num_args) + 1);
	_victims.resize(static_cast<uint64_t>(_num_args) + 1);
	_self_attack.resize(static_cast<uint64_t>(_num_args) + 1);

	std::fill(_self_attack.begin(), _self_attack.end(), 0);
}

/*===========================================================================================================================================================*/
/*===========================================================================================================================================================*/

void AF::finish_initilization()
{
	_attackers.clear();
	_victims.clear();

	std::fill(_self_attack.begin(), _self_attack.end(), 0);

	for (const uint64_t attack : _attacks) {
		const uint32_t source = unpack_attacker(attack);
		const uint32_t target = unpack_victim(attack);

		_attackers[target].push_back(source);
		_victims[source].push_back(target);

		if (source == target)
			_self_attack[source] = true;
	}
}