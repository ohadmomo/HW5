#pragma once
#include<stdlib.h>
#include<deque>
#include "DeliveryVehicle.h"
using namespace std;

class DeliveryVehicleList: public deque<DeliveryVehicle*> {
public: 
	DeliveryVehicleList();
	~DeliveryVehicleList();

	bool checkIfExists(DeliveryVehicle* vehicle);
	DeliveryVehicle* getElement(int index) const;
};

