#include <iostream>

using namespace std;

int main()
{
	double x[2][3] = {{1.0, 1.0, 1.0},{1.0, 2.0, 3.0}};
	point p1(x[0]), p2(x[1]);
	const point p3(0.4, 0.2, 0.1);

	cout << p1 << ", " << p2 << '\n';
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';
	cout << p1.distance(point()) << ", "<< p3.distance(p1) << '\n';
	cout << p1 + p2 << ", " << p1 - p3 << '\n';
	cout << 3.14 * p2 << ", " << p2 * 3.14 << '\n';
	cout << (p1 < p3) << ", " << (p1 == point(1.0, 1.0, 1.0)) << '\n';
	cin >> p1;
	cout << p1 << '\n';
	
	return 0;
}
