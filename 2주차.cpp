#include<cstdio>
#define MAX_DEGREE 80
class Polynomial {
	int degree;
	float coef[MAX_DEGREE];

public:
	Polynomial() { degree = 0; }

	void read() {
		printf("다항식의 최고차수를 입력하시오: ");
		scanf_s("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개):", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf_s("%f", coef + i);

	}

	void display(const char *str = " Poly= ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++) {
			if (coef[i] != 0)
			{
				if (coef[i] != 1)
					printf("%5.1f x^%d + ", coef[i], degree - i);
				else
					printf("  x^%d + ", degree - i);
			}
		}
		printf("%4.1f\n", coef[degree]);
	}

	void trim() {
		int k = 0;
		while (coef[k] == 0)
		{
			degree-=1;
			k++;
		}
		for (int i = 0; i <= degree; i++) 
			coef[i] = coef[i+k];
	
			
	}
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
		void trim();
	}
	void sub(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] -= b.coef[i];
		}
		else {
			b.negate();
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
		void trim();
	}
	void mult(Polynomial a, Polynomial b) {
		int mul[MAX_DEGREE];
		for (int i = 0; i <= MAX_DEGREE; i++)
			mul[i] = 0; 
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= a.degree; i++)
				for (int j = 0; j <= b.degree; j++)
					mul[i + j] += coef[i + (degree - b.degree)] * b.coef[j];
		}
		else {
			*this = b;
			for (int i = 0; i <= b.degree; i++)
				for (int j = 0; j <= a.degree; j++)
					mul[i + j] += coef[i + (degree - a.degree)] * a.coef[j];
		}
		void trim();
	}
	bool isZero() { return degree == 0; }
	void negate() {
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}



};

void main() {
	Polynomial a, b, c;
	a.read();
	b.read();
	a.display("A=");
	b.display("B=");

	c.add(a, b);
	c.display("A+B=");

	c.sub(a, b);
	c.display("A-B=");

	c.mult(a, b);
	c.display("A*B=");


}
