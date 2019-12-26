using System;

namespace CornellRoom
{
    public class Point
    {
        public double x, y, z;
        public Point(double x, double y, double z = 0)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        
        public static bool operator ==(Point left, Point right)
        {
            if (ReferenceEquals(left, null) && !ReferenceEquals(right, null) || !ReferenceEquals(left, null) && ReferenceEquals(right, null))
                return false;
            return ReferenceEquals(left, null) || left.x == right.x && left.y == right.y && left.z == right.z;
        }
        public static Point operator +(Point left, Point right)
        {
            return new Point(left.x + right.x, left.y + right.y, left.z + right.z);
        }
        public static Point operator +(Point left, double d)
        {
            return new Point(left.x + d, left.y + d, left.z + d);
        }
        public static Point operator -(Point left, double d)
        {
            return left + (-1) * d;
        }
        public static Point operator -(Point left, Point right)
        {
            return left + (-1) * right;
        }
        public static Point operator *(Point left, double d)
        {
            return new Point(left.x * d, left.y * d, left.z * d);
        }
        public static Point operator /(Point left, double d)
        {
            return new Point(left.x / d, left.y / d, left.z / d);
        }
        public static Point operator *(double d, Point left)
        {
            return left * d;
        }
        public static double operator *(Point right, Point left)
        {
            return (right.x * left.x) + (right.y * left.y) + (right.z * left.z);
        }
        public static bool operator !=(Point left, Point right)
        {
            return !(left == right);
        }
        

        public Point norm()
        {
            var m = mag();
            double div = m == 0 ? double.PositiveInfinity : 1 / m;
            return times(div);
        }

        public double mag()
        {
            return Math.Sqrt(this * this);
        }

        public Point times(double d)
        {
            return new Point(x * d, y * d, z * d);
        }
       
        public Point cross(Point v)
        {
            return new Point(( (y * v.z) - (z * v.y)),
                              ((z * v.x) - (x * v.z)),
                              ((x * v.y) - (y * v.x)));
        }
    }
}
