#include"FastDeliveryCompany.h"
int FastDeliveryCompany::getType() const { return fast; }
FastDeliveryCompany::FastDeliveryCompany(int money):DeliveryCompany(money) {}
FastDeliveryCompany::~FastDeliveryCompany() {}