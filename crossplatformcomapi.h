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
// Filename    : crossplatformcomapi.h
// Description : Cross-platform COM API Definitions
//
//************************************************************************************************

#ifndef _crossplatformcomapi_h
#define _crossplatformcomapi_h

#ifdef _WIN32
#include <objidl.h>

#elif __APPLE__
#include <CoreFoundation/CFPlugInCOM.h>

// declare missing types
typedef ULONG UINT;
typedef UniChar WCHAR;
typedef unsigned long long ULONGLONG;
typedef CFUUIDBytes GUID;

#else
#error Unsupported platform!
#endif

#endif // _crossplatformcomapi_h