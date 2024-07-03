#include <iostream>
#include <string>
using namespace std;
class Character;
class Enemy;
class player
{
protected:
    int playerId;
    string playerName;
    int health;

public:
    player() {}
    player(int playerId, string playerName) : playerId(playerId), playerName(playerName)
    {
        health = 100;
    }
    friend void attack(Character &c, Enemy &e);
    friend void playGame(Character &c, Enemy &e);
};
class Weapon
{
    string *weapons;
    int numWeapons;

public:
    Weapon() {}
    Weapon(string *_weapons, int numWeapons)
    {
        
           this->numWeapons = numWeapons;
        weapons = new string[numWeapons];
        for (int i = 0; i < numWeapons; i++)
        {
            weapons[i] = _weapons[i];
        }
    }
    void use()
    {
        cout << "Enter the weapon you want to use: " << endl;
        string chooseweapon;
        for(int i = 0; i< numWeapons; i++)
    {
        cout << i+1 << " " << weapons[i] << endl;
    }
        getline(cin, chooseweapon);
        bool found = false;
        for (int i = 0; i < 5; i++)
        {
            if (weapons[i] == chooseweapon)
            {
                found = true;
            }
        }
        if (found)
        {
            cout << "Weapon is available in your arsenal" << endl;
        }
        else
        {
            cout << "Weapon is not available in your arsenal" << endl;
            exit(0);
        }
    }
};
class Character : public player
{
    int level;
    string experience;
    int points;

public:
    Character(int playerId, string playerName) : player(playerId, playerName)
    {
        level = 1;
        points = 0;
        experience = "beginner";
    }
    void levelUp()
    {
        level += 1;
        if (experience == "beginner")
        {
            experience = "intermediate";
        }
        else if (experience == "intermediate")
        {
            experience = "advanced";
        }
        else if (experience == "advanced")
        {
            experience = "expert";
        }
    }
    friend void playGame(Character &c, Enemy &e);

    int getPlayerId()
    {
        return playerId;
    }
    string getPlayerName()
    {
        return playerName;
    }
    int getHealth()
    {
        return health;
    }
    int getpoints()
    {
        return points;
    }
    int getLevel()
    {
        return level;
    }
    string getexperience()
    {
        return experience;
    }
};
class Enemy : public player
{
    int damage;
    Weapon *weapon;

public:
    Enemy(int playerId, string playerName, int damage, Weapon *weapon) : player(playerId, playerName), weapon(weapon)
    {
        if (damage >= 0 && damage <= 10)
        {
            this->damage = damage;
        }
        else
        {
            this->damage = 10;
        }
    }
    friend void attack(Character &c, Enemy &e);
    int getPlayerId()
    {
        return playerId;
    }
    string getPlayerName()
    {
        return playerName;
    }
    int getHealth()
    {
        return health;
    }
};
void playGame(Character &c, Enemy &e)
{
    e.health -= 5;
    c.points += 10;
}
void attack(Character &c, Enemy &e)
{
    c.health -= e.damage;
    e.weapon->use();
}
int main()
{
    Character c(1, "ash");
    string weaponList[5] = {"Ak47", "MP5", "Glock18", "Desert Eagle", "Mac10"};

    Weapon weapon(weaponList, 5);
    Enemy e(2, "ayesh", 2, &weapon);

    playGame(c, e);
    c.levelUp();

    playGame(c, e);
    c.levelUp();

    playGame(c, e);
    c.levelUp();

    attack(c, e);
    cout << "Character ID: " << c.getPlayerId() << "    "
         << "Character Name: " << c.getPlayerName() << endl;
    cout << "Character points: " << c.getpoints() << endl;
    cout << "Character Level: " << c.getLevel() << endl;
    cout << "Character Health: " << c.getHealth() << endl;
    cout << "Character Experience: " << c.getexperience() << endl
         << endl;
    cout << "Enemy ID: " << e.getPlayerId() << "    "
         << "Enemy Name: " << e.getPlayerName() << endl;
    cout << "Enemy Health: " << e.getHealth();
}