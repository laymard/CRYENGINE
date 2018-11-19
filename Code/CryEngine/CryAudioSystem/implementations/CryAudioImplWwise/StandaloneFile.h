// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IStandaloneFileConnection.h>

namespace CryAudio
{
namespace Impl
{
namespace Wwise
{
class CStandaloneFile final : public IStandaloneFileConnection
{
public:

	CStandaloneFile(CStandaloneFile const&) = delete;
	CStandaloneFile(CStandaloneFile&&) = delete;
	CStandaloneFile& operator=(CStandaloneFile const&) = delete;
	CStandaloneFile& operator=(CStandaloneFile&&) = delete;

	CStandaloneFile() = default;
	virtual ~CStandaloneFile() override = default;
};
} // namespace Wwise
} // namespace Impl
} // namespace CryAudio