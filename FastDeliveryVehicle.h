#ifndef FASTDELIVERYVEHICLE_H_
#define FASTDELIVERYVEHICLE_H_
#include "DeliveryVehicle.h"


class FastDeliveryVehicle : public DeliveryVehicle {
public:

	//c'tor
	FastDeliveryVehicle(const char* ID, Quality quality);
	//d'tor
	//~FastDeliveryVehicle();
	//adds parcel to vehicle returns false if add failed
	int performDeliveryDay(int* numberOfDeliveries);
private:
	int calcProfitFast(int sum_distance, int num_of_deliveries) const;
	int getType() const;
};
#endif /* FASTDELIVERYVEHICLE_H_ */
