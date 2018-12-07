#include "PhoneNumber.h"

using namespace std;

PhoneNumber::PhoneNumber()
{
	phoneNumber = "";
	operatorName = "";
	item = new Call[100];
	length = 0;
}


PhoneNumber::PhoneNumber(string phNumber, string opName)
{
	if (phNumber.size() == 11 && opName == "KomKothaKoiben" || opName == "GrameenPhone" || opName == "Robi" || opName == "Teletalk" || opName == "BanglaLink")
	{
		phoneNumber = phNumber;
		operatorName = opName;
		length = 0;
	}
	else
	{
		throw WrongNumber();
	}
}

PhoneNumber::~PhoneNumber()
{
}

void PhoneNumber::set_phone_number(string phoneNum)
{
	if (phoneNum.size() == 11)
	{
		phoneNumber = phoneNum;
	}
	else
		throw WrongNumber();


}

void PhoneNumber::set_operator_name(string opName)
{
	if (opName == "KomKothaKoiben" || opName == "GrameenPhone" || opName == "Robi" || opName == "Teletalk" || opName == "BanglaLink")
	{
		operatorName = opName;
	}
	else
	{
		cout << "Operator name is not Correct!!";
	}

}

string PhoneNumber::get_phone_number()
{
	return phoneNumber;
}

string PhoneNumber::get_operator_name()
{
	return operatorName;
}

/*void PhoneNumber::print_phone_number()
{
	cout << endl;
	cout << "Phone Number : \t" << phoneNumber << endl;
	cout << "Operator Name:\t" << operatorName << endl;
}*/



bool PhoneNumber::operator==(const PhoneNumber & rhs)
{
	if (this->phoneNumber == rhs.phoneNumber)
		return true;
	else
		return false;
}

bool PhoneNumber::operator<(const PhoneNumber & rhs)
{
	if (this->phoneNumber < rhs.phoneNumber)
		return true;
	else
		return false;
}

bool PhoneNumber::operator>(const PhoneNumber & rhs)
{
	if (this->phoneNumber > rhs.phoneNumber)
		return true;
	else
		return false;
}

bool PhoneNumber::reheap_up(int root, int bottom)
{
	if (item != nullptr)
	{
		int parent;
		if (bottom > root)
		{
			parent = (bottom / 2);
			if (item[parent].get_relation_type() > item[bottom].get_relation_type())
			{
				swap(item[parent], item[bottom]);

				reheap_up(root, parent);
				cout << "end of reheap\n";
			}
		}
		return true;
	}
	
}

void PhoneNumber::reheap_down(int root, int bottom)
{
	if (item != nullptr)
	{
		int minChild;
		int leftChild = 2 * root + 1;
		int rightChild = 2 * root + 2;
		if (leftChild <= bottom)
		{
			minChild = leftChild;
			if (rightChild <= bottom)
			{
				if (item[rightChild].get_relation_type() <= item[minChild].get_relation_type())
				{
					minChild = rightChild;
				}
			}
			


			if (item[root].get_relation_type() >= item[minChild].get_relation_type())
			{

				swap(item[root], item[minChild]);
				reheap_down(minChild, bottom);
			}
		}
	}
	

}


void PhoneNumber::swap(Call& first, Call& second)
{
	Call temp;
	temp = first;
	first = second;
	second = temp;
	//cout << "root:";
	//first.print_call();
	//cout << "bottom:";
	//second.print_call();
	//cout << "swapped\n";
	//cout << "\n";
	//cout << "\n";
}

void PhoneNumber::insert_call(Call newCall)
{
	length++;
	item[length - 1] = newCall;
	reheap_up(0, length - 1);
}

bool PhoneNumber::call_list_is_empty()
{
	return length==0;
}

Call PhoneNumber::get_call()
{
	return item[0];
}

void PhoneNumber::dequeue_call()
{
	item[0] = item[length - 1];
	length--;
	reheap_down(0, length - 1);
}

void PhoneNumber::print_call_list()
{
	Call tempCallList[100];
	Call tempCallList1[100];
	for (int index = 0; index < length; index++)
	{
		tempCallList[index] = item[index];
	}
	
	int tempLength = length;
	int index = 0;
	while (tempLength != 0)
	{
		
		tempCallList[0].print_call();
		swap(tempCallList[0], tempCallList[tempLength - 1]);
		tempLength--;
		reheap_down(0, tempLength - 1);

	}

	
}



ostream & operator<<(ostream & os, const PhoneNumber & phoneNumber)
{
	os << endl;
	os << "Phone Number : \t" << phoneNumber.phoneNumber << endl;
	os << "Operator Name:\t" << phoneNumber.operatorName << endl;

	return os;
}

