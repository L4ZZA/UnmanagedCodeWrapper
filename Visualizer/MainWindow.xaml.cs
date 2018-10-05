using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Visualizer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private double CanvasLeft, CanvasBottom = 0;
        private Timer aTimer;
        private Key kDown;
        private bool isDown;

        public MainWindow()
        {
            InitializeComponent();

            CanvasLeft = -(rect.Width / 2);
            rect.SetValue(Canvas.BottomProperty, CanvasBottom);
            rect.SetValue(Canvas.LeftProperty, CanvasLeft);

            SetTimer();
        }

        private void OnKeyDown(object sender, KeyEventArgs e)
        {
            kDown = e.Key;
            isDown = true;
            aTimer.Start();
        }

        private void OnKeyUp(object sender, KeyEventArgs e)
        {
            if (kDown == e.Key)
                isDown = false;
            aTimer.Stop();
        }

        private void SetTimer()
        {
            int elapsedTime = 50;
            // Create a timer with a two second interval.
            aTimer = new Timer(elapsedTime);
            // Hook up the Elapsed event for the timer. 
            aTimer.Elapsed += OnTimedEvent;
            aTimer.AutoReset = true;
            aTimer.Enabled = true;
        }

        private void OnTimedEvent(Object source, ElapsedEventArgs e)
        {
            Debug.WriteLine("The Elapsed event was raised at {0:HH:mm:ss.fff}",
                e.SignalTime);
            int xDelta = 0;
            int yDelta = 0;

            if (isDown)
            {
                switch (kDown)
                {
                    case Key.Left:
                        Canvas.SetLeft(rect, Canvas.GetLeft(rect) - 1);
                        break;

                    case Key.Right:
                        Canvas.SetLeft(rect, Canvas.GetLeft(rect) + 1);
                        break;

                    case Key.Up:
                        Canvas.SetTop(rect, Canvas.GetTop(rect) - 1);
                        break;

                    case Key.Down:
                        Canvas.SetTop(rect, Canvas.GetTop(rect) + 1);
                        break;
                }
            }
        }


        private void OnClosed(object sender, EventArgs e)
        {
            aTimer.Dispose();
        }
    }
}
