#pragma once
#include<stdlib.h>
#include<queue>
#include "DeliveryVehicle.h"
using namespace std;
class DeliveryVehicleList: public queue<DeliveryVehicle*> {
public: 
	DeliveryVehicleList();
	~DeliveryVehicleList();

	bool checkIfExists(DeliveryVehicle* vehicle);
	
};

