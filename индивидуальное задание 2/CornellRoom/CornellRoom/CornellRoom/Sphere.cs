using System;

namespace CornellRoom
{
    public class Sphere : Shape
    {
        public Point center;
        public double r;
        public Point Center()
        {
            return center;
        }

        public override ISect Intersect(Ray ray)    // уравнение луча к уравнению сферы
        {
            var eo = Center() - ray.Start;
            double v = eo * ray.Dir;
            double dist;
            if (v < 0)
            {
                dist = 0;
            }
            else
            {
                double disc = Math.Pow(r, 2) - (eo * eo - Math.Pow(v, 2));
                dist = disc < 0 ? 0 : v - Math.Sqrt(disc);
            }
            if (dist == 0) return null;
            return new ISect()
            {
                Thing = this,
                Ray = ray,
                Dist = dist
            };
        }
        public override Point normal(Point pos)
        {
            return (pos - Center()).norm();
        }
    }
}
