#include "ls/Random.h"
#include "cmath"
#include "cstdio"

using std::string;
using std::queue;
using std::mutex;
using std::lock_guard;

namespace ls
{
	Random::Random(int buffersize) : buffersize(buffersize)
	{
	
	}
	char Random::seed()
	{
		if(!buffer.empty())
		{
			char ch = buffer.front();
			buffer.pop();
			return ch;
		}
		char tmp[buffersize];
		FILE *fp = fopen("/dev/urandom", "r");
		fread(tmp, 1, sizeof(tmp), fp);
		fclose(fp);
		for(int i=1;i<buffersize;++i)
			buffer.push(tmp[i]);
		return tmp[0];
	}
	string Random::randLetter(int n)
	{
		string result(n, '\0');
		{
			lock_guard<mutex> random_lock(random_mutex);
			for(int i=0;i<result.size();++i)
				result[i] = seed();
		}
		for(int i=0;i<result.size();++i)
		{
			char sign = sign(result[i]);
			result[i] = result[i] * sign % 26 + (sign > 0 ? 'A' : 'a');
		}
		return result;
	}
	char Random::sign(char number)
	{
		return number > 0 ? 1 : -1;
	}	
}
