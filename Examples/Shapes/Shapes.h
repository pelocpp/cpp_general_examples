// ===============================================================================
// Shapes.h // Interfaces - Declarations
// ===============================================================================

#include <iostream>
#include <iomanip>
#include <string>

namespace Shapes {

    class AbstractShape
    {
    public:
        // public interface
        virtual std::string version() = 0;
        virtual void draw(std::ostream& os) = 0;
    };

    // ===========================================================================

    class Shape : public AbstractShape
    {
        friend std::ostream& operator<< (std::ostream&, const Shape&);

    private:
        std::string m_name;

    protected:
        // c'tor / d'tor
        Shape(const std::string& m_name);
        virtual ~Shape();

        // public interface
        virtual std::string version() override;
        virtual void draw(std::ostream& os) override;
    };

    // ===========================================================================

    class TwoDimensional : public Shape
    {
        friend std::ostream& operator<< (std::ostream&, const TwoDimensional&);

    protected:
        double m_x;
        double m_y;

    public:
        // c'tor
        TwoDimensional(const std::string&, double x, double y);
        virtual ~TwoDimensional();

        // public interface
        virtual void draw(std::ostream& os) override;
        virtual void moveTo(double x, double y);

        // contract for derived classes
        virtual double area() const = 0;
        virtual double circumference() const = 0;
    };

    // ===========================================================================

    class ThreeDimensional : public Shape
    {
        friend std::ostream& operator<< (std::ostream&, const ThreeDimensional&);

    protected:
        double m_x;
        double m_y;
        double m_z;

    public:
        // c'tor
        ThreeDimensional(const std::string&, double x, double y, double z);
        virtual ~ThreeDimensional();

        // public interface
        virtual void draw(std::ostream& os) override;
        virtual void moveTo(double x, double y, double z);

        // contract for derived classes
        virtual double volume() const = 0;
        virtual double surface() const = 0;
    };

    // ===========================================================================

    class Triangle final : public TwoDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Triangle&);

    protected:
        double m_a;
        double m_b;
        double m_c;

    public:
        Triangle();
        Triangle(double x, double y, double a, double b, double c);
        virtual ~Triangle();

        virtual void draw(std::ostream& os) override;
        virtual double area() const final;
        virtual double circumference() const final;
    };

    // ===========================================================================

    class Rectangle final : public TwoDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Rectangle&);

    protected:
        double m_width;
        double m_height;

    public:
        Rectangle();
        Rectangle(double x, double y, double width, double height);
        virtual ~Rectangle();

        virtual void draw(std::ostream& os) override;
        virtual double area() const final;
        virtual double circumference() const final;
    };

    // ===========================================================================

    class Circle final : public TwoDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Circle&);

    protected:
        double m_radius;

    public:
        Circle();
        Circle(double x, double y, double r);
        virtual ~Circle();

        virtual void draw(std::ostream& os) override;
        virtual double area() const final;
        virtual double circumference() const final;
    };

    // ===========================================================================

    class Cube final : public ThreeDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Cube&);

    protected:
        double m_size;

    public:
        Cube();
        Cube(double x, double y, double z, double size);
        virtual ~Cube();

        virtual void draw(std::ostream& os) override;
        virtual double volume() const final;
        virtual double surface() const final;
    };

    // ===========================================================================

    class Cuboid final : public ThreeDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Cuboid&);

    protected:
        double m_width;
        double m_height;
        double m_depth;

    public:
        Cuboid();
        Cuboid(double x, double y, double z, double width, double height, double depth);
        virtual ~Cuboid();

        virtual void draw(std::ostream& os) override;
        virtual double volume() const final;
        virtual double surface() const final;
    };

    // ===========================================================================

    class Sphere final : public ThreeDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Sphere&);

    protected:
        double m_radius;

    public:
        Sphere();
        Sphere(double x, double y, double z, double radius);
        virtual ~Sphere();

        virtual void draw(std::ostream& os) override;
        virtual double volume() const final;
        virtual double surface() const final;
    };

    // ===========================================================================

    class Cone final : public ThreeDimensional
    {
        friend std::ostream& operator<< (std::ostream&, const Cone&);

    protected:
        double m_radius;
        double m_height;

    public:
        Cone();
        Cone(double x, double y, double z, double radius, double height);
        virtual ~Cone();

        virtual void draw(std::ostream& os) override;
        virtual double volume() const final;
        virtual double surface() const final;
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
