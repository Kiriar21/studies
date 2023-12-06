#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
class point{
	private:
		float v[2];
	public:
		friend float distance(point p, point p1);
		point(){ 
			for(int i=0;i<2;i++) v[i]=0; 
		}
		point(const float a, const float b){
			if(a<0 || b<0) throw 1;
			v[0]=a, v[1]=b;
		}
		float &x() { return v[0]; }
		const float &x() const { return v[0]; }
		float &y() { return v[1]; }
		const float &y() const { return v[1]; }
};
float distance(point p, point p1) { 
	return sqrt(pow(p.v[0] - p1.v[0], 2) + pow(p.v[1] - p1.v[1], 2));
}
class wielokat{
	private:
		float _ob,_p;
	public:
		friend float distance(point p, point p1);
		wielokat(){
			_ob = 0, _p = 0;
		}
		float &ob() { return _ob; }
		const float &ob() const { return _ob; }
		float &p() { return _p; }
		const float &p() const { return _p; }
		void calculations(point nodes[], int polygon[], const int &sizeObject){
			for (int index = 0; index < sizeObject-1; index++){
				_ob += distance(nodes[polygon[index]-1], nodes[polygon[index+1]-1]);
				_p += nodes[polygon[index] - 1].x() * nodes[polygon[index + 1] - 1].y() - nodes[polygon[index+1] - 1].x() * nodes[polygon[index]-1].y();
			}
			_ob += distance(nodes[polygon[sizeObject-1]-1], nodes[polygon[0]-1]);
			_p/=2;
		}
};
int main(int argc, char** argv){
	fstream files("bad.txt");
	if(!files.good()){
		cerr<<"File doesnt exist.\n\n";
		files.clear();
		files.ignore();
		files.close();
		return 1;
	} 
	
	string lines;
	int sizeObject=1,index,*numberIndexes;
	float a,b;
	point* points;
	while(!files.eof()){
		getline(files,lines);
		cout<<lines<<endl;
		if(lines == "[NUMBER OF NODES]"){
			files >> sizeObject;
			if(sizeObject<1) throw 2;
			try{
				if(sizeObject>0) points = new point[sizeObject];
				cout<<sizeObject<<endl;
			}
			catch(int error){
				cout<<"Nie dziala - bledna wartosc: " << error <<endl;
			}
		}
		if(lines == "[NODES]"){
			try{
				for(int i=0;i<sizeObject;i++){
					files>>index>>a>>b;
					points[index-1]=point(a,b);	
					cout<<index<<'\t'<<a<<'\t'<<b<<'\n';			
				}
			}
			catch(...){
				cout<<"Niepoprawne wartosci dla NODES.\n";
			}
		}
		if(lines == "[POLYGON]"){
			if(sizeObject<1) throw 2;
				numberIndexes = new int[sizeObject];
				for(int i=0;i<sizeObject;i++){
					files>>numberIndexes[i];
					cout<<numberIndexes[i]<<endl;
				}
		}
	}
	wielokat w1;
	w1.calculations(points,numberIndexes,sizeObject);
	cout<<"Obwod wynosi: "<<w1.ob()<<endl;
	cout<<"Pole wynosi: "<<w1.p()<<endl;
	if (numberIndexes) delete [] numberIndexes;
	if (points) delete [] points;
	files.clear();
	files.ignore();
	files.close();
	return 0;
}
