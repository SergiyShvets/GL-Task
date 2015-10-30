#ifndef IPADDRESS_H_
#define IPADDRESS_H_

class IPAddress {
public:
	IPAddress();

	void Menu();
	void PingIPAddress();
	void PingIPAddressManually();
	void IPWebsites(int &i);

	virtual ~IPAddress();
};

#endif
