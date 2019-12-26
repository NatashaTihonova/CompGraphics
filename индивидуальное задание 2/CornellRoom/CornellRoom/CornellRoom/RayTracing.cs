using System;
using System.Collections.Generic;
using System.Linq;

namespace CornellRoom
{
    class RayTracing
    {
        int width, height;
        double x_size, y_size; 
        List<Shape> objects;
        Light light;
        public Camera camera;
        Point background_color = new Point(0, 0, 0);
        double fit(double f, double ceil)
        {
            return f > ceil ? ceil : f;
        }
        System.Drawing.Color ToColor(Point point)   // контроль перенасыщения 
        {
            int r = (int)Math.Round(fit(point.x, 1) * 255);
            int g = (int)Math.Round(fit(point.y, 1) * 255);
            int b = (int)Math.Round(fit(point.z, 1) * 255);
            return System.Drawing.Color.FromArgb(r, g, b);
        }


        public RayTracing(int width, int height, Camera camera, double x_size, double y_size)
        {
            objects = new List<Shape>();
            this.width = width;
            this.height = height;
            this.camera = camera;
            this.x_size = x_size;
            this.y_size = y_size;
        }

        public void AddObj(Shape shape)
        {
            objects.Add(shape);
        }

        public void AddLight(Light light)
        {
            this.light = light;
        }

        public System.Drawing.Bitmap calculate() // вычисляем 3-хм координаты и выпускаем луч; (цвет)
        {
            System.Drawing.Bitmap result = new System.Drawing.Bitmap(width, height);
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    Point pixel = new Point(x, y);
                    Point pixel_3d = get_pixel_position(pixel);
                    var color = TraceRay(new Ray() { Start = camera.Pos, Dir = pixel_3d }); // выпустили луч и получили цвет
                    var draw_color = ToColor(color);
                    result.SetPixel(x, y, draw_color);
                }
            }
            return result; // получаем цвет
        }
        Point get_pixel_position(Point pixel) // перевод координат экрана в 3х-мерные
        {
            pixel.x = (pixel.x - (width / 2.0)) * x_size / (2 * width);
            pixel.y = -(pixel.y - (height / 2.0)) * y_size / (2 * height);
            return (camera.Forward + camera.Right.times(pixel.x) + camera.Up.times(pixel.y)).norm();
        }
        private IEnumerable<ISect> Intersections(Ray ray)
        {
            return objects.Select(obj => obj.Intersect(ray))
                        .Where(inter => inter != null)
                        .OrderBy(inter => inter.Dist);
        }
        private double TestRay(Ray ray) // объект между светом и точкой
        {
            var isects = Intersections(ray);
            ISect isect = isects.FirstOrDefault();
            if (isect == null)
                return 0;
            return isect.Dist;
        }
        private Point TraceRay(Ray ray) // точка откуда и направление
        {
            var isects = Intersections(ray);
            ISect isect = isects.FirstOrDefault();
            if (isect == null)
                return background_color;
            return Shade(isect);
        }
        private Point GetNaturalColor(Shape thing, Point pos, Point norm, Point rd)
        {
            Point result = background_color;
            var light_distance = light.position - pos; // расстояние от света до точки пересечения
            var light_norm = light_distance.norm();
            double near_t = TestRay(new Ray() { Start = pos, Dir = light_norm });
            bool isInShadow = !((near_t > light_distance.mag()) || (near_t == 0));
            if (!isInShadow)
            {
                result += thing.color * light.intensity * Math.Max(0, light_norm * thing.normal(pos)); //цвет*интенс*затухание
            }
            return result;
        }
        private Point Shade(ISect isect) // находим естественный цвет пикселя
        {
            var pos = isect.Dist * isect.Ray.Dir + isect.Ray.Start; //точка пересечения
            var normal = isect.Thing.normal(pos);
            var reflectDir = isect.Ray.Dir - (2 * (normal * isect.Ray.Dir) * normal);
            Point result = background_color;
            result += GetNaturalColor(isect.Thing, pos, normal, reflectDir);
            return result;
        }
    }
}
