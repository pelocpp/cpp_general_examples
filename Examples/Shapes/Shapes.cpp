// ===========================================================================
// Shapes.cpp // Implementation
// ===========================================================================

#include <vector>
#include <cmath>
#include "Shapes.h"

namespace Shapes {

    constexpr bool isLoggingActive = false;

    Shape::Shape(const std::string& name) : m_name(name)
    {
        if (isLoggingActive) {
            std::cerr << "c'tor Shape" << std::endl;
        }
    }

    Shape::~Shape()
    {
        if (isLoggingActive) {
            std::cerr << "d'tor Shape" << std::endl;
        }
    }

    std::string Shape::version()
    {
        return "1.00";
    }
   
    void Shape::draw(std::ostream& os)
    {
        os << "Shape: " << m_name << std::endl;
    }

    std::ostream& operator<< (std::ostream& os, const Shape& s)
    {
        os << "Shape: " << s.m_name;
        return os;
    }

    // ===========================================================================

    TwoDimensional::TwoDimensional(const std::string& name, double x, double y)
        : Shape(name), m_x(x), m_y(y)
    {
        if (isLoggingActive) {
            std::cerr << "  c'tor TwoDimensional" << std::endl;
        }
    }

    TwoDimensional::~TwoDimensional()
    {
        if (isLoggingActive) {
            std::cerr << "  d'tor TwoDimensional" << std::endl;
        }
    }

    void TwoDimensional::draw(std::ostream& os)
    {
        Shape::draw(os);
        os << "  TwoDimensional" << std::endl;
        os << "  Position: " << std::fixed << std::setprecision(2) 
            << m_x << ", " << m_y << std::endl;
    }

    void TwoDimensional::moveTo(double x, double y)
    {
        m_x = x;
        m_y = y;
    }

    std::ostream& operator<< (std::ostream& os, const TwoDimensional& td)
    {
        os << (Shape&)td << std::endl;
        os << "  TwoDimensional" << std::endl;
        os << "  Position: " << std::fixed << std::setprecision(2) 
            << td.m_x << ", " << td.m_y;
        return os;
    }

    // ===========================================================================

    ThreeDimensional::ThreeDimensional(
        const std::string& name, double x, double y, double z
    ) 
        : Shape(name), m_x(x), m_y(y), m_z(z)
    {
        if (isLoggingActive) {
            std::cerr << "  c'tor ThreeDimensional" << std::endl;
        }
    }

    ThreeDimensional::~ThreeDimensional()
    {
        if (isLoggingActive) {
            std::cerr << "  d'tor ThreeDimensional" << std::endl;
        }
    }

    void ThreeDimensional::draw(std::ostream& os)
    {
        Shape::draw(os);
        os << "  ThreeDimensional" << std::endl;
        os << "  Position: " << std::fixed << std::setprecision(2)
            << m_x << ", " << m_y << ", " << m_z << std::endl;
    }

