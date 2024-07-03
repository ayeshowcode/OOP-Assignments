#include <iostream>
#include <cmath>
using namespace std;
const float EARTH_RADIUS_KM = 6371.0; 
class Drone
{
protected:
    float latitude, longitude, altitude, speed;

public:
    Drone(float latitude, float longitude, float altitude, float speed) : latitude(latitude), longitude(longitude), altitude(altitude), speed(speed) {}

    void adjustAltitude(float altitude)
    {
        this->altitude = altitude;
    }

    void setSpeed(float speed)
    {
        this->speed = speed;
    }
};

class Flyable
{
public:
    virtual void takeoff() = 0;

    virtual void land() = 0;

    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable
{
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable
{
    float cameraResolution, maxFlightTime;

public:
    ReconDrone(float latitude, float longitude, float altitude, float speed, float cameraResolution, float maxFlighTime)
        : Drone(latitude, longitude, altitude, speed), cameraResolution(cameraResolution), maxFlightTime(maxFlighTime) {}

    void takeoff() override
    {
        cout << "Taking off" << endl;
    }

    void land() override
    {
        cout << "Landing" << endl;
    }
    void navigateTo(float lat, float lon, float alt) override
    {
        // Calculate the distance using the Haversine formula
        float latRad1 = latitude * 3.1415 / 180.0;
        float latRad2 = lat *  3.1415  / 180.0;
        float lonRad1 = longitude *  3.1415  / 180.0;
        float lonRad2 = lon *  3.1415  / 180.0;

        float dLat = latRad2 - latRad1;
        float dLon = lonRad2 - lonRad1;

        float a = sin(dLat / 2) * sin(dLat / 2) +
                  cos(latRad1) * cos(latRad2) *
                      sin(dLon / 2) * sin(dLon / 2);
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));
        float distance = EARTH_RADIUS_KM * c;

        // Calculate the travel time
        float time = distance / speed;

        cout << "Navigating to Latitude: " << lat << " Longitude: " << lon << " Altitude: " << alt
             << " (" << distance << " km, Estimated time: " << time << " hours)" << endl;

        // Update drone's position
        latitude = lat;
        longitude = lon;
        altitude = alt;
    }

    void scanArea(float radius) override
    {
        cout << "Scanning area within " << radius << " meters radius." << endl;
        int objectCount = rand() % 10; // Simulate detecting 0 to 9 objects
        for (int i = 0; i < objectCount; i++)
        {
            float randomLat = latitude + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX) - 0.5) * 0.1;
            float randomLon = longitude + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX) - 0.5) * 0.1;
            cout << "Detected object at (" << randomLat << ", " << randomLon << ")" << endl;
        }
    }
};

int main()
{
    ReconDrone drone(0, 0, 100, 50, 4, 8);
    drone.takeoff();
    drone.navigateTo(1, 1, 150);
    drone.scanArea(500);
    drone.land();
}