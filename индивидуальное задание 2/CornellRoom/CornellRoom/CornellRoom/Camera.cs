namespace CornellRoom
{
    class Camera
    {
        public Point Pos;
        public Point Forward;
        public Point Up;
        public Point Right;

        public static Camera Create(Point pos, Point lookAt)
        {
            Point forward = (lookAt - pos).norm();
            Point down = new Point(0, -1, 0);
            Point right = forward.cross(down).norm().times(1.5);
            Point up = forward.cross(right).norm().times(1.5);

            return new Camera() { Pos = pos, Forward = forward, Up = up, Right = right }; // направление где будет находиться px
        }
    }
}
