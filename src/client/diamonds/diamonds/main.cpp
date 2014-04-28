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
    ISceneManager* scene_mgr = pIrrDevice->getSceneManager();
    ISceneNode* cube = scene_mgr->addCubeSceneNode(100.0f);
    cube->setMaterialTexture(0, Images);
    cube->setMaterialFlag(video::EMF_LIGHTING, false);
    scene::ICameraSceneNode* camera = scene_mgr->addCameraSceneNode(0,
        core::vector3df(700,700,-700),
        core::vector3df(0,0,0));
    f32 iYPos = 0;

    pIrrDevice->setWindowCaption(L"hehehe");

    while (pIrrDevice->run())
    {
        pIrrDriver->beginScene(true, true, SColor(255,0,0,0));
        pIrrDriver->draw2DImage(Images, position2d<s32>(0,0),
            rect<s32>(0,0,800,600), 0,
            SColor(255,255,255,255), true);
        scene_mgr->drawAll();
        cube->setPosition(core::vector3df(0, ++iYPos, -700));
        pIrrDriver->endScene();
    }

    pIrrDevice->drop();
    return 0;
}
