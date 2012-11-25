#include "func.h"

double sign(const double &a, const double &b) {
	return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a);
}

double sqr(const double x) {
	return x * x;
}

double min(const double &a, const double &b) {
	if(a > b) {
		return b;
	} else {
		return a;
	}
}

double max(const double &a, const double &b) {
	if(a < b) {
		return b;
	} else {
		return a;
	}
}

double abs(const double &x) {
	if(x < 0) {
		return -x;
	} else {
		return x;
	}
}

double binomial_prefactor(int s, int ia, int ib, double xpa, double xpb){
  int t;
  double sum=0.;
  for (t=0; t<s+1; t++)
    if ((s-ia <= t) && (t <= ib))
      sum += binomial(ia,s-t)*binomial(ib,t)*pow(xpa,ia-s+t)*pow(xpb,ib-t);
  return sum;
}

int binomial(int a, int b) {
	return fact(a)/(fact(b) * fact(a-b));
}

double dist2(const Vector3 &a, const Vector3 &b) {
	return pow(a.x - b.x,2.0) + pow(a.y - b.y,2.0) + pow(a.z - b.z,2.0);
}

Vector3 gaussian_product_center(const double &alpha1, const Vector3 &a, const double &alpha2, const Vector3 &b) {
	double gamma = alpha1 + alpha2;
	double x = (alpha1 * a.x + alpha2 * b.x) / gamma;
	double y = (alpha1 * a.y + alpha2 * b.y) / gamma;
	double z = (alpha1 * a.z + alpha2 * b.z) / gamma;

	return Vector3(x,y,z);
}

void swap(unsigned int &i, unsigned int &j) {
	unsigned int m = i;
	i = j;
	j = m;
}
