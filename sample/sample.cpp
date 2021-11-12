#include "ls/Random.h"
#include "string"
#include "iostream"

using ls::Random;
using namespace std;

int main()
{
	Random random;
//	产生长度为5的由大小写字母组成的字符串
	cout << random.randLetter(5) << endl;

	cout << (int)(unsigned char)random.seed() << endl;
	return 0;
}
