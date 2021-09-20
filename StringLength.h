#pragma once
#include "IValidator.h"
class StringLength :
    public IValidator
{
// Overrides
public:
    // IValidator ‚ð‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        std::string str = sz;
        return (size_t)m_len >= str.length();
    }
// Constructor
public:
    StringLength(int len) : m_len(len) {};
// Attributes
private:
    int m_len;
};

