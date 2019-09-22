#include <Windows.h>
#include <iostream>



#define HealthPTR 0xF8
#define HeightPTR 0x5C
#define PrimAmmoPTR 0x150
#define SecAmmoPTR 0x13C
#define PlrLocPTR 0x38


namespace PlrValues {
	int HealthVal;
	int PrimAmmoVal;
	int SecAmmoVal;
	int HeightVal;
	
}
int base(DWORD addr) {
	return addr + (DWORD)GetModuleHandleA(NULL);
}
DWORD* plrbaseaddr = (DWORD*)(base(0x10F4F4));
static int Health = *(int*)(*plrbaseaddr + HealthPTR);
static int PrimAmmo = *(int*)(*plrbaseaddr + PrimAmmoPTR);
static int SecAmmo = *(int*)(*plrbaseaddr + SecAmmoPTR);
static int Height = *(float*)(*plrbaseaddr + HeightPTR);
void ConsoleCrap() {
	printf("Current Values: ");
	printf("\nHealth: %d", Health);
	printf("\nPrimary Ammo: %d", PrimAmmo);
	printf("\nSecondary Ammo: %d", SecAmmo);
	printf("\nHeight: %d", Height);
	printf("\nEnter New Values: \n");
	/////////////////////////////////
	std::cout << "Health:";
	std::cin >> PlrValues::HealthVal;
	*(int*)(*plrbaseaddr + HealthPTR) = PlrValues::HealthVal;
	/////////////////////////////////

	/////////////////////////////////
	std::cout << "Primary Ammo:";
	std::cin >> PlrValues::PrimAmmoVal;
	*(int*)(*plrbaseaddr + PrimAmmoPTR) = PlrValues::PrimAmmoVal;
	/////////////////////////////////

	/////////////////////////////////
	std::cout << "Secondary Ammo:";
	std::cin >> PlrValues::SecAmmoVal;
	*(int*)(*plrbaseaddr + SecAmmoPTR) = PlrValues::SecAmmoVal;
	/////////////////////////////////

	/////////////////////////////////
	std::cout << "Height:";
	std::cin >> PlrValues::HeightVal;
	*(float*)(*plrbaseaddr + HeightPTR) = PlrValues::HeightVal;
	/////////////////////////////////
	
}
int Main() {
	AllocConsole();
	SetConsoleTitleA("Assault Cube Cheat");
	FILE* F;
	freopen_s(&F, "CONOUT$", "w", stdout);
	freopen_s(&F,"CONIN$", "r", stdin);
    
	
	ConsoleCrap();
	while (true)
	{
		do
		{
			system("cls");
			ConsoleCrap();
		} while (std::cin.get() != '\n');
	}
	
	
	
		
	

	
	
	
	
	return 0;
}





BOOL APIENTRY DllMain(HMODULE Module, DWORD Reason, void* Reserved)
{
	if (Reason == 1)
	{

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);

	}
	return TRUE;
}