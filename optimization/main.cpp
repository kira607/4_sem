#include<iostream>
#include<cmath>
using namespace std;
struct elem {
	float a;
	float b;
};
elem multi(elem x, elem y) {
	elem rez;
	rez.a = x.a * y.a;
	rez.b = x.b * y.b;
	return rez;
}
elem my_pow(elem rez, int n) {
	rez.a = pow(rez.a, (1/ float(n)));
	rez.b = pow(rez.b, (1/ float(n)));
	return rez;
}
elem division(elem rez, elem y) {
	rez.a = rez.a/y.b;
	rez.b = rez.b / y.a;
	return rez;
}
int main() {
	cout << "Size matrix: ";
	int n;
	cin >> n;
	int k = (n * n - n) / 2;
	elem* elem1 = new elem[k];
	elem* elem2 = new elem[k];
	elem* rezult = new elem[n];
	//Начало заполнения матрицы
	for (int i = 0; i < k; i++) {
		cout << "input element with index " << i + 1 << endl;
		cout << "interval start: ";
		cin >> elem1[i].a;
		cout << "interval end: ";
		cin >> elem1[i].b;
	}
	for (int i = 0; i < k; i++) {
		elem2[i].a = 1 / elem1[i].b;
		elem2[i].b = 1 / elem1[i].a;
	}
	//Первый шаг
	int index1 = 0, index2 = 0;
	for (int i = 0; i < n; i++) {
		int n1 = n - (i + 1);
		int n2 = i;
		elem pr; pr.a = 1; pr.b = 1;
		for (int j = index1; j < n1 + index1; j++) pr = multi(pr, elem1[j]);
		index1 += n1;
		int k = 0;
		int tmp;
		while (k < n2) {
			if (k == 0) { pr = multi(pr, elem2[i - 1]); tmp = i - 1; k++; }
			else { pr = multi(pr, elem2[tmp + (n - k - 1)]); tmp += (n - k - 1); k++; }
		}
		rezult[i].a = pr.a;
		rezult[i].b = pr.b;
	}
	
	//Второй шаг
	for (int i = 0; i < n; i++) rezult[i] = my_pow(rezult[i], n);
	//Третий шаг
	elem sum; sum.a = 0; sum.b = 0;
	for (int i = 0; i < n; i++) {
		sum.a += rezult[i].a;
		sum.b += rezult[i].b;
	}
	//Четвертый шаг
	for (int i = 0; i < n; i++) rezult[i] = division(rezult[i], sum);
	//Вывод результата
	cout << endl<<"Eigenvector: "<<endl;
    for (int i = 0; i < n; i++) cout << rezult[i].a << "   " << rezult[i].b << endl;
	return 0;
}

