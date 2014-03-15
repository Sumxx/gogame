#include "stdafx.h"
#include "irrlicht/irrlicht.h"

#ifdef _IRR_WINDOWS_
#ifdef _DEBUG
#pragma comment(lib,"../../../../lib/irrlicht_d.lib")
#else
#pragma comment(lib,"../../../../lib/irrlicht.lib")
#endif // _DEBUG
#endif


using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int _tmain(int argc, _TCHAR* argv[])
{
    irr::IrrlichtDevice *pIrrDevice = createDevice(EDT_OPENGL,
        dimension2d<u32>(800,600),
        16,
        false,
        false,
        false);

    IVideoDriver *pIrrDriver = pIrrDevice->getVideoDriver();

    pIrrDevice->setWindowCaption(L"hehehe");

    while (pIrrDevice->run())
    {

    }

    pIrrDevice->drop();
    return 0;
}
