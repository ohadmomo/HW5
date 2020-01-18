#pragma once
#ifndef FASTDELIVERYCOMPANY_H_
#define FASTDELIVERYCOMPANY_H_
#include"DeliveryCompany.h"


class FastDeliveryCompany:public DeliveryCompany {
public:
	//c'tor
	FastDeliveryCompany(int money = 100);
	//d'tor
	~FastDeliveryCompany();
	//bool addVehicle(DeliveryVehicle* vehicle);
	//bool receiveParcel(Parcel* parcel);
	//bool performDeliveryDay();
	//void displayFunds();
	//void displayNumberOfDeliveries();
	int getType() const;
private:
};

#endif /* FASTDELIVERYCOMPANY_H_ */
