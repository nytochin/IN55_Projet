#include "init_from.h"

Init_From::Init_From()
{

}

void Init_From::readDataFrom(TiXmlElement *src){
    m_Filename = src->GetText();
}
