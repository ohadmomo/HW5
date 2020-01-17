#include"ProfessionalDeliveryCompany.h"
int ProfessionalDeliveryCompany::getType() const { return professional; }
ProfessionalDeliveryCompany::ProfessionalDeliveryCompany(int money): 
	DeliveryCompany(money){}
