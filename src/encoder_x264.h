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

#include "encoder_abstract.h"

class X264Encoder : public AbstractEncoder
{
public:
	X264Encoder(JobObject *jobObject, const OptionsModel *options, const SysinfoModel *const sysinfo, const PreferencesModel *const preferences, JobStatus &jobStatus, volatile bool *abort, volatile bool *pause, QSemaphore *semaphorePause, const QString &sourceFile, const QString &outputFile);
	virtual ~X264Encoder(void);

	virtual const QString &getName(void);

	virtual QString printVersion(const unsigned int &revision, const bool &modified);
	virtual bool isVersionSupported(const unsigned int &revision, const bool &modified);

	static const AbstractEncoderInfo& getEncoderInfo(void);

protected:
	virtual const QString &getBinaryPath() { return m_binaryFile; }
	virtual void buildCommandLine(QStringList &cmdLine, const bool &usePipe, const unsigned int &frames, const QString &indexFile, const int &pass, const QString &passLogFile);

	virtual void checkVersion_init(QList<QRegExp*> &patterns, QStringList &cmdLine);
	virtual void checkVersion_parseLine(const QString &line, QList<QRegExp*> &patterns, unsigned int &core, unsigned int &build, bool &modified);

	virtual void runEncodingPass_init(QList<QRegExp*> &patterns);
	virtual void runEncodingPass_parseLine(const QString &line, QList<QRegExp*> &patterns, const int &pass, double &last_progress, double &size_estimate);

	const QString m_encoderName;
	const QString m_binaryFile;
};
