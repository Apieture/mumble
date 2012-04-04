/* Copyright (C) 2005-2012, Thorvald Natvig <thorvald@natvig.com>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MESSAGE_HANDLER_H_
#define MESSAGE_HANDLER_H_

#include <QtCore/QObject>
#include <QtCore/QEvent>

#include "Mumble.pb.h"
#include "MessageTypes.h"

class ServerHandler;

/**
 * Handles message dispatching to callback functions defined
 * in this message handler.
 *
 * @warning While this class definition is shared between client
 *			and server the implementation isn't. Make sure to not
 *			confuse the corresponding implementations in the
 *			mumble/ or murmur/ folders.
 */
class MessageHandler : public QObject {
	private:
		Q_OBJECT
		Q_DISABLE_COPY(MessageHandler)

		ServerHandler *pshServerHandler;

	public:
		MessageHandler(ServerHandler *serverHandler, QObject *parent = 0);

	private:
		/**
		 * Dispatches incoming ServerHandlerMessageEvent's to the
		 * corresponding handler function defined in this class.
		 */
		void customEvent(QEvent *);

#define MUMBLE_MH_MSG(x) void msg##x(const MumbleProto:: x &);
		MUMBLE_MH_ALL
#undef MUMBLE_MH_MSG
};

#endif // MESSAGE_HANDLER_H_
