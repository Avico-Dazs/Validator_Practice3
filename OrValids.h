#pragma once
#include "IValidator.h"
#include <vector>
#include <memory>

class OrValids : 
	public IValidator
{
// Constructor/Destructor
public:
    OrValids() {};
    virtual ~OrValids() {};
    OrValids(const OrValids& obj)
    {
        // ユニークポインタの所有権を受け取る。
        size_t size = obj.m_validators.size();
        for (size_t i = 0; i < size; i++)
        {
            m_validators.push_back(obj.m_validators[i]);
        }
    }
// Overrides
public:
    // IValidator を介して継承されました
    virtual bool Eval(const char* sz, ValidationResult& result) override
    {
        for (auto& v : m_validators)
        {
            if (v->Eval(sz, result)) return true;
        }
        return false;
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