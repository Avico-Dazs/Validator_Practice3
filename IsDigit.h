#pragma once
#include "IValidator.h"
class IsDigit :
    public IValidator
{
public:
	IsDigit();
	~IsDigit();
    // IValidator ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        std::string str = sz;
        for (char const& ch : str)
        {
            if (std::isdigit(ch) == 0)
            {
                // ”’l‚¶‚á‚È‚¢
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