#ifndef IPADDRESS_H_
#define IPADDRESS_H_

class IPAddress {
public:
	IPAddress();
	void Menu();
	virtual ~IPAddress();
protected:
	void PingIPAddress();
	void PingIPAddressManually();
	void IPWebsites(int &i);
	void PingResult();

};

#endif
