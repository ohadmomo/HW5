#include "ProfessionalDeliveryVehicle.h"
#include <string.h>
#define NUMBER_OF_PARCELS 5


ProfessionalDeliveryVehicle::ProfessionalDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {};

bool ProfessionalDeliveryVehicle::addParcel(Parcel* parcel)
{
	if (parcel_array_[NUMBER_OF_PARCELS - 1] == NULL)
		return false;
	int i;
	for (i = 0; i < NUMBER_OF_PARCELS; i++)
	{
		if (parcel_array_[i] != NULL)
		{
			if (i == 0)
			{
				if (DeliveryVehicle::Distance(current_station_, parcel->getDest() <= 4))
				{
					parcel_array_[i] = parcel;
					return true;
				}
				return false;
			}
			if (DeliveryVehicle::Distance(parcel_array_[i - 1]->getDest(), parcel->getDest() <= 4))
			{
				parcel_array_[i] = parcel;
				return true;
			}
		}
	}
	return false;
}

int ProfessionalDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int total_distance;
	DeliveryVehicle::performDeliveryDayInternal(numberOfDeliveries, &total_distance);
	return (DeliveryVehicle::calcProfit(total_distance, *numberOfDeliveries));
}
int ProfessionalDeliveryVehicle::getType() const { return professional; }
