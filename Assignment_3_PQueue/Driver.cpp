
#include <iostream>

#include"PhoneNumber.h"
#include"Call.h"

int main()
{
	PhoneNumber numOne;
	numOne.set_phone_number("01783511730");
	numOne.set_operator_name("GrameenPhone");

	Call call5("01738539045", "T", spouse);
	call5.set_call_duration(50.00);                

	Call call6("01738539045", "S", Friend);
	call6.set_call_duration(60.00);

	Call call7("01738539046", "R", Child);
	call7.set_call_duration(60.00);

	Call call8("01738538455", "Q", spouse);
	call8.set_call_duration(1200.2);

	Call call9("01738538466", "P", Significant);
	call9.set_call_duration(15.15);

	Call call10("01738578980", "O", Friend);
	call10.set_call_duration(120.2);

	Call call11("01738539077", "N", Subordinate);
	call11.set_call_duration(10.10);

	numOne.insert_call(call5);
	numOne.insert_call(call6);
	numOne.insert_call(call7);
	numOne.insert_call(call8);
	numOne.insert_call(call9);
	numOne.insert_call(call10);
	numOne.insert_call(call11);
	
	numOne.print_call_list();
}

