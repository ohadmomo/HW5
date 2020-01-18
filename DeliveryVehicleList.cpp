#include"DeliveryVehicleList.h"
DeliveryVehicleList::DeliveryVehicleList() {}
DeliveryVehicleList::~DeliveryVehicleList() {}
/*
bool DeliveryVehicleList::checkIfExists(DeliveryVehicle* vehicle)
{
	deque <DeliveryVehicle*> tmp_queue;
	int deque_size = this->size();
	int i;
	for (i = 0; i < deque_size; i++)
	{
		DeliveryVehicle* vehicle_inside = this->at(i);
		if (!strcmp(vehicle_inside->getID(), vehicle->getID()));
			return true;
	}
	return false;
}*/
DeliveryVehicle* DeliveryVehicleList::getElement(int index) const
{
	return this->at(index);
}
