#include <stdio.h>
#include <string.h>
struct Vehicle 
{
	int engineCapacity;
	int numGears;
	char fuelType[20];
};

int main()
{

  struct Vehicle v;

      v.engineCapacity = 3000;
      v.numGears = 5;
      strcpy (v.fuelType, "DEISEL");
printf ("Engine Capacity = %d\n", v.engineCapacity);
printf ("No of Gers = %d\n", v.numGears);
printf ("Fuel Type = %s\n", v.fuelType);
	return 0;
}
