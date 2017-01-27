#include "instance_effect.h"

Instance_Effect::Instance_Effect()
{

}

void Instance_Effect::readDataFrom(TiXmlElement *src){
    m_Url = src->Attribute("url");
}
