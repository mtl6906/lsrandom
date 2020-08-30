#include "ls/Random.h"
#include "string"
#include "iostream"

using ls::Random;
using namespace std;

int main()
{
	Random random;
//	产生长度为5的由大小写字母组成的字符串
	cout << random.RandLetter(5) << endl;
	return 0;
}
