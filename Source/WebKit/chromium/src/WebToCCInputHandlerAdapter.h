/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebToCCInputHandlerAdapter_h
#define WebToCCInputHandlerAdapter_h

#include "CCInputHandler.h"
#include <public/WebInputHandler.h>
#include <wtf/OwnPtr.h>
#include <wtf/PassOwnPtr.h>

namespace WebKit {

class WebToCCInputHandlerAdapter : public WebCore::CCInputHandler {
public:
    static PassOwnPtr<WebToCCInputHandlerAdapter> create(PassOwnPtr<WebInputHandler>);
    virtual ~WebToCCInputHandlerAdapter(); 

    // WebCore::CCInputHandler implementation.
    virtual void bindToClient(WebCore::CCInputHandlerClient*) OVERRIDE;
    virtual void animate(double monotonicTime) OVERRIDE;

private:
    explicit WebToCCInputHandlerAdapter(PassOwnPtr<WebInputHandler>);

    class ClientAdapter;
    OwnPtr<ClientAdapter> m_clientAdapter;
    OwnPtr<WebInputHandler> m_handler;
};

}

#endif // WebToCCInputHandlerAdapter_h