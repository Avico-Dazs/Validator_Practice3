#pragma once
#include "IValidator.h"
#include "GreaterThan.h"
#include <vector>
#include <iostream>

class AndValids :
    public IValidator
{
// Overrides
public:
    // IValidator を介して継承されました
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        for (auto& v : m_validators)
        {
            if(!v->Eval(sz, result)) return false;
        }
        return true;
    }
// Constructor/Destructor
public:
    AndValids()
    {
        std::cout << "Create And\n";
    }

    AndValids(const AndValids & obj)
    {
        std::cout << "Copy And\n";
        // ユニークポインタの所有権を受け取る。
        size_t size = obj.m_validators.size();
        for (size_t i = 0; i < size; i++)
        {
            m_validators.push_back(obj.m_validators[i]);
        }
    }

    virtual ~AndValids()
    {
        m_validators.clear();
        printf("Delete And\n");
    }

// Implements
public:
    template<class T>
    void Add(const T& e)
    {
        auto p = new T(e);
        auto u = std::shared_ptr<IValidator>(p);
        m_validators.push_back(u);
    }
// Attributes
private:
    std::vector<std::shared_ptr<IValidator>> m_validators;
};

