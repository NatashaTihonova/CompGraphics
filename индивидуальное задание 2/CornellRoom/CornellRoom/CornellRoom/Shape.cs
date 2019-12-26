namespace CornellRoom
{
    public abstract class Shape
    {
        public static double eps = 0.0001;
        public Point color;
        abstract public ISect Intersect(Ray ray);
        abstract public Point normal(Point point);
    }
}
