#include <iostream>
using namespace std;
class SecurityTool
{
protected:
    string securityLevel;
    float cost;
    int numDevices;

public:
    SecurityTool(string securityLevel, float cost, int numDevices) : numDevices(numDevices)
    {
        if (securityLevel != "high" && securityLevel != "low" && securityLevel != "medium" && cost <= 0)
        {

            cout << "Invalid Input" << endl;

        }
        else
        {
            this->securityLevel = securityLevel;
            this->cost = cost;
        }
        if (numDevices > 10)
        {
            cout << "Max devices can only be 10" << endl;
            numDevices = 10;
        }
    }
   virtual void performScan()
    {
        cout << "Generic Security Scan" << endl;
    }
};
class FirewallTool : public SecurityTool
{
    int *ports;
    string *protocols;

public:
    FirewallTool(string securityLevel, float cost, int numDevices) : SecurityTool(securityLevel, cost, numDevices)
    {
        ports = new int[23];
        protocols = new string[6];
    }
    void generateList()
    {
        for (int i = 0; i < 23; i++)
        {
            ports[i] = i + 2;
        }
    }
    void protocolList()
    {
        protocols[0] = "HTTPS";
        protocols[1] = "FTP";
        protocols[2] = "UDP";
        protocols[3] = "ICMP";
        protocols[4] = "SSH";
        protocols[5] = "SNMP";
    }
    void performScan()
    {
        if (securityLevel == "high")
        {
            cout << "Traffic from the port and protocol list is allowed" << endl;
            for (int i = 0; i < 23; i++)
            {
                cout << ports[i] << endl;
            }
            cout << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << protocols[i] << endl;
            }
        }
        else if (securityLevel == "medium")
        {
            cout << "Traffic from the port and protocol list is allowed along with the next two ports" << endl;
            for (int i = 0; i < 23; i++)
            {
                cout << ports[i] << endl;
            }
            cout << ports[22] + 1 << endl;
            cout << ports[22] + 2 << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << protocols[i] << endl;
            }
        }
        else if (securityLevel == "low")
        {
            cout << "Traffic from the port and protocol list is allowed along with the next 5 ports and from TCP and DNS protocol" << endl;
            cout <<"PORTS:" << endl;
            for (int i = 0; i < 23; i++)
            
                cout << ports[i] << "\t";
            
            for (int i = 0; i < 5; i++)
            {
                cout << ports[22] + i + 1 << "\t";
            }
            cout << endl << endl;
            cout << "PROTOCOLS" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << protocols[i] << endl;
            }
            cout << "TCP" << endl
                 << "DNS" << endl;
        }
    }
};

int main()
{
    FirewallTool F("low", 13.2, 4);
    F.generateList();
    F.protocolList();
    F.performScan();
}