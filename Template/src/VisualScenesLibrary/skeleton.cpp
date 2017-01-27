#include "skeleton.h"

Skeleton::Skeleton()
{

}

void Skeleton::readDataFrom(TiXmlElement *src){
    // cout << "Current Element : " <<src->Value()<<endl;
    m_Skeleton = src->GetText();
}
