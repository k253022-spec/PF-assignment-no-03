#include<stdio.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets)
{
    if(fuel <= 0)
    {
        printf("Fuel exhausted. Mission failed\n");
        return;
    }

    if(planet > totalPlanets)
    {
        printf("All planets visited successfully\n");
        return;
    }

    fuel = fuel - consumption;

    if(planet % 2 == 0)
    {
        fuel = fuel + recharge;
    }

    if(planet % 4 == 0)
    {
        fuel = fuel + solarBonus;
        printf("Solar recharge activated on Planet %d\n", planet);
    }

    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    calculateFuel(fuel, consumption, recharge, solarBonus, planet + 1, totalPlanets);
}

int main()
{
    int fuel = 100;
    int consumption = 20;
    int recharge = 10;
    int solarBonus = 15;
    int totalPlanets = 6;

    printf("Spacecraft Fuel Tracking\n");
    printf("-------------------------\n");

    calculateFuel(fuel, consumption, recharge, solarBonus, 1, totalPlanets);

    return 0;
}