#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <cmath>
using namespace std;

//листинг 7

//7.1

template<class X> void show(X arg) {
	cout << arg << endl;
}
int main() {
	system("chcp 1251>nul");
	show('A');
	show(123);
	show("Текст");
	system("pause>nul");
	return 0;
}
//7.2

template<class T> void show(T* m, int n) {
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
template<class X> void sort(X* m, int n) {
	show(m, n);
	X s;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (m[j] > m[j + 1]) {
				s = m[j + 1];
				m[j + 1] = m[j];
				m[j] = s;
			}
		}
	}
	show(m, n);
}
int main() {
	system("chcp 1251>nul");
	int A[5] = { 3,2,8,1,0 };
	char B[7] = { 'Z', 'B', 'Y', 'A', 'D', 'C', 'X' };
	sort(A, 5);
	sort(B, 7);
	system("pause>nul");
	return 0;
}

//7.3

template<class X, class R> R apply(R(*fun) (X), X arg){
return fun(arg);
	}
	double f(double x) {
		return x * (1 - x);
	}
	int factorial(int n) {
		if (n == 0) {
			return 1;
		}
		else {
			return n * factorial(n - 1);
		}
	}
	char symb(int n) {
		return 'A' + n;
	}
	int main() {
		system("chcp 1251>nul");
		cout << apply(f, 0.5) << endl;
		cout << apply(factorial, 5) << endl;
		cout << apply(symb, 3) << endl;
		system("pause>nul");
		return 0;
	}

//7.4

template<class X> void show(X x) {
	cout << "Функция с одним аргументов\n";
	cout << "Знавение аргумента: " << x << endl;
}
template<class X, class Y> void show(X x, Y y) {
	cout << "Функция с двумя аргументами\n";
	cout <<"Первый аргумента : "<<x<<endl;
		cout <<"Второй аргумент : "<<y<<endl;
}
int main() {
	system("chcp 1251>nul");
	show('A');
	show(123);
	show("Текст");
	show(321, "Текст");
	show('B', 456);
	show('C', 'D');
	system("pause>nul");
	return 0;
}

//7.5

class MyClass {
public:
	int number;
	MyClass(int n) {
		number = n;
	}
	void show() {
		cout << "Объект класса MyClass: " << number << endl;
	}
};
template<class X> void show(X arg) {
	cout << "Значение аргумента функции: " << arg << endl;
}
template<> void show <int>(int arg) {
	cout << "Целочисленный аргумент: " << arg << endl;
}
template<> void show <MyClass>(MyClass obj) {
	obj.show();
}
int main() {
	system("chcp 1251>nul");
	MyClass obj(300);
	show('A');
	show(100.0);
	show(200);
	show(obj);
	system("pause>nul");
	return 0;
}


//7.6

template<class A, class B> class MyClass {
public:
	A first;
	B second;
	MyClass(A f, B s) {
		first = f;
		second = s;
	}
	void show() {
		cout << "Первое поле: " << first << endl;
		cout << "Второе поле: " << second << endl;
	}
};
int main() {
	system("chcp 1251>nul");
	MyClass<int, char> objA(100, 'A');
	MyClass<string, double> objB("текст", 10.5);
	MyClass<string, string> objC("первый", "второй");
	MyClass<int, int> objD(1, 2);
	objA.show();
	objB.show();
	objC.show();
	objD.show();
	system("pause>nul");
	return 0;
}

//7.7

template<class T> class MyClass {
private:
	T value;
public:
	MyClass(T v) {
		value = v;
	}
	void show() {
		cout << "Значение поля: " << value << endl;
	}
};
template<> class MyClass <string>{
private:
	char value[100];
public:
	MyClass(string str) {
		int k;
		value[0] = 'j';
		for (k = 0; str[k]; k++) {
			value[2 * k + 1] = str[k];
			value[2 * k + 2] = '|';
		}
		value[2 * k + 1] = '\0';
	}
	void show() {
		cout << value << endl;
	}
};
int main() {
	system("chcp 1251>nul");
	MyClass<int> objA(100);
	MyClass<char> objB('A');
	MyClass<string> objC("текст");
	MyClass<string> objD("текст");
	objA.show();
	objB.show();
	objC.show();
	objD.show();
	system("pause>nul");
	return 0;
}


//7.8

