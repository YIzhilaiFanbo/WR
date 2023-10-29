#include<iostream> 
#include<stack>
#include<string>
using namespace std;

int Caculate(string exp) {
	stack<int>opand;
	int a, b, c, d;
	size_t i = 0;
	while (i < exp.length()) {
		char ch = exp[i];
		switch (ch) {
		case'+':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = a + b;
			opand.push(c);
			break;
		case'-':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = b-a;
			opand.push(c);
			break;
		case'*':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = a * b;
			opand.push(c);
			break;
		case'/':
			a = opand.top(); opand.pop();
			b = opand.top(); opand.pop();
			c = b / a;
			opand.push(c);
			break;
		case',':
			break;
		default:
			d = 0;
			while (ch >= '0' && ch <= '9') {
				d = 10 * d + (ch - '0');
				i++;
				ch = exp[i];
			}
			opand.push(d);
			break;
		}
		i++;
	}
	return opand.top();
}

int main() {
	freopen("in.txt","r",stdin);
	string exp;
	cin >> exp;
	cout << Caculate(exp);
	return 0;
}

