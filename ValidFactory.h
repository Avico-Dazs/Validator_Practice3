#pragma once
#include "AndValids.h"
#include "OrValids.h"

class ValidFactory
{
public:
	IValidator* Create(int checkId, uint16_t wparam, uint32_t lparam)
	{
		IValidator* validator = CreateValid(checkId, wparam, lparam);
		return validator;
	}
	ValidFactory(); // 単体では使用できない。
	virtual ~ValidFactory();
private:
	virtual IValidator* CreateValid(int checkId, uint16_t wparam, uint32_t lparam) = 0;

};

ValidFactory::ValidFactory()
{
}

ValidFactory::~ValidFactory()
{
}