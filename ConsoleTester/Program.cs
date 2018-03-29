using System;
using CLIWrapper;

namespace ConsoleTester
{
    class Program
    {
        static void Main(string[] args)
        {
            Entity e = new Entity("The Wallman", 20, 35);
            Console.WriteLine("Starting position: "+e.XPosition + " " + e.YPosition);

            ConsoleKeyInfo input;
            do
            {
                input = Console.ReadKey();
                move(e, input.Key);
                Console.WriteLine("Moved to: " + e.XPosition + " " + e.YPosition);
            } while (input.Key != ConsoleKey.Escape);
        }

        static void move(Entity e, ConsoleKey key)
        {
            int deltaX = 0, deltaY = 0;
            switch (key)
            {
                case ConsoleKey.UpArrow:
                    deltaY = +1;
                    break;

                case ConsoleKey.DownArrow:
                    deltaY = -1;
                    break;

                case ConsoleKey.LeftArrow:
                    deltaX = -1;
                    break;

                case ConsoleKey.RightArrow:
                    deltaX = +1;
                    break;
            }
            e.Move(deltaX, deltaY);
        }
    }
}