template<class A = int, class B = char> class MyClass {
public:
	A first;
	B second;
	MyClass(A f, B s) {
		first = f;
		second = s;
	}
	void show() {
		cout << "Значения " << first << " и " << second << endl;
	}
};
int main() {
	system("chcp 1251>nul");
	MyClass<double, int> objA(3.5, 100);
	MyClass<string> objB("текст", 'A');
	MyClass<> objC(200, 'B');
	objA.show();
	objB.show();
	objC.show();
	system("pause>nul");
	return 0;
}

//7.9

template<class A> class Alpha {
public:
	A alpha;
	Alpha(A a) {
		alpha = a;
	}
	void show() {
		cout << "Поле alpha: " << alpha << endl;
	}
};
template<class B> class Bravo {
public:
	B bravo;
	Bravo(B b) {
		bravo = b;
	}
	void show() {
		cout << "Поле bravo: " << bravo << endl;
	}
};
template<class A, class B, class C> class Charlie : public
Alpha<A>, public Bravo<B>{
public:
C charlie;
Charlie(A a,B b,C c) :Alpha<A>(a),Bravo<B>(b) {
charlie = c;
}
void show() {
Alpha<A>::show();
Bravo<B>::show();
cout << "Поле charlie: " << charlie << endl;
}
};
int main() {
	system("chcp 1251>nul");
	Charlie<string, char, int> objA("текст", 'A', 100);
	Charlie<int, double, char> objB(200, 5.5, 'B');
	objA.show();
	objB.show();
	system("pause>nul");
	return 0;
}


//7.10

template<class X> class BaseClass {
private:
	X value;
public:
	BaseClass(X val) {
		set(val);
	}
	void set(X val) {
		value = val;
	}
	X get() {
		return value;
	}
};
class Alpha : public BaseClass<int> {
public:
	Alpha():BaseClass<int>(0) {}
};
class Bravo : public BaseClass<char> {
public:
	Bravo(char s) :BaseClass<char>(s) {}
};
int main() {
	system("chcp 1251>nul");
	Alpha objA;
	cout << "Объект objA: " << objA.get() << endl;
	objA.set(100);
	cout << "Объект objA: " << objA.get() << endl;
	Bravo objB('A');
	cout << "Объект objB: " << objB.get() << endl;
	objB.set('B');
	cout << "Объект objB: " << objB.get() << endl;
	system("pause>nul");
	return 0;
}

//7.11

template<int power> class  Polynom {
private:
	double a[power + 1];
public:
	Polynom() {
		for (int k = 0; k <= power; k++) {
			a[k] = 0;
		}
	}
	Polynom(double* nums) {
		for (int k = 0; k <= power; k++) {
			a[k] = nums[k];
		}
	}
	void getAll() {
		cout << "| ";
		for (int k = 0; k <= power; k++) {
			cout << a[k] << " | ";
		}
		cout << endl;
	}
	double operator()(double x) {
		double s = 0, q = 1;
		for (int k = 0; k <= power; k++) {
			s += a[k] * q;
			q *= x;
		}
		return s;
	}
	double& operator[](int k) {
		return a[k];
	}
	template<int n> Polynom<power + n> operator*(Polynom<n> pol) {
		Polynom<power + n> tmp;
		for (int i = 0; i <= power; i++) {
			for (int j = 0; j <= n; j++) {
				tmp[i + j]+= a[i] * pol[j];
			}
		}
		return tmp;
	}
	template<int n> Polynom<(n > power ? n : power)>
	operator+(Polynom<n> pol) {
		int i;
		Polynom<(n > power ? n : power)> tmp;
		for (i = 0; i <= power; i++) {
			tmp[i] += a[i];
		}
		for (i = 0; i <= n; i++) {
			tmp[i] + pol[i];
		}
		return tmp;
	}
};
template<int power> Polynom<power> operator*(Polynom<power>pol, double r) {
	Polynom<power> tmp;
	for (int k = 0; k <= power; k++) {
		tmp[k] = pol[k] * r;
	}
	return tmp;
}
template<int power> Polynom<power> operator*(double r, Polynom<power> pol) {
	return pol * r;
}
template<int m, int n> Polynom<(m > n ? m : n)> operator-(Polynom<m> x, Polynom<n> y) {
	return x + (-1) * y;
}
template<int power> Polynom<power - 1> Diff(Polynom<power> pol) {
	Polynom<power - 1> tmp;
	for (int k = 0; k <= power - 1; k++) {
		tmp[k] = pol[k + 1] * (k + 1);
	}
	return tmp;
}
int main() {
	system("chcp 1251>nul");
	double A[] = { 1,2,-1,1 };
	double B[] = { -1,3,0,2,-1,1 };
	double x = 2;
	Polynom <3> P(A);
	cout << "Полином P:\t";
	P.getAll();
	cout << "Значение P(" << x << ") = ";
	cout << P(x) << endl;
	cout << "Полином P':\t";
	Diff(P).getAll();
	cout << "Значение P'(" << x << ") = ";
	cout << Diff(P)(x) << endl;
	Polynom<5> Q(B);
	cout << "Полином Q:\t";
	Q.getAll();
	cout << "Значение Q(" << x << ") = ";
	cout << Q(x) << endl;
	cout << "Полином P*Q:\t";
	(P * Q).getAll();
	cout << "Значение (P*Q)(" << x << ") = ";
	cout << (P * Q)(x) << endl;
	cout << "Полином P+Q:\t";
	(P + Q).getAll();
	cout << "Значение (P+Q)(" << x << ") = ";
	cout << (P + Q)(x) << endl;
	cout << "Полином Q-P:\t";
	(Q - P).getAll();
	cout << "Значение (Q-P)(" << x << ") = ";
	cout << (Q - P)(x) << endl;
	system("pause>nul");
	return 0;
}

