#include <iostream>
using namespace std;
class DarazPersonData
{
    string lastName, firstName, address, city, state, zip, phone;
    public:
    void setLastName(string lastName)
    {
        this->lastName=lastName;
    }
    string getLastName()
    {
        return lastName;
    }
    void setFirstName(string firstName)
    {
        this->firstName=firstName;
    }
    string getFirstName()
    {
        return firstName;
    }
    void setAddress(string address)
    {
        this->address=address;
    }
    string getAddress()
    {
        return address;
    }
    void setCity(string city)
    {
        this->city=city;
    }
    string getCity()
    {
        return city;
    }
    void setState(string state)
    {
        this->state=state;
    }
    string getState()
    {
        return state;
    }
    void setZip(string zip)
    {
        this->zip=zip;
    }
    string getZip()
    {
        return zip;
    }
    void setPhone(string phone)
    {
this->phone=phone;
    }
    string getPhone()
    {
        return phone;
    }


    

};
class DarazCustomerData :  public DarazPersonData
{
    int customerNo;
    int loyaltyPoints;
    public:
    DarazCustomerData(): customerNo(1), loyaltyPoints(0){}
    void setCustomerNo(int customerNo)
    {
        this->customerNo=customerNo;
    }
    int getCustomerNo()
    {
        return customerNo;
    }
    void setLoyaltyPoints(int loyaltyPoints)
    {
        this->loyaltyPoints=loyaltyPoints;
    }
    int getLoyalPoints()
    {
        return loyaltyPoints;
    }
};
class DarazLoyaltyProgram
{
    public:
    void addLoyaltyPoints(DarazCustomerData &customer, int points)
    {
        if (points>0)
        customer.setLoyaltyPoints(customer.getLoyalPoints()+points);
        else cout << "Cannot add negative points" << endl;
    }
    void redeemLoyaltyPoints(DarazCustomerData &customer, int points)
    {
        if(points>0 && points <= customer.getLoyalPoints())
        {
            customer.setLoyaltyPoints(customer.getLoyalPoints()-points);
        }
        else cout << "Invalid redemption: The points are negative or the customer has not enough points to be redeemed" << endl;
    }
    void display(DarazCustomerData &customer)
    {
        cout << "First Name: " << customer.getFirstName() << "    " << "Last Name: " << customer.getLastName()<< endl;
        cout << "Address: " << customer.getAddress() << endl;
        cout << "City: " << customer.getCity() << "    " << "State: " << customer.getState() << endl;
        cout << "Zip: " << customer.getZip()<< endl;
        cout << "Phone: " << customer.getPhone() << endl;
        cout << "Customer: " << customer.getCustomerNo() << endl;
        cout << "Customer Loyal Points: " << customer.getLoyalPoints() << endl;
    }
};
int main()
{
    DarazCustomerData dcd;
    DarazLoyaltyProgram dlp;
    dcd.setFirstName("Ayesh");
    dcd.setLastName("Qureshi");
    dcd.setPhone("0900078601");
    dcd.setAddress("mera");
    dcd.setCity("thatta");
    dcd.setState("sindh");
    dcd.setZip("1441");

    dlp.addLoyaltyPoints(dcd, 100);
    dlp.redeemLoyaltyPoints(dcd, 30);
    dlp.display(dcd);
}