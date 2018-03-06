using System;
using CLIWrapper;

namespace ConsoleTester
{
    class Program
    {
        static void Main(string[] args)
        {
            Entity e = new Entity("The Wallman", 20, 35);
            e.Move(5, -10);
            Console.WriteLine(e.XPosition + " " + e.YPosition);
            Console.Read();
        }
    }
}