//Листинг 8

//8.1

struct MyMoney {
	string name;
	double money;
	double rate;
	int time;
};
double getMoney(MyMoney str) {
	double s = str.money;
	for (int k = 1; k <= str.time; k++) {
		s *= (1 + str.rate / 100);
	}
	return s;
}
void show(MyMoney str) {
	cout << "Имя вкладчика : " << str.name << endl;
	cout << "Начальная сумма : " << str.money << endl;
	cout << "Процентная ставка : " << str.rate << endl;
	cout << "Время (лет) : " << str.time << endl;
	cout << "Итоговая сумма : " << getMoney(str) << endl;
}
int main() {
	system("chcp 1251>nul");
	MyMoney cat = { "Кот Матроскин",1000,8,5 };
	MyMoney dog = { "Пес Шарик",1200,7,4 };
	show(cat);
	show(dog);
	system("pause>nul");
	return 0;
}

//8.2

template<class A, class B> struct MyStruct {
	A first;
	B second;
};
template<class A, class B> void show(MyStruct<A, B> str) {
	cout << "Первое поле: " << str.first << endl;
	cout << "Второе поле: " << str.second << endl;
}
int main() {
	system("chcp 1251>nul");
	MyStruct<int, char> strA = { 100,'A' };
	MyStruct<double, string> strB = { 2.5,"текст" };
	show(strA);
	show(strB);
	system("pause>nul");
	return 0;
}

//8.3

int main() {
	system("chcp 1251>nul");
	double x = 2, y = 3;
	complex<double> A(3, 4), B(2, -1);
	cout << "Сумма :";
	cout << A << " + " << B << " = " << A + B << endl;

	cout << "Разность :";
	cout << A << " - " << B << " = " << A - B << endl;

	cout << "Произведение :";
	cout << A << " * " << B << " = " << A * B << endl;

	cout << "Частное :";
	cout << A << " / " << B << " = " << A / B << endl;

	cout << "Сумма :";
	cout << A << " + " << x << " = " << A + x << endl;

	cout << "Разность :";
	cout << A << " - " << x << " = " << A - x << endl;

	cout << "Произведение :";
	cout << A << " * " << x << " = " << A * x << endl;

	cout << "Частное :";
	cout << A << " / " << x << " = " << A / x << endl;

	cout << "Сумма :";
	cout << y << " + " << B << " = " << y + B << endl;

	cout << "Разность :";
	cout << y << " - " << B << " = " << y - B << endl;

	cout << "Произведение :";
	cout << y << " * " << B << " = " << y * B << endl;

	cout << "Частное :";
	cout << y << " / " << B << " = " << y / B << endl;

	cout << "Действительная часть: ";
	cout << "Re" << A << " = " << A.real() << endl;

	cout << "Мнимая часть: ";
	cout << "Im" << A << " = " << A.imag() << endl;

	cout << "Модуль: ";
	cout << "abs" << A << " = " << abs(A) << endl;

	cout << "Аргумент: ";
	cout << "arg" << A << " = " << arg(A) << endl;

	cout << "Комплексно-сопряженное: ";
	cout << A << "* = " << conj(A) << endl;

	cout << "Определитель числа: ";
	cout << polar(abs(A), arg(A)) << endl;

	system("pause>nul");
	return 0;
}

