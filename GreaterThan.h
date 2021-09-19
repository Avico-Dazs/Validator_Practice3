#pragma once
#include <memory>
#include "IValidator.h"
class GreaterThan :
    public IValidator
{
public:
    // IValidator ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        const int num = atoi(sz);
        if (num < m_num)
        {
            result.SetMessage("less than");
            return false;
        }
        return true;
    }

    GreaterThan(const GreaterThan& obj)
    {
        printf("Copy GreaderThan\n");
        m_num = obj.m_num;
    }

    GreaterThan(int n) : m_num(n)
    {
        printf("Create GreaderThan\n");
    };

    ~GreaterThan()
    {
        printf("Delete GreaterThan\n");
    };

// Attributes
private:
    int m_num;
};

