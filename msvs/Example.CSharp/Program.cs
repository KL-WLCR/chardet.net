using System;
using System.IO;
using libcharsetdetect;

namespace Example.CSharp
{
    static class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("usage: example-sharp <file>");
                return;
            }

            using (var fs = File.OpenRead(args[0]))
            {
                var buf = new byte[4096];
                var readedLen = fs.Read(buf, 0, buf.Length);
                var data = new byte[readedLen];
                Array.Copy(buf, data, readedLen);

                var encoding = CharsetDetector.Detect(data);
                Console.WriteLine(encoding == null ? "UNKNOWN" : encoding.WebName);
            }
        }
    }
}
