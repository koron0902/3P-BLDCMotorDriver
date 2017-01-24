
#ifndef MIDDLE_HOLESENSOR_H_
#define MIDDLE_HOLESENSOR_H_

#include <functional>
#include <stdint.h>

namespace Middle {
namespace HallSensor{
void Init();

enum class HallStatus:uint32_t{
	None=0b000,
	U=0b001,
	UV=0b011,
	V=0b010,
	VW=0b110,
	W=0b100,
	WU=0b101
};

using HoleSensorHandler=std::function<void(HallSensor::HallStatus, bool)>;

void SetHandler(const HoleSensorHandler&func=nullptr);
void SetDirection(bool direction = true);



}
} /* namespace mid */

#endif /* MIDDLE_HOLESENSOR_H_ */
