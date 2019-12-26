using System.Windows;
using System.Windows.Media.Imaging;

namespace CornellRoom
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        RayTracing rt;
        Point camera_center = new Point(3, 2, 4); //центр
        Point camera_dir = new Point(-1, .5, 0);    // направление
        public MainWindow()
        {
            
            InitializeComponent();
            rt = new RayTracing(800, 800, Camera.Create(camera_center, camera_dir), 4, 4);
            rt.AddObj(new Plane()
            {
                norm = new Point(0, 1, 0),
                Offset = 0,
                color = new Point(0.5, 0.5, 0.5) 
            });
            rt.AddObj(new Plane()
            {
                norm = new Point(1, 0, 1),
                Offset = 5,
                color = new Point(0.0, 0.0, 1.0)
            });
            rt.AddObj(new Plane()
            {
                norm = new Point(1, 0, -2),
                Offset = 12,
                color = new Point(0.0, 1.0, 0.0)
            });
            rt.AddObj(new Plane()
            {
                norm = new Point(-2, 0, 1),
                Offset = 7,
                color = new Point(1, 0, 0)
            });
            rt.AddObj(new Sphere()
            {
                center = new Point(0, 1.3, 0),
                r = 1.3,
                color = new Point(1, 0, 0)
            });
            rt.AddObj(new Sphere()
            {
                center = new Point(1, 0.5, 1.5),
                r = .5,
                color = new Point(0.1, 1, 0.1)
            });
            rt.AddLight(new Light()
            {
                position = new Point(2.2, 2.5, 0),
                intensity = 3
            });
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var btmp = rt.calculate();
            FillContent(btmp);
        }

        public void FillContent(System.Drawing.Bitmap btmp) // отрисовка
        {
            if (btmp != null)
            {
                System.IO.MemoryStream ms = new System.IO.MemoryStream();
                btmp.Save(ms, System.Drawing.Imaging.ImageFormat.Png);
                ms.Position = 0;
                BitmapImage bi = new BitmapImage();
                bi.BeginInit();
                bi.StreamSource = ms;
                bi.EndInit();

                image.Source = bi;
            }
        }
    }
}
