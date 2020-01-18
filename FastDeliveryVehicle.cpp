#include "FastDeliveryVehicle.h"
#include <string.h>
using namespace std;

FastDeliveryVehicle::FastDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {};


int FastDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int total_distance;
	DeliveryVehicle::performDeliveryDayInternal(numberOfDeliveries, &total_distance);
	int profit = calcProfitFast(total_distance, *numberOfDeliveries);
	if (*numberOfDeliveries == 0)
		cout << "No parcels to deliver for vehicle " << this->getID() << endl;
	else
		cout << "Total revenue is " << profit << endl;
	return profit;
}

int FastDeliveryVehicle::calcProfitFast(int sum_distance, int num_of_deliveries) const
{
	return (sum_distance - quality_);
}

int FastDeliveryVehicle::getType() const { return fast; }