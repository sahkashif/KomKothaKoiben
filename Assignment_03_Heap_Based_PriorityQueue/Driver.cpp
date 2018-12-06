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

	numOne.insert_call(call);
	numOne.insert_call(call1);
	numOne.insert_call(call2);
	numOne.insert_call(call3);

	numOne.print_call_list();
}
