#pragma once
#include "IValidator.h"
class IsDigit :
    public IValidator
{
public:
	IsDigit();
	~IsDigit();
    // IValidator を介して継承されました
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        std::string str = sz;
        for (char const& ch : str)
        {
            if (std::isdigit(ch) == 0)
            {
                // 数値じゃない
                result.SetMessage("not number");
                return false;
            }
        }
        return true;
    }


private:

};

IsDigit::IsDigit()
{
}

IsDigit::~IsDigit()
{
}