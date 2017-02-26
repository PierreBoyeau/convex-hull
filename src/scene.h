#ifndef _SCENE_H_
#define _SCENE_H_

// std
#include <fstream>
#include <algorithm>
#include <list>

// Qt
#include <QtOpenGL>

// CGAL
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>


#undef min
#undef max

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

class Scene
{
public:
	typedef Kernel::FT FT;
	typedef Kernel::Point_2 Point;


private:
	// input points and hull
	std::list<Point> m_points;
	std::list<Point> m_hull;

	Point m_mouse_pos;

public:    
	Scene()
	{
	}

	~Scene()
	{
	}    

	void clear()
	{
		m_points.clear();
	}

	void random()
	{
		clear();

		for(int i = 0; i < 100; i++)
		{
			const double x = random_double(0.0, 1.0);
			const double y = random_double(0.0, 1.0);
			m_points.push_back(Point(x, y));
		}

		convex_hull();
	}

	double random_double(const double min, const double max)
	{
		double range = max - min;
		return min + (double(rand()) / double(RAND_MAX)) * range;
	}

	void add_point(const Point& point)
	{
		m_points.push_back(point);

		// recompute convex hull
		convex_hull(); 
	}

	void set_mouse_pos(const Point& pos) {  m_mouse_pos = pos; }


	void render()
	{
		// render points
		::glColor3ub(0, 0, 0); // black color
		::glPointSize(2.0f);

		::glBegin(GL_POINTS);
		std::list<Point>::iterator it;
		for(it = m_points.begin(); it != m_points.end(); it++)
		{
			const Point& p = *it;
			::glVertex2d(p.x(), p.y());
		}
		::glEnd();

		// render hull
		::glColor3ub(255, 0, 0); // red color
		::glLineWidth(3.0f);

		::glBegin(GL_LINE_LOOP);
		for(it = m_hull.begin(); it != m_hull.end(); it++)
		{
			const Point& p = *it;
			::glVertex2d(p.x(), p.y());
		}
		::glEnd();

	}

	//-------------------------------------------------------
	// TO COMPLETE
	//-------------------------------------------------------

	void convex_hull()
	{
		// TODO: recompute hull from points
	}

};

#endif // _SCENE_H_
