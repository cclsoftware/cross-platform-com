//************************************************************************************************
//
// Cross-platform COM
// Copyright (c) 2024 CCL Software Licensing GmbH. All Rights Reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS",
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Filename    : crossplatformcombase.h
// Description : Cross-platform COM Classes
//
//************************************************************************************************

#ifndef _crossplatformcombase_h
#define _crossplatformcombase_h

#include "crossplatformcomapi.h"

#include <atomic>

//////////////////////////////////////////////////////////////////////////////////////////////////
// Macros
//////////////////////////////////////////////////////////////////////////////////////////////////

#define CPCOM_DEFINE_IUNKNOWN_METHODS \
HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject) override { return Unknown::QueryInterface (riid, ppvObject); } \
ULONG STDMETHODCALLTYPE AddRef () override { return Unknown::AddRef (); } \
ULONG STDMETHODCALLTYPE Release () override { return Unknown::Release (); }

//************************************************************************************************
// Unknown
//************************************************************************************************

class Unknown: public IUnknown
{
public:
	virtual ~Unknown () 
	{}

	// IUnknown
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject) override
	{
		*ppvObject = nullptr;
		return E_NOINTERFACE;		
	}
	
	ULONG STDMETHODCALLTYPE AddRef () override
	{
		return ++refCount;
	}
	
	ULONG STDMETHODCALLTYPE Release () override
	{
		if(--refCount == 0)
		{
			delete this;
			return 0;
		}
		return refCount;
	}

private:
	std::atomic<ULONG> refCount = 1;
};

#endif // _crossplatformcombase_h