    void ThreeDimensional::moveTo(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    std::ostream& operator<< (std::ostream& os, const ThreeDimensional& td)
    {
        os << (Shape&)td << std::endl;
        os << "  ThreeDimensional" << std::endl;
        os << "  Position: " << std::fixed << std::setprecision(2)
            << td.m_x << ", " << td.m_y << ", " << td.m_z;
        return os;
    }

    // ===========================================================================

    Triangle::Triangle() : Triangle(0, 0, 0, 0, 0) {}

    Triangle::Triangle(double x, double y, double a, double b, double c)
        : TwoDimensional("Triangle", x, y), m_a(a), m_b(b), m_c(c) {}

    Triangle::~Triangle()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Triangle" << std::endl;
        }
    }

    void Triangle::draw(std::ostream& os)
    {
        TwoDimensional::draw(os);
        os << std::fixed;
        os << "    A: " << std::setprecision(2) << m_a << std::endl;
        os << "    B: " << std::setprecision(2) << m_b << std::endl;
        os << "    C: " << std::setprecision(2) << m_c << std::endl;
        os << "    Area: " << std::setprecision(2) << area() << std::endl;
        os << "    Circumference: " << std::setprecision(2) 
            << circumference() << std::endl;
    }

    double Triangle::area() const
    {
        return sqrt(((4 * m_a * m_a * m_c * m_c) -
            (m_a * m_a + m_c * m_c - m_b * m_b) *
            (m_a * m_a + m_c * m_c - m_b * m_b)) / 16.0);
    }

    double Triangle::circumference() const
    {
        return m_a + m_b + m_c;
    }

    std::ostream& operator<< (std::ostream& os, const Triangle& t)
    {
        os << (TwoDimensional&)t << std::endl;
        os << std::fixed;
        os << "    A: " << std::setprecision(2) << t.m_a << std::endl;
        os << "    B: " << std::setprecision(2) << t.m_b << std::endl;
        os << "    C: " << std::setprecision(2) << t.m_c << std::endl;
        os << "    Area: " << std::setprecision(2) << t.area() << std::endl;
        os << "    Circumference: " << std::setprecision(2) 
            << t.circumference() << std::endl;
        return os;
    }

    // ===========================================================================

    Rectangle::Rectangle() : Rectangle(0, 0, 0, 0) {}

    Rectangle::Rectangle(double x, double y, double width, double height)
        : TwoDimensional("Rectangle", x, y), m_width(width), m_height(height) {}

    Rectangle::~Rectangle()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Rectangle" << std::endl;
        }
    }

    void Rectangle::draw(std::ostream& os)
    {
        TwoDimensional::draw(os);
        os << std::fixed;
        os << "    Width: " << std::setprecision(2) << m_width << std::endl;
        os << "    Height: " << std::setprecision(2) << m_height << std::endl;
        os << "    Area: " << std::setprecision(2) << area() << std::endl;
        os << "    Circumference: " << std::setprecision(2) 
            << circumference() << std::endl;
    }

    double Rectangle::area() const
    {
        return m_width * m_height;
    }

    double Rectangle::circumference() const
    {
        return 2 * (m_width + m_height);
    }

    std::ostream& operator<< (std::ostream& os, const Rectangle& r)
    {
        os << (TwoDimensional&)r << std::endl;
        os << std::fixed;
        os << "    Width: " << std::setprecision(2) << r.m_width << std::endl;
        os << "    Height: " << std::setprecision(2) << r.m_height << std::endl;
        os << "    Area: " << std::setprecision(2) << r.area() << std::endl;
        os << "    Circumference: " << std::setprecision(2)
            << r.circumference() << std::endl;
        return os;
    }

    // ===========================================================================

    Circle::Circle() : Circle(0, 0, 0) {}

    Circle::Circle(double x, double y, double radius)
        : TwoDimensional("Circle", x, y), m_radius(radius) {}

    Circle::~Circle()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Circle" << std::endl;
        }
    }

    void Circle::draw(std::ostream& os)
    {
        TwoDimensional::draw(os);
    }

    double Circle::area() const
    {
        return m_radius * m_radius * acos(-1);
    }

    double Circle::circumference() const
    {
        return 2 * acos(-1) * m_radius;
    }

    std::ostream& operator<< (std::ostream& os, const Circle& c)
    {
        os << (TwoDimensional&)c << std::endl;
        os << std::fixed;
        os << "    Radius: " << std::setprecision(2) << c.m_radius << std::endl;
        os << "    Area: " << std::setprecision(2) << c.area() << std::endl;
        os << "    Circumference: " << std::setprecision(2) 
            << c.circumference() << std::endl;
        return os;
    }

    // ===========================================================================

    Cube::Cube() : Cube(0, 0, 0, 0) {}

    Cube::Cube(double x, double y, double z, double size)
        : ThreeDimensional("Cube", x, y, z), m_size(size) {}

    Cube::~Cube()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Cube" << std::endl;
        }
    }

    void Cube::draw(std::ostream& os)
    {
        ThreeDimensional::draw(os);
        os << std::fixed;
        os << "    Size: " << std::setprecision(2) << m_size << std::endl;
        os << "    Volume: " << std::setprecision(2) << volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << surface() << std::endl;
    }

    double Cube::volume() const
    {
        return m_size * m_size * m_size;
    }

    double Cube::surface() const
    {
        return 6 * m_size * m_size;
    }

    std::ostream& operator<< (std::ostream& os, const Cube& c)
    {
        os << (ThreeDimensional&)c << std::endl;
        os << std::fixed;
        os << "    Size: " << std::setprecision(2) << c.m_size << std::endl;
        os << "    Volume: " << std::setprecision(2) << c.volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << c.surface() << std::endl;
        return os;
    }

    // ===========================================================================

    Cuboid::Cuboid() : Cuboid(0, 0, 0, 0, 0, 0) {}

    Cuboid::Cuboid(double x, double y, double z, double width, double height, double depth
    )
    : ThreeDimensional("Cuboid", x, y, z), m_width(width), m_height (height), m_depth(depth) {}

    Cuboid::~Cuboid()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Cuboid" << std::endl;
        }
    }

    void Cuboid::draw(std::ostream& os)
    {
        ThreeDimensional::draw(os);
        os << std::fixed;
        os << "    Width: " << std::setprecision(2) << m_width << std::endl;
        os << "    Height: " << std::setprecision(2) << m_height << std::endl;
        os << "    Depth: " << std::setprecision(2) << m_depth << std::endl;
        os << "    Volume: " << std::setprecision(2) << volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << surface() << std::endl;
    }

    double Cuboid::volume() const
    {
        return m_width * m_height * m_depth;
    }

    double Cuboid::surface() const
    {
        return 2 * (m_width * m_height + m_height * m_depth + m_width * m_depth);
    }

    std::ostream& operator<< (std::ostream& os, const Cuboid& c)
    {
        os << (ThreeDimensional&)c << std::endl;
        os << std::fixed;
        os << "    Width: " << std::setprecision(2) << c.m_width << std::endl;
        os << "    Height: " << std::setprecision(2) << c.m_height << std::endl;
        os << "    Depth: " << std::setprecision(2) << c.m_depth << std::endl;
        os << "    Volume: " << std::setprecision(2) << c.volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << c.surface() << std::endl;
        return os;
    }

    // ===========================================================================

    Sphere::Sphere() : Sphere(0, 0, 0, 0) {}

    Sphere::Sphere(double x, double y, double z, double radius)
        : ThreeDimensional("Sphere", x, y, z), m_radius(radius) {}

    Sphere::~Sphere()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Sphere" << std::endl;
        }
    }

    void Sphere::draw(std::ostream& os)
    {
        ThreeDimensional::draw(os);
        os << std::fixed;
        os << "    Radius: " << std::setprecision(2) << m_radius << std::endl;
        os << "    Volume: " << std::setprecision(2) << volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << surface() << std::endl;
    }

    double Sphere::volume() const
    {
        return (4.0 / 3.0) * acos(-1) * m_radius * m_radius * m_radius;
    }

    double Sphere::surface() const
    {
        return 4 * acos(-1) * m_radius * m_radius;
    }

    std::ostream& operator<< (std::ostream& os, const Sphere& s)
    {
        os << (ThreeDimensional&)s << std::endl;
        os << std::fixed;
        os << "    Radius: " << std::setprecision(2) << s.m_radius << std::endl;
        os << "    Volume: " << std::setprecision(2) << s.volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << s.surface() << std::endl;
        return os;
    }

    // ===========================================================================

    Cone::Cone() : Cone(0, 0, 0, 0, 0) {}

    Cone::Cone(double x, double y, double z, double radius, double height)
        : ThreeDimensional("Cone", x, y, z), m_radius(radius), m_height(height) {}

    Cone::~Cone()
    {
        if (isLoggingActive) {
            std::cerr << "    d'tor Cone" << std::endl;
        }
    }

    void Cone::draw(std::ostream& os)
    {
        ThreeDimensional::draw(os);
        os << std::fixed;
        os << "    Radius:  " << std::setprecision(2) << m_radius << std::endl;
        os << "    Height:  " << std::setprecision(2) << m_height << std::endl;
        os << "    Volume:  " << std::setprecision(2) << volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << surface() << std::endl;
    }

    double Cone::volume() const
    {
        return (acos(-1) * m_radius * m_radius * m_height) / 3;
    }

    double Cone::surface() const
    {
        return acos(-1) * m_radius *
            (m_radius + sqrt(m_height * m_height + m_radius * m_radius));
    }

    std::ostream& operator<< (std::ostream& os, const Cone& c)
    {
        os << (ThreeDimensional&)c << std::endl;
        os << std::fixed;
        os << "    Radius:  " << std::setprecision(2) << c.m_radius << std::endl;
        os << "    Height:  " << std::setprecision(2) << c.m_height << std::endl;
        os << "    Volume:  " << std::setprecision(2) << c.volume() << std::endl;
        os << "    Surface: " << std::setprecision(2) << c.surface() << std::endl;
        return os;
    }

    // ===========================================================================

    void test_01()
    {
        Triangle tria(1, 1, 2, 3, 4);
        tria.draw(std::cout);
        Rectangle rect(10, 10, 20, 40);
        rect.draw(std::cout);
        Circle circle(20, 20, 10);
        circle.draw(std::cout);
        Cube cube(30, 30, 20, 10);
        cube.draw(std::cout);
        Cuboid cuboid(50, 50, 40, 10, 20, 30);
        cuboid.draw(std::cout);
        Sphere sphere(40, 40, 30, 15);
        sphere.draw(std::cout);
        Cone cone(60, 60, 50, 20, 30);
        cone.draw(std::cout);
    }

    void test_02()
    {
        Triangle tria;
        std::cout << tria << std::endl;
        Rectangle rect;
        std::cout << rect << std::endl;
        Circle circle;
        std::cout << circle << std::endl;
        Cube cube;
        std::cout << cube << std::endl;
        Cuboid cuboid;
        std::cout << cuboid << std::endl;
        Sphere sphere;
        std::cout << sphere << std::endl;
        Cone cone;
        std::cout << cone << std::endl;
    }

    void test_03()
    {
        Triangle tria(1, 2, 5, 6, 7);
        Rectangle rect(10, 10, 40, 40);
        Circle circle(20, 20, 10);
        Sphere sphere(40, 40, 30, 15);
        Cone cone(60, 60, 50, 20, 30);

        AbstractShape* someShapes[] = { 
            &tria, &rect, &circle, &sphere, &cone 
        };

        for (AbstractShape* shape : someShapes) {
            shape->draw(std::cout);
        }

        TwoDimensional* someTwoDimShapes[] = { &tria, &rect, &circle };
        double totalArea = 0.0;
        for (TwoDimensional* twoDim : someTwoDimShapes) {
            totalArea += twoDim->area();
        }
        std::cout << "TotalArea: " << totalArea << std::endl;
    }

    void test_04()
    {
        Triangle tria(1, 2, 5, 6, 7);
        Rectangle rect(10, 10, 40, 40);
        Circle circle(20, 20, 10);
        Sphere sphere(40, 40, 30, 15);
        Cone cone(60, 60, 50, 20, 30);

        std::vector<AbstractShape*> someShapes{
            &tria,& rect,& circle,& sphere,& cone
        };

        for (AbstractShape* shape : someShapes) {
            shape->draw(std::cout);
        }

        std::vector<TwoDimensional*> someTwoDimShapes = {
            &tria, &rect, &circle 
        };

        double totalArea = 0.0;
        for (TwoDimensional* twoDim : someTwoDimShapes) {
            totalArea += twoDim->area();
        }
        std::cout << "TotalArea: " << totalArea << std::endl;
    }
}

// ===========================================================================

void main_inheritance()
{
    using namespace Shapes;

    test_01();
    test_02();
    test_03();
    test_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
