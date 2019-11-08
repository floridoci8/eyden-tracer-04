#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorRegular : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
		int k = 0;
		for (int i = 0; i < sqrt(n); i++){
			for (int j = 0; j < sqrt(n); j++){
				u[k] = (i + 0.5f)/sqrt(n);
				v[k] = (j + 0.5f)/sqrt(n);
				weight[k] = 1.0f/n;
				k++;
			}
		}
	}
};
