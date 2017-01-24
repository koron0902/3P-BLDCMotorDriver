#include <HallSensor.hpp>
#include <INT.hpp>
#include <xport.hpp>

namespace Middle {
namespace HallSensor{

using namespace Device;
using namespace Device::INT;
using namespace Device::Port;

static HoleSensorHandler handler;

static bool mDirection = true;

const IntHandler INTHandler(INT_ID);

void Init(){
	//GPIOの初期化
	HallU.Din();
	HallV.Din();
	HallW.Din();
	//登録する
	SetInt(HallU, INT_ID::INT0);
	SetInt(HallV, INT_ID::INT1);
	SetInt(HallW, INT_ID::INT2);
	//割り込み先を登録
	SetHandler(INT_ID::INT0, INTHandler);
	SetHandler(INT_ID::INT1, INTHandler);
	SetHandler(INT_ID::INT2, INTHandler);

	handler=nullptr;
}

void SetHandler(const HoleSensorHandler& func){
	handler=func;
}

void SetDirection(bool direction){
	mDirection = direction;
}

const IntHandler INTHandler(INT_ID){
	uint32_t data=0;
	data|=HallU.Get()?0b001:0;
	data|=HallV.Get()?0b010:0;
	data|=HallW.Get()?0b100:0;

	//Port::LED1.Set(data & 0b001);
	//Port::LED2.Set((data & 0b010) >> 1);
	//Port::LED3.Set((data & 0b100) >> 2);

	if (handler!=nullptr){
		handler((HallStatus)data, mDirection);
	}
}



}
} /* namespace mid */
