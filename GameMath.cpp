#include <chrono>
#include <random>
#include "GameMath.h"

namespace GameMath
{
	float RandomFloat(const float begin, const float end)
	{
		unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
		static std::default_random_engine engine(seed);
		std::uniform_real_distribution<float> dist(begin, end);
		return dist(engine);
	};
}