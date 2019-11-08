#pragma once

#include "sampleGenerator.h"
#include "random.h"

class CSampleGeneratorStratified : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
		int k = 0;
		for(int i = 0; i < sqrt(n); i++){
			for(int j = 0; j < sqrt(n); j++){
				float ei = DirectGraphicalModels::random::U<float>();
				float ej = DirectGraphicalModels::random::U<float>();
				u[k] = (i + ei) / sqrt(n);
				v[k] = (j + ej) / sqrt(n);
				weight[k] = 1.0f/n;
				k++;
			}
		}
	}
};
