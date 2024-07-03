#include <iostream>
#include <string>
using namespace std;

class Medicine
{
    protected:
    string name, formula;
    float retailPrice;
    string manufactureDate, expDate;

public:
    Medicine(string name, string formula, float retailPrice, string manufactureDate, string expDate)
        : name(name), formula(formula), retailPrice(retailPrice), manufactureDate(manufactureDate), expDate(expDate) {}

    virtual void printDetails()
    {
        cout << "Name: " << name << "\nFormula: " << formula << "\nRetail Price: $" << retailPrice
             << "\nManufacture Date: " << manufactureDate << "\nExpiry Date: " << expDate << "\n";
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setFormula(string formula)
    {
        this->formula = formula;
    }
    string getFormula()
    {
        return formula;
    }
    void setRetailPrice(float retailPrice)
    {
        this->retailPrice = retailPrice;
    }
    float getRetailPrice()
    {
        return retailPrice;
    }
    void setManufactureDate(string manufactureDate)
    {
        this->manufactureDate = manufactureDate;
    }
    string getManufactureDate()
    {
        return manufactureDate;
    }
    void setExpDate(string expDate)
    {
        this->expDate = expDate;
    }
    string getExpYear()
    {
        return expDate;
    }
    bool operator==(const Medicine &other) const
    {
        return this->expDate == other.expDate;
    }
};

class Tablet : public Medicine
{
    float sucroseLevel;

public:
    Tablet(string name, string formula, float retailPrice, string manufactureDate, string expDate, float sucroseLevel)
        : Medicine(name, formula, retailPrice, manufactureDate, expDate), sucroseLevel(sucroseLevel) {}

    void printDetails() override
    {
        Medicine::printDetails();
        cout << "Sucrose Level: " << sucroseLevel << "%\n";
    }
};

class Capsule : public Medicine
{
    float absorptionPercentage;

public:
    Capsule(string name, string formula, float retailPrice, string manufactureDate, string expDate, float absorptionPercentage)
        : Medicine(name, formula, retailPrice, manufactureDate, expDate), absorptionPercentage(absorptionPercentage) {}

    void printDetails() override
    {
        Medicine::printDetails();
        cout << "Absorption Percentage: " << absorptionPercentage << "%\n";
    }
};

class Syrup : public Medicine
{
public:
    Syrup(string name, string formula, float retailPrice, string manufactureDate, string expDate)
        : Medicine(name, formula, retailPrice, manufactureDate, expDate) {}

    void printDetails() override
    {
        Medicine::printDetails();
    }
};

class Pharmacist
{
    Medicine *medicines[10];

public:
    Pharmacist(Medicine *m[10])
    {
        for (int i = 0; i < 10; i++)
        {
            medicines[i] = m[i];
        }
    }

    void searchMedicine(const string &formula)
    {
        for (int i = 0; i < 10; i++)
        {
            if (medicines[i] && medicines[i]->getFormula() == formula)
            {
                cout << "-------------------------------------------" << endl;
                cout << "Details of medicine of formula: " << formula << endl;
                cout << "-------------------------------------------" << endl;
                medicines[i]->printDetails();
                return;
            }
        }
        cout << "No medicine found with this formula.\n";
    }
};

class Counter
{
    float revenue = 0;
    Medicine *medicines[10];

public:
    Counter(Medicine *m[10])
    {
        for (int i = 0; i < 10; i++)
        {
            medicines[i] = m[i];
        }
    }

    void searchMedicine(const string &name)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Details of medicine of name: " << name << endl;
            cout << "-------------------------------------------" << endl;
            if (medicines[i] && medicines[i]->getName() == name)
            {
                medicines[i]->printDetails();
                return;
            }
        }
        cout << "No medicine found with this name.\n";
    }

    void updateRevenue(float amount)
    {
        revenue += amount;
    }
};

int main()
{
    Medicine *meds[10] = {
        new Tablet("Aspirin", "C9H8O4", 19.99, "2021-05-12", "2024-05-12", 0.5),
        new Capsule("Tylenol", "C8H9NO2", 22.50, "2021-06-15", "2025-06-15", 80.0),
        new Syrup("Benadryl", "C17H21NO", 15.45, "2022-01-20", "2025-01-20"),
        nullptr};

    Pharmacist pharmacist(meds);
    Counter counter(meds);

    pharmacist.searchMedicine("C8H9NO2");
    cout << endl
         << endl;
    counter.searchMedicine("Aspirin");
    counter.updateRevenue(200.0);


    if (*meds[0] == *meds[2])
    {
        cout << "Medicine 1 and Medicine 3 have the same expiry date." << endl;
    }
    else
    {
        cout << "Medicine 1 and Medicine 3 do not have the same expiry date." << endl;
    }
}