//листинг 8.4

int main() {
	system("chcp 1251>nul");
	int n;
	cout << "Введите размер массива:";
	cin >> n;
	valarray<int> fibs(n);
	fibs[0] = 1;
	fibs[1] = 1;
	cout << fibs[0] << " " << fibs[1];
	for (int k = 2; k < n; k++) {
		fibs[k] = fibs[k - 1] + fibs[k - 2];
		cout << " " << fibs[k];
	}
	cout << endl;
	system("pause>nul");
	return 0;
}

//8.5

class Polynom {
private:
	valarray<double> a;
public:
	Polynom(int n = 0) {
		a.resize(n + 1, 0);
	}
	Polynom(double* nums, int n) {
		valarray<double> b(nums, n + 1);
		a = b;
	}
	int power() {
		return a.size() - 1;
	}
	void getAll() {
		cout << "| ";
		for (int k = 0; k <= power(); k++) {
			cout << a[k] << " | ";
		}
		cout << endl;
	}
	double operator() (double x) {
		valarray<double> b(a);
		double q = 1;
		for (int k = 0; k < b.size(); k++) {
			b[k] *= q;
			q *= x;
		}
		return b.sum();
	}
	double& operator[](int k) {
		return a[k];
	}
	Polynom operator*(Polynom pol) {
		Polynom tmp(pol.power() + power());
		for (int i = 0; i <= power(); i++) {
			for (int j = 0; j <= pol.power(); j++) {
				tmp[i + j] += a[i] * pol[j];
			}
		}
		return tmp;
	}
	Polynom operator+(Polynom pol) {
		int  i;
		int length = pol.power() > power() ? pol.power() : power();
		Polynom tmp(length);
		for (i = 0; i <= power(); i++) {
			tmp[i] += a[i];
		}
		for (i = 0; i <= pol.power(); i++) {
			tmp[i] += pol[i];
		}
		return tmp;
	}
};
Polynom operator*(Polynom pol, double r) {
	Polynom tmp(pol.power());
	for (int k = 0; k <= pol.power(); k++) {
		tmp[k] = pol[k] * r;
	}
	return tmp;
}
Polynom operator*(double r, Polynom pol) {
	return pol * r;
}
Polynom operator-(Polynom x, Polynom y) {
	return x + (-1) * y;
}
Polynom Diff(Polynom pol) {
	Polynom tmp(pol.power() - 1);
	for (int k = 0; k <= tmp.power(); k++) {
		tmp[k] = pol[k + 1] * (k + 1);
	}
	return tmp;
}
int main() {
	system("chcp 1251>nul");
	double A[] = { 1,2,-1,1 };
	double B[] = { -1,3,0,2,-1,1 };
	double x = 2;
	Polynom res;
	Polynom P(A, 3);
	cout << "Полином P:\t";
	P.getAll();
	cout << "Значение P(" << x << ") = ";
	cout << P(x) << endl;
	res = Diff(P);
	cout << "Полином P':\t";
	res.getAll();
	cout << "Значение P'(" << x << ") = ";
	cout << res(x) << endl;
	Polynom Q(B, 5);
	cout << "Полином Q:\t";
	Q.getAll();
	cout << "Значение Q(" << x << ") = ";
	cout << Q(x) << endl;
	res = P * Q;
	cout << "Полином P*Q:\t";
	res.getAll();
	cout << "Значение (P*Q)(" << x << ") = ";
	cout << res(x) << endl;
	res = P + Q;
	cout << "Полином P+Q:\t";
	res.getAll();
	cout << "Значение (P+Q)(" << x << ") = ";
	cout << res(x) << endl;
	res = Q - P;
	cout << "Полином Q-P:\t";
	res.getAll();
	cout << "Значение (Q-P)(" << x << ") = ";
	cout << res(x) << endl;
	system("pause>nul");
	return 0;
}

//8.6

