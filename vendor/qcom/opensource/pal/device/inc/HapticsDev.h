/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef HapticsDev_H
#define HapticsDev_H

#include "Device.h"

#ifdef SEC_AUDIO_SUPPORT_HAPTIC_PLAYBACK
#include "SecPalDefs.h"
#endif

class HapticsDev : public Device
{
protected:
    static std::shared_ptr<Device> obj;
    HapticsDev(struct pal_device *device, std::shared_ptr<ResourceManager> Rm);
public:
    static std::shared_ptr<Device> getInstance(struct pal_device *device,
                                               std::shared_ptr<ResourceManager> Rm);
    static int32_t isSampleRateSupported(uint32_t sampleRate);
    static int32_t isChannelSupported(uint32_t numChannels);
    static int32_t isBitWidthSupported(uint32_t bitWidth);
    static std::shared_ptr<Device> getObject();
    virtual ~HapticsDev();

#ifdef SEC_AUDIO_SUPPORT_HAPTIC_PLAYBACK
    int start();
    int32_t setParameter(uint32_t param_id, void *param) override;
private:
    void setHapticSource(haptic_source_t source);
    haptic_source_t hapticSource;
#endif
};


#endif //HapticsDev_H
