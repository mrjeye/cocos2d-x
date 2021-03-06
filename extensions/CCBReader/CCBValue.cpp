#include "CCBValue.h"

using namespace cocos2d;

NS_CC_EXT_BEGIN

// Implementation of Color3BWapper

Color3BWapper* Color3BWapper::create(const Color3B& color)
{
    Color3BWapper *ret = new Color3BWapper();
    if (ret)
    {
        ret->color.r = color.r;
        ret->color.g = color.g;
        ret->color.b = color.b;
        
        ret->autorelease();
    }
    
    return ret;
}

const Color3B& Color3BWapper::getColor() const
{
    return color;
}

// Implementation of CCBValue

CCBValue* CCBValue::create(int nValue)
{
    CCBValue *ret = new CCBValue();
    if (ret)
    {
        ret->mValue.nValue = nValue;
        ret->mType = kIntValue;
        ret->autorelease();
    }
    
    return ret;
}

CCBValue* CCBValue::create(float fValue)
{
    CCBValue *ret = new CCBValue();
    if (ret)
    {
        ret->mValue.fValue = fValue;
        ret->mType = kFloatValue;
        ret->autorelease();
    }
    
    return ret;
}

CCBValue* CCBValue::create(bool vValue)
{
    CCBValue *ret = new CCBValue();
    if (ret)
    {
        ret->mValue.nValue = vValue ? 1 : 0;
        ret->mType = kBoolValue;
        ret->autorelease();
    }
    
    return ret;
}

CCBValue* CCBValue::create(unsigned char byte)
{
    CCBValue *ret = new CCBValue();
    if (ret)
    {
        ret->mValue.nValue = byte;
        ret->mType = kUnsignedCharValue;
        ret->autorelease();
    }
    
    return ret;
}

CCBValue* CCBValue::create(const char *pStringValue)
{
    CCBValue *ret = new CCBValue();
    if (ret)
    {
        ret->_value = pStringValue;
        ret->mType = kStringValue;
        ret->autorelease();
    }
    
    return ret;
}


CCBValue* CCBValue::create(Array *pArrValue)
{
    CCBValue *ret = new CCBValue();
    if (ret)
    {
        ret->_arrValue = pArrValue;
        ret->mType = kArrayValue;
        ret->autorelease();
    }
    
    return ret;
}


int CCBValue::getIntValue()
{
    assert(mType == kIntValue);
    
    return mValue.nValue;
}

float CCBValue::getFloatValue()
{
    assert(mType == kFloatValue);
    
    return mValue.fValue;
}

bool CCBValue::getBoolValue()
{
    assert(mType == kBoolValue);
    
    return mValue.nValue == 1 ? true : false;
}

unsigned char CCBValue::getByteValue()
{
    assert(mType == kUnsignedCharValue);
    
    return (unsigned char)(mValue.nValue);
}

Array* CCBValue::getArrayValue() {
    assert(mType == kArrayValue);
    
    return _arrValue;
}


const char* CCBValue::getStringValue()
{
    assert(mType == kStringValue);
    
    return _value.c_str();
}

int CCBValue::getType()
{
    return mType;
}

NS_CC_EXT_END
