﻿namespace CornellRoom
{
    class Plane : Shape
    {
        public Point norm;
        public double Offset;

        public override ISect Intersect(Ray ray)    // вычисляем пересечение с объектом
        {
            double denom = norm * ray.Dir;
            if (denom > 0) return null;
            return new ISect()
            {
                Thing = this,
                Ray = ray,
                Dist = (norm * ray.Start + Offset) / (-denom)
            };
        }

        public override Point normal(Point point)
        {
            return norm;
        }
    }
}
