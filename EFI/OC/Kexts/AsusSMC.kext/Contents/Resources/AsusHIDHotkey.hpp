//
//  AsusHIDHotkey.hpp
//  AsusSMC
//
//  Created by lymos on 2025/7/6.
//  Copyright © 2025 Le Bao Hiep. All rights reserved.
//
#ifndef _ASUS_HID_HOTKEY_HPP
#define _ASUS_HID_HOTKEY_HPP

#include <IOKit/IOService.h>
#include <IOKit/hidsystem/IOHIKeyboard.h>

class AsusHIDHotkey : public IOService {
    OSDeclareDefaultStructors(AsusHIDHotkey)

public:
    bool start(IOService* provider) override;
    void stop(IOService* provider) override;

private:
    static void keyboardEventCallback(OSObject* target,
                                      unsigned eventType,
                                      unsigned flags,
                                      unsigned key,
                                      unsigned charCode,
                                      unsigned charSet,
                                      unsigned origCharCode,
                                      unsigned origCharSet,
                                      unsigned keyboardType,
                                      bool repeat,
                                      AbsoluteTime ts);

    void handleKeyPress(unsigned key);
};

#endif // _ASUS_HID_HOTKEY_HPP


