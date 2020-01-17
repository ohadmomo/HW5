#include"DeliveryVehicleList.h"
DeliveryVehicleList::DeliveryVehicleList() {}
DeliveryVehicleList::~DeliveryVehicleList() {}

bool DeliveryVehicleList::checkIfExists(DeliveryVehicle* vehicle)
{
	queue<DeliveryVehicle*>* tmp_queue;
	int queue_size = this->size();
	int i, count = 0;
	bool isExists = false;
	for (i = 0; i < queue_size; i++)
	{
		if (strcmp(vehicle->getID(), (this->front()->getID())))
		{
			isExists = true;
			break;
		}
		else
		{
			tmp_queue->push(this->pop());
			count++;
		}
	}
	for (i = 0; i < count; i++)
	{
		this->push(tmp_queue->pop());
	}
	return isExists;
}