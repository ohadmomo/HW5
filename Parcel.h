#ifndef PARCEL_H_
#define PARCEL_H_

class Parcel {
public:
	//c'tor	
	Parcel(const char* ID, int dest);
	char* getID() const;
	int getDest() const;
	//d'tor
	~Parcel();

private:
	char* ID_;
	int dest_;
};

#endif /* PARCEL_H_ */
