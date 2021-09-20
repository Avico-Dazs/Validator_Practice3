#pragma once
#include "IValidator.h"
class ExcludingChars :
    public IValidator
{
private:
    char m_chars[128];
public:
    ExcludingChars(const char* sz) 
    {
        memset(m_chars, 0, 128);
        memcpy_s(m_chars, 128, sz, 128);
    };

    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        std::string str = sz;
        for (auto ch : str)
        {
            bool find = false;
            for (auto c : m_chars)
            {
                if (c == 0) break;
                if (ch == c) return false;
            }
        }
        return true;
    }
};

