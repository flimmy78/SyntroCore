//
//  Copyright (c) 2013 Pansenti, LLC.
//	
//  This file is part of Syntro
//
//  Syntro is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Syntro is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Syntro.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef SYNTROSTORE_H
#define SYNTROSTORE_H

#include <qmutex.h>
#include <qqueue.h>

#include "SyntroLib.h"
#include "StoreStream.h"

class SyntroStore
{
public:
	SyntroStore(StoreStream *stream);
	virtual ~SyntroStore();

	virtual void queueBlock(QByteArray block);
	virtual void processQueue() = 0;

protected:
	StoreStream *m_stream;

	QMutex m_blockMutex;
	QQueue<QByteArray> m_blocks;
};

#endif // SYNTROSTORE_H
