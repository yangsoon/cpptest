class Point2d {
protected:
    float _x, _y;
};

class Vertex:public virtual Point2d {
protected:
    Vertex *next;
};

class Point3d : public virtual Point2d {
protected:
    float _z;
};

class Vertex3d: public Vertex, public Point3d {
protected:
    float mumble;
};