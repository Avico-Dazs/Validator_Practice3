#pragma once
#include "ValidFactory.h"
#include "StringLength.h"
#include "ExcludingChars.h"

class PasswordValidFactory :
    public ValidFactory
{
private:
    virtual IValidator* CreateValid(int checkId, uint16_t wparam, uint32_t lparam)
    {
        AndValids* validator = new AndValids();
        validator->Add(StringLength(6));
        validator->Add(ExcludingChars(".,*()@\"\'-"));
        return validator;
    }
};

