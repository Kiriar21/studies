#include <iostream>
#include <math.h>

using namespace std;

class point{
	private:
		float v[3];
	public:
		point(){ 
			for(int i=0;i<3;i++) v[i]=0; 
		}
		point(float tab[]){
				for(int i=0;i<3;i++) 
					v[i]=tab[i];
		}
		point(const float a,const float b, const float c){
			v[0]=a, v[1]=b, v[2]=c;
		}

		float& operator[](unsigned int n){
			return v[n];
		}
		const float &operator[](unsigned int n) const
		{
			return v[n];
		}

		const float distance(const point p1) const{
			return sqrt((v[0] - p1[0]) * (v[0] - p1[0]) + (v[1] - p1[1]) * (v[1] - p1[1]) + (v[2] - p1[2]) * (v[2] - p1[2]));
		}

		friend ostream &operator<<(ostream &cout, const point &p1);
		friend ostream &operator<<(ostream &cout, const float &p1);
		friend istream &operator>>(istream &cin, point &p1);
			// friend point operator+(point a, point b);
			// friend point operator+(point a, float b);
			// friend point operator+(float a, point b);
		point operator-(point b)
		{
			point c;
			for (int i = 0; i < 3; ++i)
				c[i] = v[i] - b[i];
			return c;
		}
		point operator+(point b)
		{
			point c;
			for (int i = 0; i < 3; ++i)
				c[i] = v[i] + b[i];
			return c;
		}
		point operator*(float b)
		{
			point c;
			for (int i = 0; i < 3; ++i)
				c[i] = v[i] * b;
			return c;
		}
		bool operator<(point b){
			 return this->distance(point()) > b.distance(point()) ?  true :  false;
		}
		bool operator==(point b){
			if(this->v[0]==b[0]){
				if(this->v[1]==b[1]){
					if(this->v[2]==b[2]){
						return true;
					}
				}
			}
			return false;
		}
};

ostream &operator<<(ostream &cout, const point &p1)
{
		return cout << "Point x: "<<p1.v[0]<<" Point y: "<<p1.v[1]<<" Point z: "<<p1.v[2]<<endl; 
}
istream &operator>>(istream &cin, point &p1)
{
		return cin>>p1.v[0]>>p1.v[1]>>p1.v[2];
}
//Operator niearytmetyczny
point operator*(float a, point b){
	point c;
	for(int i=0;i<3;++i) c[i] = a * b[i];
	return c;
}

// point operator+(point a, point b){
// 	point c;
// 	for(int i=0;i<3;++i) c[i] = a[i] + b[i];
// 	return c;
// }

// point operator+(point a, float b){
// 	point c;
// 	for(int i=0;i<3;++i) c[i] = a[i] + b;
// 	return c;
// }
// point operator+(float a, point b){
// 	point c;
// 	for(int i=0;i<3;++i) c[i] = a + b[i];
// 	return c;
	
// 	// or
// 	// return b+a; - wykorzystuje poprzednia funkcje 24-28 linia
// }
int main()
{
	float x[2][3] = {{1.0, 1.0, 1.0},{1.0, 2.0, 3.0}};
	point p1(x[0]), p2(x[1]);
	const point p3(0.4, 0.2, 0.1);

	cout << p1 << ", " << p2 << '\n';
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n'<<endl<<endl;
	cout <<"Distance point p1 od podstawowego pustego:\n "<< p1.distance(point()) << "\nDistance point p3 od p1:\n "<< p3.distance(p1) << '\n';
	cout <<"p1+p2:\n " << p1 + p2 <<"p1-p3:\n" << p1 - p3 << '\n';
	cout <<"3.14*p2:\n " << 3.14 * p2 <<"p2*3.14:\n  " << p2 * 3.14 << '\n';
	cout <<"p1<p3:\n "<< (p1 < p3) <<"\np1==zerowy:\n" << (p1 == point(1.0, 1.0, 1.0)) << '\n';
	cin >> p1;
	cout << p1 << '\n';
	
	return 0;
}
