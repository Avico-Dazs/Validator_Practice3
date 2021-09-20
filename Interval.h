#pragma once
#include "IValidator.h"

class Interval : public IValidator
{
// Constructor/Destructor
public:
	Interval(int max, int min, bool allowEqual = true) : 
		m_max(max), m_min(min), m_allowEqual(allowEqual){}
// Implements
public:
	// IValidator を介して継承されました
	virtual bool Eval(const char* sz, ValidationResult& result) override
	{
		const int num = atoi(sz);
		bool b;
		if (m_allowEqual)
			b = (m_max >= num && num >= m_min);
		else
			b = (m_max > num && num > m_min);

		if (!b)
		{
			// 失敗理由をresultにセット
		}

		return b;
	}
// Attributes
private:
	int m_max;
	int m_min;
	bool m_allowEqual;
};