#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_
#include "DeliveryVehicle.h"

class ProfessionalDeliveryVehicle : public DeliveryVehicle {
public:
	//c'tor
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);

	//d'tor
	//~ProfessionalDeliveryVehicle();

	//adds parcel to vehicle returns false if add failed
	bool addParcel(Parcel* parcel);

	int performDeliveryDay(int* numberOfDeliveries);
private:
	int getType() const;
};

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */
