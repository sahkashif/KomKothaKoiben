#include <iostream>
#include"PhoneNumber.h"
#include"Call.h"

using namespace std;


int main()
{
	PhoneNumber numOne, numTwo, numThree, numFour, numFive, numSix, numSeven, numEight, numNine, numTen, numEleven, numTwelve, numTherteen, numFourteen, numFifteen;

	numOne.set_phone_number("01783511730");
	numOne.set_operator_name("GrameenPhone");

	numTwo.set_phone_number("01715583543");
	numTwo.set_operator_name("GrameenPhone");

	numThree.set_phone_number("01998021382");
	numThree.set_operator_name("BanglaLink");

	Call call("01738539000", "Z", spouse);
	call.set_call_duration(44.44);

	Call call1("01738539001", "Y", Child);
	call1.set_call_duration(200.02);

	Call call2("01738539002", "Z", Parent);
	call2.set_call_duration(55.59);

	Call call3("01738539003", "V", spouse);
	call3.set_call_duration(2400.00);

	Call call4("01738539004", "U", Sibling);
	call4.set_call_duration(56.71);

	Call call5("01738539045", "T", spouse);
	call5.set_call_duration(50.00);

	Call call6("01738539045", "S", Friend);
	call6.set_call_duration(60.00);

	Call call7("01738539046", "R", Child);
	call7.set_call_duration(60.00);

	Call call8("01738538455", "Q", Cousins);
	call8.set_call_duration(1200.2);

	/*numOne.insert_call(call);
	numOne.insert_call(call1);
	numOne.insert_call(call2);
	numOne.insert_call(call3);
	numOne.insert_call(call4);*/
	numOne.insert_call(call5);
	numOne.insert_call(call7);
	numOne.insert_call(call8);
	
	numOne.print_call_list();
}
