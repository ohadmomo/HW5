#include "FastDeliveryVehicle.h"
#include <string.h>


FastDeliveryVehicle::FastDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {};


int FastDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int total_distance;
	DeliveryVehicle::performDeliveryDayInternal(numberOfDeliveries, &total_distance);
	return (calcProfitFast(total_distance, *numberOfDeliveries));
}

int FastDeliveryVehicle::calcProfitFast(int sum_distance, int num_of_deliveries) const
{
	return (sum_distance - quality_);
}

int FastDeliveryVehicle::getType() const { return fast; }