int main() {
	system("chcp 1251>nul");
	srand(2);
	int n;
	cout << "Количество символов: ";
	cin >> n;
	vector<char> symbs(n);
	cout << "|";
	for (int k = 0; k < symbs.size(); k++) {
		symbs[k] = 'A' + rand() % (n + 5);
		cout << " " << symbs[k] << " |";
	}
	cout << endl;
	system("pause>nul");
	return 0;
}

//8.7

int main() {
	system("chcp 1251>nul");
	srand(2);
	int n;
	cout << "Количество символов: ";
	cin >> n;
	vector<char> symbs(n);
	cout << "|";
	for (int k = 0; k < symbs.size(); k++) {
		symbs[k] = 'A' + rand() % (n + 5);
		cout << " " << symbs[k] << " |";
	}
	cout << endl;
	system("pause>nul");
	return 0;
}

//8.8

int main() {
	system("chcp 1251>nul");
	srand(2);
	int n;
	cout << "Количество символов: ";
	cin >> n;
	vector<char> symbs;
	cout << "|";
	while (symbs.size() < n){
		symbs.push_back('A' + rand() % (n + 5));
	cout << " " << symbs[symbs.size() - 1] << " |";
		}
	cout << endl;
	system("pause>nul");
	return 0;
}

//8.9

int main() {
	system("chcp 1251>nul");
	srand(2);
	int n;
	cout << "Количество символов: ";
	cin >> n;
	set<char> symbs;
	char s;
	int counter = 0;
	while (symbs.size() < n){
		s = 'A' + rand() % (n + 5);
		counter++;
		cout << s << " ";
		symbs.insert(s);
		}
	cout << "\nВсего сгенерировано " << counter << " символов\n";
	cout << "Разные символы:\n";
	set<char>::iterator p;
	p = symbs.begin();
	cout << "|";
	while (p != symbs.end()) {
		cout << " " << *p << " |";
		p++;
	}
	cout << endl;
	system("pause>nul");
	return 0;
}
//8.10

int main() {
	system("chcp 1251>nul");
	map<string, int> numbers;
	const int n = 5;
	string names[n] = { "один","два","три","четыре","пять" };
	int nms[n] = { 1,2,3,4,5 };
	for (int k = 0; k < n; k++) {
		numbers.insert(pair<string, int>(names[k], nms[k]));
	}
	numbers.insert(pair<string, int>("шесть", 6));
	numbers.erase("три");
	map<string, int>::iterator p;
	p = numbers.begin();
	while (p != numbers.end()) {
		cout << (*p).first << "\t - " << (*p).second << endl;
		p++;
	}
	cout << "Единица\t - это " << numbers["один"] << endl;
	cout << "Двойка\t - это " << numbers.at("два") << endl;
	system("pause>nul");
	return 0;
}

//8.11

int main() {
	system("chcp 1251>nul");
	int n;
	cout << "Числа Фибоначчи\n";
	cout << "Введите размер массива: ";
	cin >> n;
	try {
		vector<int> fibs(n, 1);
		cout << fibs[0] << " " << fibs[1];
		for (int k = 2; k < n; k++) {
			fibs[k] = fibs[k - 1] + fibs[k - 2];
			cout << " " << fibs[k];
		}
	}
	catch (...) {
		cout << "Произошла ошибка!";
	}
	system("pause>nul");
	return 0;
}

//8.12
mutex m;

void mythread(string name, int time, int steps) {
	for (int k = 1; k <= steps; k++) {
		this_thread::sleep_for(chrono::seconds(time));
		m.lock();
		cout << "Поток " << name << ":\tсообщение " << k << endl;
		m.unlock();
	}
}
int main() {
	system("chcp 1251>nul");
	int n;
	cout << "Запускаются потоки...\n";
	thread A(mythread, "Alpha", 4, n);
	thread B(mythread, "Bravo", 3, n);
	mythread("Main", 2, n);
	if (A.joinable()) {
		A.join();
	}
	if (B.joinable()) {
		B.join();
	}
	cout << "Выполнение программы завершено...\n";
	system("pause>nul");
	return 0;
}


//Листинг 9

//9.1

