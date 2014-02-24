///////////////////////////////////////////////////////////////////////////////
// Simple x264 Launcher
// Copyright (C) 2004-2014 LoRd_MuldeR <MuldeR2@GMX.de>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// http://www.gnu.org/licenses/gpl-2.0.txt
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "tool_abstract.h"

class QRegExp;
template<class T> class QList;

class AbstractEncoder : public AbstractTool
{
public:
	static const unsigned int REV_MULT = 10000;

	AbstractEncoder(const QUuid *jobId, JobObject *jobObject, const OptionsModel *options, const SysinfoModel *const sysinfo, const PreferencesModel *const preferences, volatile bool *abort);
	virtual ~AbstractEncoder(void);

	virtual unsigned int checkVersion(bool &modified);
	virtual bool isVersionSupported(const unsigned int &revision, const bool &modified) = 0;
	virtual void printVersion(const unsigned int &revision, const bool &modified) = 0;

protected:
	virtual void checkVersion_init(QList<QRegExp*> &patterns, QStringList &cmdLine) = 0;
	virtual void checkVersion_parseLine(const QString &line, QList<QRegExp*> &patterns, unsigned int &coreVers, unsigned int &revision, bool &modified) = 0;
};