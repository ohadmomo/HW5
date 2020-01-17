#define _CRT_SECURE_NO_WARNINGS
#include "Parcel.h"
#include <string.h>

Parcel::Parcel(const char* ID, int dest)
{
	// Memory allocation!!
	char* new_copy = new char[strlen(ID) + 1];
	strncpy(new_copy, ID, (strlen(ID) + 1));
	ID_ = new_copy;
	dest_ = dest;
}

int Parcel::getDest() const
{
	return dest_;
}

char* Parcel::getID() const
{
	//return the pointer to ID!!
	return ID_;
}

Parcel::~Parcel()
{
	delete[] ID_;
}

