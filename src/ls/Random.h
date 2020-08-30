#ifndef LS_RANDOM_H
#define LS_RANDOM_H

#include "string"
#include "queue"
#include "mutex"

namespace ls
{
	class Random
	{
		std::queue<char> buffer;
		int buffersize;
		std::mutex random_mutex;
		private:
			char Sign(char number);
		public:
			Random(int buffersize = 128);
			char Seed();
			std::string RandLetter(int n);
	};
}

#endif
