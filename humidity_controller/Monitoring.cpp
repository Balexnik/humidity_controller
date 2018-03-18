#include "Monitoring.hpp"

Monitoring::Monitoring(int interval) :
		IntervalWorkerBase(interval) {
}

void Monitoring::work(Values *values, unsigned long currentMillis) {
	Serial.print(currentMillis / 1000);
	Serial.print("Temperature Mokry: ");
	Serial.print(values->wetT);
	Serial.println(" *C");
	Serial.print("Temperature Syhoi: ");
	Serial.print(values->dryT);
	Serial.println(" *C");
	Serial.print("Humidity dyn:  ");
	Serial.print(values->humDyn);
	Serial.println("%    ");

	Serial.print("Humidity stat:  ");
	Serial.print(values->humStat);
	Serial.println("%    ");

#ifdef CLIMATE_DEBUG_RAM
	Serial.print("\t");
	Serial.print(DebugUtils::getfreeRam());
#endif
	Serial.print("\n");
	Serial.flush();
}
