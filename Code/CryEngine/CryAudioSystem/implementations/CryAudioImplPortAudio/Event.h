// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IEvent.h>
#include <portaudio.h>
#include <atomic>
#include <PoolObject.h>

// Forward declare C struct
struct SNDFILE_tag;
using SNDFILE = struct SNDFILE_tag;

namespace CryAudio
{
class CEvent;

namespace Impl
{
namespace PortAudio
{
enum class EEventState
{
	None                  = 0,
	Playing               = BIT(0),
	Stopped               = BIT(1),
	Done                  = BIT(2),
	WaitingForDestruction = BIT(3),
};

class CObject;

class CEvent final : public IEvent, public CPoolObject<CEvent, stl::PSyncNone>
{
public:

	CEvent() = delete;
	CEvent(CEvent const&) = delete;
	CEvent(CEvent&&) = delete;
	CEvent& operator=(CEvent const&) = delete;
	CEvent& operator=(CEvent&&) = delete;

	explicit CEvent(CryAudio::CEvent& event_);
	virtual ~CEvent() override;

	bool Execute(
		int const numLoops,
		double const sampleRate,
		CryFixedStringT<MaxFilePathLength> const& filePath,
		PaStreamParameters const& streamParameters);
	void Update();

	// CryAudio::Impl::IEvent
	virtual ERequestStatus Stop() override;
	// ~CryAudio::Impl::IEvent

	SNDFILE*                 pSndFile;
	PaStream*                pStream;
	void*                    pData;
	CObject*                 pObject;
	int                      numChannels;
	int                      remainingLoops;
	CryAudio::CEvent&        event;
	uint32                   pathId;
	PaSampleFormat           sampleFormat;
	std::atomic<EEventState> state;

private:

	void Reset();
};
} // namespace PortAudio
} // namespace Impl
} // namespace CryAudio