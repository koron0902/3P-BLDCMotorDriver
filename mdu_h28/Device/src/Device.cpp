#include <ADC.hpp>
#include <chip.hpp>
#include <Device.hpp>
#include <HallSensor.hpp>
#include <Port.hpp>
#include <PWM.hpp>
#include <QEI.hpp>
#include <Storage.hpp>
#include <Timer.hpp>
#include <Uart.hpp>
#include <USB.hpp>
#include <SPI.hpp>
#include <SysTick.hpp>
#include <INT.hpp>

namespace Device {

void Init(){
	//using module supply clock
	Chip_SetupXtalClocking();
	SystemCoreClockUpdate();
	Tick::Init();
	//Each Function Initialize
	Port::Init();

	Storage::Init();
	Timer::Init();
	PWM::Init();
	Uart::Init();
	QEI::Init(10000);
	ADC::Init();
	USB::Init();
	SPI::Init();
	INT::Init();

}





} /* namespace Device */