double findRoot(double (*f)(double), double x0, int n) {
	double x = x0;
	for (int k = 1; k <= n; k++) {
		x = f(x);
	}
	return x;
}
double f(double x) {
	return 0.5 * cos(x);
}
double g(double x) {
	return exp(-x);
}
double h(double x) {
	return (x * x + 6) / 5;
}
void test(double (*f)(double), double x0, string eq) {
	int n = 100;
	double z;
	cout << "Решение уравнения " << eq << ":\t";
	z = findRoot(f, x0, n);
	cout << z << endl;
	cout << "Проверка найденного решения:\t";
	cout << z << " = " << f(z) << endl;
	for (int k = 1; k <= 50; k++) {
		cout << "-";
	}
	cout << endl;
}
int main() {
	system("chcp 1251>nul");
	test(f, 0, "x=0.5cos(x)");
	test(g, 0, "x=exp(-x)");
	test(h, 1, "x=(x*x+6)/5");
	system("pause>nul");
	return 0;
}

//листинг 9.2

double findRoot(double (*f)(double), double a, double b, double dx) {
	double x = (a + b) / 2;
	while ((b - a) / 2 > dx) {
		if (f(a) == 0){
			return a;
		}
		if (f(b) == 0){
			return b;
		}
		if (f(x) == 0) {
			return x;
		}
		if (f(a) * f(x) > 0) {
			a = x;
		}
		else {
			b = x;
		}
		x = (a + b) / 2;
	}
	return x;
}
double f(double x) {
	return 0.5 * cos(x) - x;
}
double g(double x) {
	return exp(-x) - x;
}
double h(double x) {
	return x * x - 5 * x + 6;
}
void test(double (*f)(double), double a, double b, string eq) {
	try {
		if (f(a) * f(b) > 0) {
			throw "Указан неверный диапазон!";
		}
		double dx = 0.001;
		double z;
		cout << "Решение уравнения " << eq << ":\t";
		z = findRoot(f, a, b, dx);
		cout << z << endl;
		cout << "Проверка найденного решения:\t";
		cout << f(z) << " = 0" << endl;
	}
	catch (char* e) {
		cout << e << endl;
	}
	for (int k = 1; k <= 50; k++) {
		cout << "-";
	}
	cout << endl;
}
int main() {
	system("chcp 1251>nul");
	test(f, 0, 1, "0.5cos(x)-x=0");
	test(g, 0, 2, "exp(-x)-x");
	test(h, 0, 5, "x*x-5*x+6=0");
	test(h, 0, 2, "x*x-5*x+6=0");
	test(h, 1, 3, "x*x-5*x+6=0");
	test(h, 2.5, 4.5, "x*x-5*x+6=0");
	test(h, 2.5, 10, "x*x-5*x+6=0");
	system("pause>nul");
	return 0;
}

//9.3

double f(double x) {
	return 2 * exp(-x) - 1;
}
	int main() {
		system("chcp 1251>nul");
		int n = 10;
		double dx = 0.00001;
		double x = 0;
		for (int k = 1; k <= n; k++) {
			x = x - f(x) / ((f(x + dx) - f(x)) / dx);
		}
		cout << "Найдено такое решение:\t" << x << endl;
		cout << "Контрольное значение:\t" << log(2) << endl;
		system("pause>nul");
		return 0;
	}

//9.4

void findA(double* a, double* x, double* y, int n) {
	double q;
	a[0] = y[0];
	for (int k = 1; k < n; k++) {
		a[k] = y[k];
		q = 1;
		for (int m = 0; m < k; m++) {
			a[k] -= a[m] * q;
			q *= (x[k] - x[m]);
		}
		a[k] /= q;
	}
}
double P(double* a, double z, double* x, int n) {
	double s = 0;
	double q;
	for (int k = 0; k < n; k++) {
		q = 1;
		for (int m = 0; m < k; m++) {
			q *= (z - x[m]);
		}
		s += a[k] * q;
	}
	return s;
}
void line(int m) {
	for (int k = 1; k <= m; k++) {
		cout << "-";
	}
	cout << endl;
}
int main() {
	system("chcp 1251>nul");
	int k, m = 20;
	const int n = 5;
	double x[n] = { 1,3,5,7,9 };
	double y[n] = { 0,2,-1,1,3 };
	double a[n];
	findA(a, x, y, n);
	line(m);
	cout << "x\t| P(x)\n";
	line(m);
	for (k = 0; k < n; k++) {
		cout << x[k] << "\t| " << P(a, x[k], x, n) << endl;
	}
	double dx = 1;
	line(m);
	cout << "x\t| P(x)\n";
	line(m);
	for (k = 0; k < n; k++) {
		cout << x[k] + dx << "\t| " << P(a, x[k] + dx, x, n) << endl;
	}
	system("pause>nul");
	return 0;
}

