using namespace System;
using namespace System::Text;

namespace chardetnet
{
	public ref class CharsetDetector
	{
	public:
		static Encoding^ Detect(array<Byte>^ data);
	};
}