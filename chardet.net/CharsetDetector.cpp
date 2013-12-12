#include <ctype.h>
#include <string.h>
#include "CharsetDetector.h"
#include "charsetdetectPriv.h"

using namespace System;
using namespace System::Text;

namespace chardetnet
{
	/// <summary>
	/// Detect encoding of byte array. Returns System.Encoding instance or null if detection failed.
	/// </summary>
	Encoding^ CharsetDetector::Detect(array<Byte>^ data)
	{
		cli::pin_ptr<unsigned char> dataPtr = &(data[0]);

		Detector detector = Detector(NS_FILTER_ALL);
		int resultCode = detector.Consider(reinterpret_cast<const char*>(dataPtr), data->Length);
		const char* encoding = detector.Close();

		if (resultCode < 0 || encoding == NULL)
			return nullptr;

		// looks like .NET doesnt support that encodings
		if (_strcmpi(encoding, "ISO-2022-CN") == 0
			|| _strcmpi(encoding, "x-euc-tw") == 0
			|| _strcmpi(encoding, "X-ISO-10646-UCS-4-2143") == 0
			|| _strcmpi(encoding, "X-ISO-10646-UCS-4-3412") == 0)
			return nullptr;

		return Encoding::GetEncoding(gcnew String(encoding));
	};
}