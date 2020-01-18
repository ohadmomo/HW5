#include"DeliveryCompany.h"
using namespace std;
DeliveryCompany::DeliveryCompany(int money) 
	:pdvl(NULL), next_to_deliver(NULL), num_of_deliveries(0) {
	budget = money;
	pdvl = new DeliveryVehicleList;
}

DeliveryCompany::~DeliveryCompany() {
	unsigned int i = 0;
	for (i = 0; i < pdvl->size(); i++)
	{
		if (pdvl->getElement(i) != NULL)
			delete pdvl->getElement(i);
	}
	delete pdvl;
}

bool DeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	if (vehicle == NULL) {
		return false;
	}
	if (getType() != all && getType() != vehicle->getType()) {
		delete vehicle;
		return false;
	}
	
	if (CheckIfExist(vehicle, pdvl)) {
		cout << "Can't add vehicle, it already exists" << endl;
		delete vehicle;
		return false;
	}
	pdvl->push_front(vehicle);
	return true;
}

bool DeliveryCompany::CheckIfExist(DeliveryVehicle* vehicle, DeliveryVehicleList* pdvl) const{
	
	//return pdvl->checkIfExists(vehicle);
	unsigned int i = 0;
	for (i = 0; i < pdvl->size(); i++) //check if size is correct
		if (!strcmp(pdvl->getElement(i)->getID(), vehicle->getID()))return true;
	return false;
}
 bool DeliveryCompany::receiveParcel(Parcel* parcel) {
	//DeliveryVehicle** head_of_queue = (DeliveryVehicle**)(pdvl->front());
	if (parcel == NULL) return false;
	if (pdvl->size() == 0) { // is this a good check??
		delete parcel;
		return false;
	}
	DeliveryVehicle* tmp_next_to_deliver = next_to_deliver;
	unsigned int next_to_deliver_index = 0;
	if (next_to_deliver == NULL) //first time
		next_to_deliver = pdvl->at(0);
	else
	{
		next_to_deliver_index = getIndex(next_to_deliver);
		if (next_to_deliver_index == pdvl->size()-1)
		{
			next_to_deliver = pdvl->at(0);
			next_to_deliver_index = 0;
		}
		else {
			if (getIndex(next_to_deliver) < 0) {
				delete parcel;
				return false;
			}
			next_to_deliver = pdvl->at(next_to_deliver_index+1);
			next_to_deliver_index++;
		}
	}
	unsigned int i = 0;
	for (i = next_to_deliver_index; i < pdvl->size(); i++)
	{
		if ((pdvl->at(i))->addParcel(parcel) == false)continue;//check if there is a case for parcel with sam id
		next_to_deliver = pdvl->getElement(i);
		return true;
	}
	for (i = 0; i < next_to_deliver_index; i++)
	{
		if ((pdvl->at(i))->addParcel(parcel) == false)continue;//check if there is a case for parcel with sam id
		next_to_deliver = pdvl->at(i);
		return true;
	}
	next_to_deliver = tmp_next_to_deliver;
	delete parcel;
	return false;
}

int DeliveryCompany::getType() const{ return all; }

void DeliveryCompany::displayNumberOfDeliveries() {
	cout << "Till now company has delivered " << num_of_deliveries << " parcels" << endl;
}

void DeliveryCompany::displayFunds() {
	cout << "Company balance is now " << budget << endl;
}
int DeliveryCompany::getIndex(DeliveryVehicle* vehicle) const {
	unsigned int i = 0;
	for (i = 0; i < pdvl->size(); i++) {
		if (pdvl->getElement(i) == vehicle) return i;
	}
	return -1; //shouldn't get here
}

bool DeliveryCompany::performDeliveryDay() {
	if (pdvl->size() == 0)return false;
	int i = 0;
	//DeliveryVehicle** head_of_queue = (DeliveryVehicle**)(pdvl->front());
	int num_of_daily_deliveries = 0;
	int daily_revenue = 0;
	int deque_size = (this->pdvl)->size();
	cout << "Starting days deliveries:" << endl;
	for (i = 0; i < deque_size; i++) {
		int per_car =  pdvl->at(i)->performDeliveryDay(&num_of_daily_deliveries);
		if (num_of_daily_deliveries == 0)
			per_car = 0;
		daily_revenue += per_car;
		num_of_deliveries += num_of_daily_deliveries;
	}
	budget += daily_revenue;
	cout << "Total revenue for company is " << daily_revenue << endl; 
	return true;
}
