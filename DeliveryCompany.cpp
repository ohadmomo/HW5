#include"DeliveryCompany.h"
using namespace std;
DeliveryCompany::DeliveryCompany(int money) 
	: next_to_deliver(NULL), pdvl(NULL), num_of_deliveries(0) {
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
	delete[] pdvl;
}

bool DeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	if (vehicle == NULL) {
		return false;
	}
	if (/*this->*/getType() != 0 && /*this->*/getType() != vehicle->getType()) return false;
	if (/*this->*/getType() == 1)
	{
		
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
	
	return pdvl->checkIfExists(vehicle);
	/*int i = 0;
	DeliveryVehicle* head_of_queue = (pdvl->front);
	for (i = 0; i < pdvl->size(); i++) //check if size is correct
		//if (!strcmp(head_of_queue[i]->getID(), vehicle->getID()))return true;
	return false;*/
}
bool DeliveryCompany::receiveParcel(Parcel* parcel) {
	//DeliveryVehicle** head_of_queue = (DeliveryVehicle**)(pdvl->front());
	if (parcel == NULL) return false;
	if (pdvl->size() == 0) {
		delete parcel;
		return false;
	}
	int next_to_deliver_index = 0;
	if (next_to_deliver == NULL) 
		next_to_deliver = pdvl->getElement(0);
	else
	{
		next_to_deliver_index = getIndex(next_to_deliver);
		if (next_to_deliver_index < 0) return false;
	}
	int i = 0;
	//DeliveryVehicle** car_queue = (DeliveryVehicle**)(pdvl->front());
	for (i = next_to_deliver_index; i < pdvl->size(); i++)
	{
		if ((pdvl->getElement(i))->addParcel(parcel) == false)continue;//check if there is a case for parcel with sam id
		else {
			if (pdvl->size() - 1 == i)
				next_to_deliver = pdvl->getElement(0); /*car_queue[0];*/
			else
				next_to_deliver = pdvl->getElement(i + 1);
			return true;
		}
		for (i = 0; i < next_to_deliver_index; i++) {
			if ((pdvl->getElement(i))->addParcel(parcel) == false)continue;
			else {
				next_to_deliver = pdvl->getElement(i+1);
				return true;
			}
		}
	}
	delete parcel;
	return false;
}

int DeliveryCompany::getType() { return all; }

void DeliveryCompany::displayNumberOfDeliveries() {
	cout << "Till now company has delivered " << num_of_deliveries << " parcels" << endl;
}

void DeliveryCompany::displayFunds() {
	cout << "Company balance is now " << budget << endl;
}
int DeliveryCompany::getIndex(DeliveryVehicle* vehicle) const {
	int i = 0;
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
		daily_revenue += pdvl->getElement(i)->performDeliveryDay(&num_of_daily_deliveries);
		num_of_deliveries += num_of_daily_deliveries;
	}
	budget += daily_revenue;
	cout << "Total revenue for company is " << daily_revenue << endl; 
	cout << "Company balance is now " << budget << endl; 
}