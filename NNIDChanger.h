#pragma once

#include "../minecraft/mc.h"
#include "../Key/key.hpp"
#include <code/code.h>

void NNIDChanger()
{
    wchar_t* nnidAddr = ((wchar_t*)((uint32_t)code::Mem(0x104CCB18 + 0x502200).as<wchar_t*>() + 0x50));
    mc::CInput::GetInput()->RequestKeyboard(L"", nnidAddr, 0, 24, [](void* data, bool b) -> int32_t {
        wchar_t temp[17];
        mc::CInput::GetInput()->GetText(temp, 24);
            
        mc_swprintf((wchar_t*) data, 24, L"%ls", temp);

        mc_printf(L"[NNIDChanger] NNID has been changed to %ls", temp);
        mc::ConsoleUIController::GetUIController()->PlayUISFX(mc::SoundEvent::MG03_emeraldPointTick);
        return 0;
    }, nnidAddr, mc::CInput::KeyboardMode::NNID);
}