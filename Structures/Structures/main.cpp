#include <iostream>

/*--------------------------------*/
void PointerTest()
{
	int a = 7, b = 0;
	int* pa = nullptr;
	int* pb = nullptr;

	pa = &a;
	pb = &b;
	b = *pa + 2;

	std::cout << "size of int : " << sizeof(int) << std::endl
		<< "size of pointer : " << sizeof(int*) << std::endl;

	std::cout << std::hex;
	std::cout << a << " " << b << std::endl
		<< &a << " " << &b << std::endl
		<< *pa << " " << * pb << std::endl
		<< pa << " " << pb << std::endl
		<< &pa << " " << &pb << std::endl;


	std::cout << "\n&a  : " << &a << "\n&b  : " << &b << "\n&pa : " << &pa << "\n&pb : " << &pb;
	std::cout << std::dec;
}

/*--------------------------------*/
void FunEnum() {

	enum class Days: unsigned int { Monday = 0, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday, UKN = 99 };
	std::cout << "Monday is : " << (int)Days::Monday << " whereas Saturday is : " << (int)Days::Saturday;
}

/*--------------------------------*/
struct Captor
{
	enum class TypeCaptor { ACC, ANE, AAA, TEM };
	TypeCaptor type;
	double value;
};

void initMesureCaptor(Captor* pCaptorToInit)
{
	pCaptorToInit->value = 0;
}

void CaptorExo()
{
	Captor myCaptor;
	myCaptor.type = Captor::TypeCaptor::TEM;

	std::cout << "Init Cport of type id #" << (int)myCaptor.type << std::endl;
	initMesureCaptor(&myCaptor);
	std::cout << "Captor value : " << myCaptor.value << std::endl;
	myCaptor.value = 22.65;
	std::cout << "Captor updated value : " << myCaptor.value << std::endl;

}
/*--------------------------------*/
/*
* i = 6666
6666
6666; 1a0a

i = 666666
666666
11306 ; 2c2a
(diff 'cause a short is : 32,767 (2^16)/2)
*/
void shortPointer(short* v)
{
	std::cout << *v << " ; " << std::hex << *v << std::dec << std::endl;
}

int Caster()
{
	int i = 666666;
	std::cout << i << std::endl;

	short s = static_cast<short>(i);
	shortPointer(&s);
	return 0;
}
/*--------------------------------*/
#include <sstream>
/*
In hex : 40200000
64 T
32 @
0
0
Transfering 4 bytes : 0 0 32 64
*/

int HexToDec(char hex)
{
	switch (hex)
	{
		case '0': return 0; 
		case '1': return 1; 
		case '2': return 2; 
		case '3': return 3; 
		case '4': return 4; 
		case '5': return 5; 
		case '6': return 6; 
		case '7': return 7; 
		case '8': return 8; 
		case '9': return 9; 
		case 'A': return 10; 
		case 'B': return 11; 
		case 'C': return 12; 
		case 'D': return 13; 
		case 'E': return 14; 
		case 'F': return 15; 
		
	}
}

void ExtractByte(float data, unsigned char* bytes)
{
	int* p = reinterpret_cast<int*>(&data);
	int i = *p;
	std::stringstream hex;
	hex << std::hex << i;
	std::cout << "In hex : " << hex.str() << std::endl;

	for (int i = 0; i < 4; i++)
	{
		int byte = HexToDec(hex.str().at(2 * i)) * 16 + HexToDec(hex.str().at(i * 2 +1));
		bytes[3-i] = static_cast<char>(byte);
		std::cout << byte << " " << bytes[4 - i] << std::endl;
	}

	//std::cout << "\n" << HexToDec(hex.str().at(0)) * 16 << " " << HexToDec(hex.str().at(1)) << "\n";
}

void BTS2009()
{
	float dataValue = 2.5;
	std::cout << "Enter a float : ";
	std::cin >> dataValue;

	unsigned char bytesToSend[4];

	ExtractByte(dataValue, bytesToSend);

	std::cout << "Transfering 4 bytes : ";
	for (int i = 0; i < 4; i++)
	{
		std::cout << (int)bytesToSend[i] << " ";
	}
}


/*--------------------------------*/
int main()
{
	bool running = true;
	int selection = 0;

	char input;

	while (running)
	{
		std::cout << "\n \t -----------Excercices Menu :------------- " << std::endl << std::endl
			<< "[n] - Quitter" << std::endl
			<< "1 - Pointers" << std::endl
			<< "2 - Enums" << std::endl
			<< "3 - Captor" << std::endl
			<< "4 - Caster" << std::endl
			<< "5 - BTS 2009" << std::endl
			<< std::endl;
		std::cin >> input;
		//system("cls");
		switch (input)
		{
			case 'n': running = false; break;
			case '1': PointerTest(); break;
			case '2': FunEnum();  break;
			case '3': CaptorExo();  break;
			case '4': Caster();  break;
			case '5': BTS2009();  break;
		}
	}

	return 0;
}