//листинг 9.6

double integrate(double (*f)(double), double a, double b, int m = 1000) {
	double h = (b - a) / 2 / m;
	double s = 0;
	for (int k = 1; k <= m - 1; k++) {
		s += 4 * f(a + (2 * k - 1) * h) + 2 * f(a + 2 * k * h);
	}
	s += f(a) + f(b) + 4 * f(a + (2 * m - 1) * h);
	s *= h / 3;
	return s;
}
double F1(double x) {
	return x * (1 - x);
}
double F2(double x) {
	double pi = 3.141592;
	return pi / 2 * tan(pi * x / 4);
}
double F3(double x) {
	return exp(-x) * cos(x);
}
int main() {
	system("chcp 1251>nul");
	cout << "Вычисление интегралов\n";
	cout << integrate(F1, 0, 1) << " vs." << (double)1 / 6 << endl;
	cout << integrate(F2, 0, 1) << " vs." << log(2) << endl;
	cout << integrate(F3, 0, 100, 1e5) << " vs." << 0.5 << endl;


	system("pause>nul");
	return 0;
}

double integrate(double (*f)(double), double a, double b, double Fmax) {
	double x, y;
	int m = 10000;
	double dx = (b - a) / m;
	double dy = Fmax / m;
	int count = 0;
	for (int i= 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			x = a + i * dx;
			y = j * dy;
			if (y <= f(x)) {
				count++;
			}
		}
	}
	double z = (double)count / (m + 1) / (m + 1);
	return Fmax * (b - a) * z;
}
double F1(double x) {
	return x * (1 - x);
}
double F2(double x) {
	double pi = 3.141592;
	return pi / 2 * tan(pi * x / 4);
}
int main() {
	system("chcp 1251>nul");
	cout << "Вычисление интегралов\n";
	cout << integrate(F1, 0, 1, 0.25) << " vs." << (double)1 / 6 << endl;
	cout << integrate(F2, 0, 1, 1.6) << " vs." << log(2) << endl;
	system("pause>nul");
	return 0;
}

double f(double x, double y) {
	return x * x * exp(-x) - y;
}
double dsolve(double (*f)(double, double), double x0, double y0, double x) {
	int n = 1000;
	double h = (x - x0) / n;
	double y = y0;
	for (int k = 0; k < n; k++) {
		y = y + h * f(x0 + k * h, y);
	}
	return y;
}
double Y(double x) {
	return (x * x * x / 3 + 1) * exp(-x);
}
int main() {
	system("chcp 1251>nul");
	double x[] = { 0,0.5,1,3,10 };
	cout << "Решение дифференциального уравнения:\n";
	for (int k = 0; k < 5; k++) {
		cout << dsolve(f, 0, 1, x[k]) << " vs. " << Y(x[k]) << endl;
	}
	system("pause>nul");
	return 0;
}

double f(double x, double y) {
	return x * x * exp(-x) - y;
}
double dsolve(double (*f)(double, double), double x0, double y0, double x) {
	int n = 1000;
	double p1, p2, p3, p4;
	double h = (x - x0) / n;
	double y = y0;
	for (int k = 0; k < n; k++) {
		p1 = f(x0 + k * h, y);
		p2 = f(x0 + k * h + h / 2, y + h * p1 / 2);
		p3 = f(x0 + k * h + h / 2, y + h * p2 / 2);
		p4 = f(x0 + k * h + h, y + h * p3);
		y = y + (h / 6) * (p1 + 2 * p2 + 2 * p3 + p4);
	}
	return y;
}
double Y(double x) {
	return (x * x * x / 3 + 1) * exp(-x);
}
int main() {
	system("chcp 1251>nul");
	double x[] = { 0,0.5,1,3,10 };
	cout << "Решение дифференциального уравнения:\n";
	for (int k = 0; k < 5; k++) {
		cout << dsolve(f, 0, 1, x[k]) << " vs. " << Y(x[k]) << endl;
	}
	system("pause>nul");
	return 0;
}