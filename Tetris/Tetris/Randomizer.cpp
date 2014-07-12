#include "stdafx.h"
#include "Randomizer.h"

namespace Randomizer {
	std::random_device rd;
	std::mt19937 engine(rd());

	int Randomizer::GetRandomInt(int min, int max) {
		int tmpmin = min < max ? min : max;
		int tmpmax = min < max ? max : min;

		std::uniform_int_distribution<int> distr(tmpmin, tmpmax);
		return distr(Randomizer::engine);
	}

	double Randomizer::GetRandomDouble(double min, double max) {
		double tmpmin = min < max ? min : max;
		double tmpmax = min < max ? max : min;

		std::uniform_real_distribution<double> distr(tmpmin, tmpmax);
		return distr(Randomizer::engine);
	}

	double Randomizer::GetNormalDistribution(double mean, double deviation) {
		std::normal_distribution<double> distr(mean, deviation);
		return distr(Randomizer::engine);
	}
}