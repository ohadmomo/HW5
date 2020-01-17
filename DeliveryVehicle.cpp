#define _CRT_SECURE_NO_WARNINGS
#include "DeliveryVehicle.h"
#include <string.h>
#include <iostream>
#define NUMBER_OF_PARCELS 5
using namespace std;

DeliveryVehicle::DeliveryVehicle(const char* ID, Quality quality)
{
	quality_ = quality;
	current_station_ = 0;

	// Memory allocation!!
	char* new_copy = new char[strlen(ID) + 1];
	strncpy(new_copy, ID, (strlen(ID) + 1));
	ID_ = new_copy;
	// Memory allocation!!
	parcel_array_ = new Parcel* [NUMBER_OF_PARCELS];
	//int parcel_array_[5] = { 2,3,5,7,8 };

	int i;
	for (i = 0; i < NUMBER_OF_PARCELS; i++)
		parcel_array_[i] = NULL;
}

DeliveryVehicle::~DeliveryVehicle()
{
	delete[] ID_;
	int i;
	for (i = 0; i < NUMBER_OF_PARCELS; i++)
	{
		if (parcel_array_[i] != NULL)
			delete parcel_array_[i];
	}
	delete[] parcel_array_;
}

bool DeliveryVehicle::addParcel(Parcel* parcel)
{ //check adding same parcel
	if (parcel == NULL)
		return false;
	int i;
	for (i = 0; i < NUMBER_OF_PARCELS; i++)
	{
		if (parcel_array_[i] == NULL)
		{
			parcel_array_[i] = parcel;
			return true;
		}
	}
	return false;
}

int DeliveryVehicle::performDeliveryDay(int* numberOfDeliveries)
{
	int total_distance;
	DeliveryVehicle::performDeliveryDayInternal(numberOfDeliveries, &total_distance);
	int profit = calcProfit(total_distance, *numberOfDeliveries);
	cout << "Total revenue is " << profit << endl;
	return profit;
}

void DeliveryVehicle::performDeliveryDayInternal(int* numberOfDeliveries, int* total_distance)
{//what if NULL???
	int max_station = 12;//DEFINEEEE
	int sum_distance = 0;
	int num_of_deliveries = 0;
	int next_station, current_distance = 0;
	int i;
	cout << "Starting deliveries for vehicle " << ID_ << endl;
	for (i = 0; i < NUMBER_OF_PARCELS; i++)
	{
		next_station = parcel_array_[i]->getDest();
		current_distance = DeliveryVehicle::Distance(current_station_, next_station);
		if ((current_distance+sum_distance) <= max_station)
		{
			num_of_deliveries++;
			current_station_ = next_station;
			sum_distance += current_distance;
			cout << "Delivering parcel " << parcel_array_[i]->getID() << " to position " << parcel_array_[i]->getDest() << endl;
			cout << "Fuel consumed: " << current_distance << "Revenue is: " << (DELIVERY_PROFIT) << endl;
}
		else
		{
			DeliveryVehicle::updateParcelArray(parcel_array_, num_of_deliveries);
			*numberOfDeliveries = num_of_deliveries;
			*total_distance = sum_distance;
			cout << "Total travel distance is " << *total_distance << endl;
			return;
			//return (DeliveryVehicle::calcProfit(sum_distance, num_of_deliveries));
		}
	}
	DeliveryVehicle::updateParcelArray(parcel_array_, num_of_deliveries);
	*numberOfDeliveries = num_of_deliveries;
	*total_distance = sum_distance;
	cout << "Total travel distance is " << total_distance << endl;
	return; 
}

int DeliveryVehicle::Distance(int current_station, int next_station) const
{
	if (next_station - current_station >= 0)
	{
		return (next_station - current_station);
	}
	return (next_station + (10 - current_station));//MAKE DEFINE
}

void DeliveryVehicle::updateParcelArray(Parcel** parcel_array, int num_of_deliveries)
{
	int i;
	for (i = 0; i < num_of_deliveries; i++)
	{
		parcel_array[i]->~Parcel();
	}
	for (i = num_of_deliveries; i < NUMBER_OF_PARCELS; i++)
	{
		parcel_array[i - num_of_deliveries] = parcel_array[i];
		parcel_array[i] = NULL;
	}
}

int DeliveryVehicle::calcProfit(int sum_distance, int num_of_deliveries) const
{
	return (num_of_deliveries * DELIVERY_PROFIT - sum_distance - quality_);
}

char* DeliveryVehicle::getID() { return ID_; }

int DeliveryVehicle::getType() const { return all; }