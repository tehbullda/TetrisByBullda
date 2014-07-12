#include <random>

namespace Randomizer {

	int GetRandomInt(int min = 0, int max = INT_MAX);

	double GetRandomDouble(double min, double max);

	double GetNormalDistribution(double mean, double deviation);
}