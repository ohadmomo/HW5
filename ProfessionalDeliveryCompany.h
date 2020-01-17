#pragma once
#ifndef PROFESSIONALDELIVERYCOMPANY_H_
#define PROFESSIONALDELIVERYCOMPANY_H_
#include"DeliveryCompany.h"

class ProfessionalDeliveryCompany: public DeliveryCompany  {
public:
	//c'tor
	ProfessionalDeliveryCompany(int money = 100);

	//d'tor
	//~ProfessionalDeliveryCompany();
	//bool addVehicle(DeliveryVehicle* vehicle);
	//bool receiveParcel(Parcel* parcel);
	//bool performDeliveryDay();
	//void displayFunds();
	//void displayNumberOfDeliveries();
private:
	int getType() const;
};

#endif /* PROFESSIONALDELIVERYCOMPANY_H_ */
