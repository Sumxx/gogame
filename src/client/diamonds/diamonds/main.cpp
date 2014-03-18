#include "stdafx.h"
#include <iostream>
#include "include\utils\utils.h"

int _tmain(int argc, _TCHAR* argv[])
{
    irr::IrrlichtDevice *pIrrDevice = createDevice(EDT_OPENGL,
        dimension2d<u32>(800,600),
        16,
        false,
        false,
        false);

    CString csImageTestPath(utils::GetGamePath() + L"res\\images\\brick0.png");
    CString csFontTestPath(utils::GetGamePath() + L"res\\fonts\\msyh.ttf");

    IVideoDriver *pIrrDriver = pIrrDevice->getVideoDriver();
    ITexture* Images = pIrrDriver->getTexture((LPCTSTR)csImageTestPath);
    IGUIEnvironment* pGuienv = pIrrDevice->getGUIEnvironment();
    pGuienv->addButton(rect<int>(200,10,238,30), 0, 2, L"1");
    pGuienv->addEditBox(L"1", rect<int>(0,0,238,200), 0, 0, 3);

    pIrrDevice->setWindowCaption(L"hehehe");

    while (pIrrDevice->run())
    {
        pIrrDriver->beginScene(true, true, SColor(255,0,0,0));
        pIrrDriver->draw2DImage(Images, position2d<s32>(0,0),
            rect<s32>(0,0,800,600), 0,
            SColor(255,255,255,255), true);
        pGuienv->drawAll();
        pIrrDriver->endScene();
    }

    pIrrDevice->drop();
    return 0;
}
