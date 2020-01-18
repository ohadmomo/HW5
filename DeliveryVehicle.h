#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_
#define NUMBER_OF_PARCELS 5
#define MAX_TRAVEL_DISTANCE 12
#include "Parcel.h"
#include <iostream>
#define  DELIVERY_PROFIT 4


typedef enum quality { good = 3, ok = 4, bad = 5 } Quality;
typedef enum type { all = 0, fast = 1, professional = 2 } Type;
class DeliveryVehicle {
public:
	//c'tor
	DeliveryVehicle(const char* ID, Quality quality);

	//d'tor
	virtual ~DeliveryVehicle();

	//adds parcel to vehicle returns false if add failed
	virtual bool addParcel(Parcel* parcel);
	int Distance(int current_station, int next_station) const;
	void updateParcelArray(Parcel** parcel_array, int num_of_deliveries);
	virtual int performDeliveryDay(int* numberOfDeliveries);
	char* getID();
	virtual int getType() const;
protected:
	void performDeliveryDayInternal(int* numberOfDeliveries, int* total_distance);
	char* ID_;
	Quality quality_;
	Parcel** parcel_array_;
	int current_station_;
	int calcProfit(int sum_distance, int num_of_deliveries) const;
	int getNumOfParcels() const;
	
	
};

#endif /* DELIVERYVEHICLE_H_ */
