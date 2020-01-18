#include "ProfessionalDeliveryVehicle.h"
#include <string.h>
#include <iostream>
#define NUMBER_OF_PARCELS 5
using namespace std;

ProfessionalDeliveryVehicle::ProfessionalDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {};

bool ProfessionalDeliveryVehicle::addParcel(Parcel* parcel)
{
	if (parcel_array_[NUMBER_OF_PARCELS - 1] != NULL)
		return false;
	int i;
	for (i = 0; i < getNumOfParcels(); i++)
	{
		if (parcel == parcel_array_[i]) // if this parcel already exists
			return false;
	}
	for (i = 0; i < NUMBER_OF_PARCELS; i++)
	{
		if (parcel_array_[i] == NULL)
		{
			if (i == 0)
			{
				if (DeliveryVehicle::Distance(current_station_, parcel->getDest()) <= 4)
				{
					parcel_array_[i] = parcel;
					return true;
				}
				return false;
			}
			if (DeliveryVehicle::Distance(parcel_array_[i - 1]->getDest(), parcel->getDest()) <= 4)
			{
				parcel_array_[i] = parcel;
				return true;
			}
			return false;
		}
	}
	return false;//shouldnt get here
}

int ProfessionalDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int total_distance;
	DeliveryVehicle::performDeliveryDayInternal(numberOfDeliveries, &total_distance);
	int total_revenue = DeliveryVehicle::calcProfit(total_distance, *numberOfDeliveries);
	if (*numberOfDeliveries == 0)
		cout << "No parcels to deliver for vehicle " << (this->getID()) << endl;
	else
		cout << "Total revenue is " << total_revenue << endl;
	if (total_distance != 0)
		cout << "Revenue per distance: " << (total_revenue / total_distance) << endl;
	else
		cout << "Revenue per distance: no distance" << endl;
	if (*numberOfDeliveries != 0)
		cout << "Revenue per parcel: " << (total_revenue / (*numberOfDeliveries)) << endl;
	else
		cout << "Revenue per parcel: no parcels" << endl;
	return total_revenue;
}
int ProfessionalDeliveryVehicle::getType() const { return professional; }
